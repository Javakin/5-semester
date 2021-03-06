#include "Mapping.h"
#include "Image.h"
#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include "PPMLoader.h"

using namespace std;
using namespace rw::sensor;
using namespace rw::loaders;

Mapping::Mapping()
{
	map = nullptr;
	brushfireMap = nullptr;
	brushfireMapWObj = nullptr;
	brushfireMapInc = nullptr;
	pathMap = nullptr;
	voronoiMap = nullptr;
	cellDecMap = nullptr;
}

Mapping::Mapping(Image* amap)
{
	map = amap->copyFlip(0, 0);
	brushfireMap = nullptr;
	brushfireMapWObj = nullptr;
	brushfireMapInc = nullptr;
	pathMap = nullptr;
	voronoiMap = nullptr;
	cellDecMap = nullptr;
}

void Mapping::brushfire()
{
	if (map == nullptr)
		return;

	// setup
	brushfireMap = map->copyFlip(0, 0);
	vector< vector< point > > borderlines;
	int objectColour = 50;
	
	// identifying all objects 
	cout << "identifying all objects..." << endl;
	for (unsigned int x = 0; x < brushfireMap->getWidth(); x++)
	{
		for (unsigned int y = 0; y < brushfireMap->getHeight(); y++)
		{
			// for every pixel check for a black pixel and run prushfireexhaustive for a collor
			if (brushfireMap->getPixelValuei(x, y, 0) == 0)
			{
				cout << "new object detected\n";
				borderlines.push_back(brushfireExhaustive(x, y, objectColour));
				objectColour += 20; 
				if (objectColour == 254 || objectColour == 253 || objectColour == 255 || objectColour == 0)
					objectColour += 20;
				
			}
		}
	}
	
	// debugging collor edges
	/*for (vector<vector<int> > edge : borderlines)
	{
		for (vector<int> point : edge)
		{
			brushfireMap->setPixel8U(point[0], point[1], 60);
		}
	}*/
	

	// generate brushfireMap
	int semEmpty = 1;
	while (semEmpty != 0)
	{
		semEmpty = 0;
		for (unsigned int i = borderlines.size(); i > 0; i--)
		{
			// for each object brushfire one step
			borderlines[i - 1] = brushfireSingleStep(borderlines[i - 1]);

			// vector still full?
			if (borderlines[i - 1].size() != 0)
				semEmpty = 1;
		}		
	}

	// generate brushfireMapInc
	brushfireInc();

	// generate brushfireMapWObj
	brushfireMapWObj = brushfireMap->copyFlip(0, 0);
	for (int x = 0; x < brushfireMap->getWidth(); x++)
	{
		for (int y = 0; y < brushfireMap->getHeight(); y++)
		{
			if (map->getPixelValuei(x, y, 0) == 0)
			{
				brushfireMapWObj->setPixel8U(x, y, 0);
			}
		}
	}
}

vector<Cell> Mapping::cellDecomp()
{
	// precondition
	if (map == nullptr)
		return vector<Cell>();

	// setup
	std::string filename("Images/Bane4.pgm");
	std::cout << filename << std::endl;

	std::cout << "loading image..." << std::endl;
	cellDecMap = PPMLoader::load(filename);
	vector<Cell> vCells;
	vector<unsigned int> vLines;

	// finde the lines
	cout << "identifying all cells..." << endl;
	int semLine = 0;
	for (unsigned int uiY = 0; uiY < cellDecMap->getHeight() - 1; uiY++)
	{
		semLine = 0;
		for (unsigned int uiX = 0; uiX < cellDecMap->getWidth(); uiX++)
		{
			if (cellDecMap->getPixelValuei(uiX, uiY, 0) != cellDecMap->getPixelValuei(uiX, uiY + 1, 0) && semLine == 0)
			{
				semLine = 1;
				vLines.push_back(uiY);
			}
		}
	}

	// finde the cells
	point p1;
	point p2;
	Cell newCell;
	for (unsigned int uiY = 0; uiY < vLines.size(); uiY++)
	{
		for (unsigned int uiX = 0; uiX < cellDecMap->getWidth() - 1; uiX++)
		{
			if (cellDecMap->getPixelValuei(uiX, vLines[uiY] + 1, 0) != cellDecMap->getPixelValuei(uiX + 1, vLines[uiY] + 1, 0) && cellDecMap->getPixelValuei(uiX, vLines[uiY] + 1, 0) == 0)
			{
				// found a new cell
				p1.xVal = uiX + 1;
				p1.yVal = vLines[uiY] + 1;

				// finde p2				cellDecMap->setPixel8U(uiX + 1, vLines[uiY] + 1, 125);
				for (unsigned int uiXEnd = uiX + 1; uiXEnd < cellDecMap->getWidth() - 1; uiXEnd++)
				{
					if (cellDecMap->getPixelValuei(uiXEnd, vLines[uiY + 1], 0) != cellDecMap->getPixelValuei(uiXEnd + 1, vLines[uiY + 1], 0) && cellDecMap->getPixelValuei(uiXEnd, vLines[uiY + 1], 0) == 255)
					{
						p2.xVal = uiXEnd;
						p2.yVal = vLines[uiY + 1];
						newCell.p1 = p1;
						newCell.p2 = p2;
						vCells.push_back(newCell);
						uiXEnd = UINT_MAX - 1;
					}
				}
			}
		}
	}
	// display cells for debugging
	unsigned int aColor = 50;
	for (Cell c : vCells)
	{
		for (unsigned int x = c.p1.xVal; x <= c.p2.xVal; x++)
		{
			for (unsigned int y = c.p1.yVal; y <= c.p2.yVal; y++)
			{
				cellDecMap->setPixel8U(x, y, aColor);
			}
		}
		aColor = (aColor + 60) % 250;
		if (aColor < 80)
			aColor += 50;
		
	}
	 
	// terminate and return
	return vCells;
}

vector<point> Mapping::dijkstra(point startPoint, point stopPoint)
{
	// setup
	if (map == nullptr)
	{
		cout << "map is nullpointer\n";
		return vector<point>();
	}


	// setup
	//pathMap = map->copyFlip(0, 0);
	vector<point> fullPointGraph(diagramPoints);
	vector<edge> dijkstraPath;
	point currentPoint = startPoint;
	point tempPoint;
	edge currentEdge;

	int relIderat[8][2] = { { 0, 1 },{ 0, -1 },{ 1, 0 },{ -1, 0 },{ 1, 1 },{ 1, -1 },{ -1,1 },{ -1,-1 } };
	deque<point> livingPoints = { currentPoint };
	
	vector<point> temp1(pointToParth(startPoint));
	vector<point> temp2(pointToParth(stopPoint));
	

	// merge vectors
	for (point p : temp1)
		fullPointGraph.push_back(p);
	for (point p : temp2)
		fullPointGraph.push_back(p);
	

	// remove starting point from list
	if (!pointRemove(startPoint, fullPointGraph))
	{
		cout << "startpoint was not in list\n";
		return vector<point>();
	}

	// begin dijgstra algorithm
	int semDij = 1;
	while(livingPoints.size() != 0 && semDij == 1)
	{
		// phase 1 finde and pop the smalest living point
		currentPoint = livingPoints.front();
		livingPoints.pop_front();

		// phase 2 search the fullPointGraph for points neightbours
		for (unsigned int i = 0; i < 8; i++)
		{
			tempPoint.xVal = currentPoint.xVal + relIderat[i][0];
			tempPoint.yVal = currentPoint.yVal + relIderat[i][1];

			if (pointRemove(tempPoint, fullPointGraph))
			{
				// for every point found add edge to dijkstraPath and add newpoint to the land of the living
				currentEdge.xVal1 = currentPoint.xVal;
				currentEdge.yVal1 = currentPoint.yVal;
				currentEdge.xVal2 = tempPoint.xVal;
				currentEdge.yVal2 = tempPoint.yVal;
				dijkstraPath.push_back(currentEdge);
				livingPoints.push_back(tempPoint);

				// if new point is the goal, add edge and break
				if ((tempPoint.xVal == stopPoint.xVal) && (tempPoint.yVal == stopPoint.yVal))
				{
					cout << "goal detected process terminates\n";
					semDij = 0;
				}
			}
		}		
	}


	// extract the shortest path
	currentPoint = stopPoint;
	vector<point> shortestPath = {stopPoint};

	while (!((currentPoint.xVal == startPoint.xVal) && (currentPoint.yVal == startPoint.yVal)))
	{
		//dijkstraPath
		for (edge e : dijkstraPath)
		{
			//find the edge ending with the current point
			if ((e.xVal2 == currentPoint.xVal) && (e.yVal2 == currentPoint.yVal))
			{
				//I found it append the point to path
				currentPoint.xVal = e.xVal1;
				currentPoint.yVal = e.yVal1;
				shortestPath.push_back(currentPoint);
			}
		}
	}

	/*cout << "done and ready to paint\n";
	for (point p : shortestPath)
	{
		pathMap->setPixel8U(p.xVal, p.yVal, 60);
	}*/

	// invert vector for ease
	vector<point> pathInv;
	for (int i = shortestPath.size() - 1; i >= 0; i--)
		pathInv.push_back(shortestPath[(unsigned int)i]);

	return pathInv;
}

Image* Mapping::getBrushfireMap()
{
	return brushfireMap;
}

Image* Mapping::getBrushfireMapWObj()
{
	return brushfireMapWObj;
}

Image* Mapping::getBrushfireMapInc()
{
	return brushfireMapInc;
}

Image* Mapping::getPathMap()
{
	return pathMap;
}

vector<point> Mapping::pointToParth(point aPoint)
{
	// given a point find path to the voronoid diagram
	if (brushfireMapInc == nullptr)
		return vector<point>();
	

	// setup
	int relIderat[8][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1,1}, {-1,-1}};
	int semNewPoint = 1;
	vector<point> pointPath = { aPoint };
	point currentPoint = aPoint;
	
	
	// find the next point
	while (semNewPoint != 0)
	{
		semNewPoint = 0;
		for (int i = 0; i < 8; i++)
		{
			int currVal = brushfireMapInc->getPixelValuei(currentPoint.xVal, currentPoint.yVal, 0);
			int newVal = brushfireMapInc->getPixelValuei(currentPoint.xVal + relIderat[i][0], currentPoint.yVal + relIderat[i][1], 0);

			if (newVal > currVal)
			{
				// add new point
				currentPoint.xVal += relIderat[i][0];
				currentPoint.yVal += relIderat[i][1];
				pointPath.push_back(currentPoint);
				semNewPoint++;
				i = 10;		// break for loop
			}
		}
	}
	
	// add the next point

	return pointPath;
}

Image* Mapping::getVoronoiMap()
{
	return voronoiMap;
}

Image * Mapping::getCellDecMap()
{
	return cellDecMap;
}

void Mapping::Voronoi()
{
	// precondition
	if (map == nullptr)
		return;

	// setup
	voronoiMap = brushfireMap->copyFlip(0, 0);

	int rows = voronoiMap->getHeight();
	int cols = voronoiMap->getWidth();
	int val = 0;
	
	vector<vector<int>> testvec(rows, vector<int>(cols, val));
	int channel = 0; // allways 0 on grayscale image


	// Iterate through the the picture
	for (unsigned int x = 0; x < voronoiMap->getWidth(); ++x) {
		for (unsigned int y = 0; y < voronoiMap->getHeight(); ++y) {
			int val = voronoiMap->getPixelValuei(x, y, channel);

			testvec[x][y] = val; // Put the value of the pixel into the vector
								 // Check the surrounding points value. If they have the color value code "254" the do nothing else change current points value to the color code "254"
			if (x < voronoiMap->getWidth() - 1 && x > 1 && y < voronoiMap->getHeight() - 1 && y > 1)
			{
				if (testvec[x][y] != testvec[x - 1][y] && testvec[x][y] != testvec[x + 1][y] && testvec[x - 1][y] != 254 && testvec[x + 1][y] != 254 && testvec[x - 1][y] != 253 && testvec[x + 1][y] != 253 && testvec[x][y] != 253)
				{
					testvec[x][y] = 254;
				}
				else if (testvec[x][y] != testvec[x][y - 1] && testvec[x][y] != testvec[x][y + 1] && testvec[x][y - 1] != 254 && testvec[x][y + 1] != 254 && testvec[x][y - 1] != 253 && testvec[x][y + 1] != 253 && testvec[x][y] != 253)
				{
					testvec[x][y] = 254;
				}
			}
		}
	}

	// Color all the pixels on the position that have the value 254
	for (unsigned int x = 0; x < voronoiMap->getWidth(); ++x) {
		for (unsigned int y = 0; y < voronoiMap->getHeight(); ++y) {
			if (testvec[x][y] == 254) {
				voronoiMap->setPixel8U(x, y, 0);
			}
		}
	}

	// Take the position of all the pixels with the color code and put them into a vector of pairs
	// Put the pairs into the vector
	point apair;
	for (int i = 0; i < voronoiMap->getWidth(); i++) {
		for (int j = 0; j < voronoiMap->getWidth(); j++) {
			if (testvec[i][j] == 254)
			{
				
				apair.xVal = i;
				apair.yVal = j;
				diagramPoints.push_back(apair);
			}
		}
	}

	//for debugging
	/*for (vector<point>::iterator it2 = diagramPoints.begin(); it2 != diagramPoints.end(); ++it2) {
		apair = *it2;
		cout << "(" << apair.xVal << "," << apair.yVal << ") ; ";
	}
	cout << '\n';

	//std::cout << "saving image Voronoi map" << std::endl;
	// save image
	//voronoiMap->saveAsPGM("testout.pgm");*/
}

Mapping::~Mapping()
{
	delete map;
	delete brushfireMap;
	delete brushfireMapWObj;
	delete brushfireMapInc;
	delete pathMap;
	delete voronoiMap;
	delete cellDecMap;
	
}

vector<point> Mapping::brushfireExhaustive(int xPos, int yPos, int colour)
{
	// setup
	int relIderat[4][2] = { { 0,1 },{ 0,-1 },{ 1,0 },{ -1, 0 } };
	point current_point = {xPos, yPos};
	vector<point> pointStack = { current_point };
	vector<point> borderLinePoints;
	brushfireMap->setPixel8U(xPos, yPos, colour);
	

	// do exaustive brushfire
	while (pointStack.size() != 0)
	{
		// pop new pixel
		current_point = pointStack.back();
		pointStack.pop_back();

		//check for childes
		for (int i = 0; i < 4; i++)
		{
			int semBorder = 0;

			if (validPoint(current_point.xVal + relIderat[i][0], current_point.yVal + relIderat[i][1]))
			{
				int pixVal = brushfireMap->getPixelValuei(current_point.xVal + relIderat[i][0], current_point.yVal + relIderat[i][1], 0);
				//case one: pixel is borderLine point
				if (semBorder == 0 && pixVal == 255)
				{
					// add borderline point
					borderLinePoints.push_back(current_point);
					semBorder++;
				}
				// case two: pixel is a new black pixel
				if (pixVal == 0)
				{
					// colour point and add to the pointstack
					point pointHolder = { current_point.xVal + relIderat[i][0], current_point.yVal + relIderat[i][1] };
					brushfireMap->setPixel8U(pointHolder.xVal, pointHolder.yVal, colour);
					pointStack.push_back(pointHolder);
				}
			}
		}
	}

	return borderLinePoints;
}

vector<point> Mapping::brushfireSingleStep(vector<point> anEdge)
{
	// precondition
	if (anEdge.size() == 0)
		return vector<point>();

	// setup
	int relIderat[4][2] = { { 0,1 },{ 0,-1 },{ 1,0 },{ -1, 0 } };
	int colour = brushfireMap->getPixelValuei(anEdge[0].xVal, anEdge[0].yVal, 0);
	point current_point;
	vector<point> borderLinePoints;


	// do exaustive brushfire
	while (anEdge.size() != 0)
	{
		// pop new pixel
		current_point = anEdge.back();
		anEdge.pop_back();

		//check for childes
		for (int i = 0; i < 4; i++)
		{
			if (validPoint(current_point.xVal + relIderat[i][0], current_point.yVal + relIderat[i][1]))
			{
				int pixVal = brushfireMap->getPixelValuei(current_point.xVal + relIderat[i][0], current_point.yVal + relIderat[i][1], 0);

				// pixel is a new white pixel
				if (pixVal == 255)
				{
					// colour point and add to the borderLineStack
					point pointHolder = { current_point.xVal + relIderat[i][0], current_point.yVal + relIderat[i][1] };
					brushfireMap->setPixel8U(pointHolder.xVal, pointHolder.yVal, colour);
					borderLinePoints.push_back(pointHolder);
				}
			}
		}
	}

	return borderLinePoints;
}

bool Mapping::pointRemove(point aPoint, vector<point>& pointList)
{
	bool semRem = 0;
	for (unsigned int i = 0; i < pointList.size(); i++)
	{
		if ((aPoint.xVal == pointList[i].xVal) && (aPoint.yVal == pointList[i].yVal))
		{
			pointList.erase(pointList.begin() + i);
			semRem = 1;
		}
	}
	if (semRem == 1)
		pointRemove(aPoint, pointList);

	return semRem;
}

void Mapping::brushfireInc()
{
	
	brushfireMapInc = map->copyFlip(0, 0);

	int relIderat[4][2] = { { 0,1 },{ 0,-1 },{ 1,0 },{ -1, 0 } };
	int semWhite = 0;

	for (int collor = 1; collor < 255; collor++)
	{
		semWhite = 0;
		for (int x = 0; x < brushfireMap->getWidth(); x++)
		{
			for (int y = 0; y < brushfireMap->getHeight(); y++)
			{
				// for every pixel check for a black pixel and run prushfireexhaustive for a collor
				if (brushfireMapInc->getPixelValuei(x, y, 0) == 255)
				{
					semWhite = 1;
					for (int i = 0; i < 4; i++)
					{
						if (brushfireMapInc->getPixelValuei(x + relIderat[i][0], y + relIderat[i][1], 0) == collor - 1)
						{
							brushfireMapInc->setPixel8U(x, y, collor);
						}
					}
				}
			}
		}
		if (semWhite == 0)
		{
			break;
		}
	}
}

bool Mapping::validPoint(int xPos, int yPos)
{
	//out of bounce check xPos
	if (xPos < 0 || xPos >= brushfireMap->getWidth())
	{
		//cout << "error: wrong xpos on the map\n";
		return false;
	} 
	// oute of bounce check yPos
	if (yPos < 0 || yPos >= brushfireMap->getHeight())
	{
		//cout << "error: wrong ypos on the map\n";
		return false;
	}

	// nothing is wrong return true
	return true;
}