#include "Mapping.h"
#include "Image.h"
#include <iostream>
#include <vector>
#include <string>
#include <deque>

using namespace std;
using namespace rw::sensor;


Mapping::Mapping()
{
	map = nullptr;
	brushfireMap = nullptr;
	brushfireMapWObj = nullptr;
	brushfireMapInc = nullptr;
	pathMap = nullptr;
	voronoiMap = nullptr;
}

Mapping::Mapping(Image* amap)
{
	map = amap->copyFlip(0, 0);
	brushfireMap = nullptr;
	brushfireMapWObj = nullptr;

	brushfireMapInc = nullptr;
	pathMap = nullptr;

	voronoiMap = nullptr;

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
	for (int x = 0; x < brushfireMap->getWidth(); x++)
	{
		for (int y = 0; y < brushfireMap->getHeight(); y++)
		{
			// for every pixel check for a black pixel and run prushfireexhaustive for a collor
			if (brushfireMap->getPixelValuei(x, y, 0) == 0)
			{
				cout << "new object detected\n";
				borderlines.push_back(brushfireExhaustive(x, y, objectColour));
				objectColour += 20; /* to do: lav en ordenlig funktion */
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

void Mapping::dijkstra(point startPoint, point stopPoint)
{
	// setup
	pathMap = map->copyFlip(0, 0);

	vector<point> voronoidPoints;
	vector<point> graph(voronoidPoints);


	vector<point> a(pointToParth(startPoint));
	vector<point> b(pointToParth(stopPoint));

	for (point p : a)
	{
		pathMap->setPixel8U(p.xVal, p.yVal, 60);
	}

	for (point p : b)
	{
		pathMap->setPixel8U(p.xVal, p.yVal, 60);
	}
		
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
	vector<point> pointPath;
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
				pointPath.push_back(currentPoint);
				currentPoint.xVal += relIderat[i][0];
				currentPoint.yVal += relIderat[i][1];
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

void Mapping::Voronoi()
{
	if (map == nullptr)
		return;
	// Get the map
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
				if (testvec[x][y] != testvec[x - 1][y] && testvec[x][y] != testvec[x + 1][y] && testvec[x - 1][y] != 254 && testvec[x + 1][y] != 254)
				{
					testvec[x][y] = 254;
				}
				else if (testvec[x][y] != testvec[x][y - 1] && testvec[x][y] != testvec[x][y + 1] && testvec[x][y - 1] != 254 && testvec[x][y + 1] != 254)
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
	// Setup the containers
	point apair;
	//vector<pair<int, int> > points;

	// Put the pairs into the vector
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
	cout << '\n';*/

	//std::cout << "saving image Voronoi map" << std::endl;
	// save image
	//voronoiMap->saveAsPGM("testout.pgm");
}

Mapping::~Mapping()
{
	delete map;
	delete brushfireMap;
	delete brushfireMapWObj;

	delete brushfireMapInc;
	delete pathMap;

	delete voronoiMap;

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