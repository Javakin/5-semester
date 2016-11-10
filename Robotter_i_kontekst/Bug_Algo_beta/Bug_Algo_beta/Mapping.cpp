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
}

Mapping::Mapping(Image* amap)
{
	map = amap->copyFlip(0, 0);
	brushfireMap = nullptr;
	brushfireMapWObj = nullptr;
	brushfireMapInc = nullptr;
}

void Mapping::Brushfire()
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
	
	// generate inc map
	brushfireInc();

	// begin brushfiring
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
	
	// update brushfireMapWObj
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

Image* Mapping::getBrushfireMap()
{
	return brushfireMap;
}

Image * Mapping::getBrushfireMapWObj()
{
	return brushfireMapWObj;
}

Image * Mapping::getBrushfireMapInc()
{
	return brushfireMapInc;
}


vector<point> Mapping::pointToParth(point apoint, vector<point> parth)
{
	// given a point find path to the voronoid diagram
	if (brushfireMapInc == nullptr)
		return vector<point>();
	
	// setup
	int relIderat[4][2] = { { 0,1 },{ 0,-1 },{ 1,0 },{ -1, 0 } };
	vector<point> pointPath;
	vector<point> currentPoint(point);

	/*
	// find the next point
	for (int i = 0; i < 4; i++)
	{
		int currVal = brushfireMapInc->getPixelValuei(currentPoint[0], currentPoint[0][1], 0);
		int newVal = brushfireMapInc->getPixelValuei(currentPoint[0][0] + relIderat[i][0], currentPoint[0][1] + relIderat[i][1], 0);

		if (newVal < currVal)
		{
			// add new point
			pointPath.push_back(currentPoint[0]);
			currentPoint[0] = std::make_pair(currentPoint[0][0] + relIderat[i][0], currentPoint[0][1] + relIderat[i][1]);
			i = 10;		// break for loop
		}
	}
	
	// add the next point*/

	return pointPath;
}


Mapping::~Mapping()
{
	delete map;
	delete brushfireMap;
	delete brushfireMapWObj;
	delete brushfireMapInc;
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


