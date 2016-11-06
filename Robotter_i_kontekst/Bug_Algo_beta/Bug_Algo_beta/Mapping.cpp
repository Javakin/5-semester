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
}

Mapping::Mapping(Image* amap)
{
	map = amap;
	brushfireMap = nullptr;
}

void Mapping::Brushfire()
{
	if (map == nullptr)
		return;

	// setup
	brushfireMap = map;
	vector< vector< vector<int> > > borderlines;
	int channel = 0; // allways 0 on grayscale image

	
	// identifying all objects 
	cout << "identifying all objects..." << endl;
	for (int x = 0; x < brushfireMap->getWidth(); x++)
	{
		for (int y = 0; y < brushfireMap->getHeight(); y++)
		{
			// for every pixel check for a black pixel and run prushfireexhaustive for a collor
			if (brushfireMap->getPixelValuei(x, y, channel) == 0)
			{
				cout << "new object detected\n";
				borderlines.push_back(brushfireExhaustive(x, y, 125));
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
		
		cout << "brushed one step\n";
		
	}
}

Image* Mapping::getBrushfireMap()
{
	return brushfireMap;
}

Mapping::~Mapping()
{
}

vector<vector<int> > Mapping::brushfireExhaustive(int xPos, int yPos, int colour)
{
	// setup
	int relIderat[4][2] = { { 0,1 },{ 0,-1 },{ 1,0 },{ -1, 0 } };
	int channel = 0;				// allways 0 on grayscale image
	vector<int> current_point = {xPos, yPos};
	vector<vector<int> > pointStack = { current_point };
	vector<vector<int> > borderLinePoints;
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

			if (validPoint(current_point[0] + relIderat[i][0], current_point[1] + relIderat[i][1]))
			{
				int pixVal = brushfireMap->getPixelValuei(current_point[0] + relIderat[i][0], current_point[1] + relIderat[i][1], channel);
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
					vector<int> pointHolder = { current_point[0] + relIderat[i][0], current_point[1] + relIderat[i][1] };
					brushfireMap->setPixel8U(pointHolder[0], pointHolder[1], colour);
					pointStack.push_back(pointHolder);
				}
			}
		}
	}

	return borderLinePoints;
}

vector<vector<int>> Mapping::brushfireSingleStep(vector<vector<int>> anEdge)
{
	// precondition
	if (anEdge.size() == 0)
		return vector<vector<int> >();

	// setup
	int relIderat[4][2] = { { 0,1 },{ 0,-1 },{ 1,0 },{ -1, 0 } };
	int channel = 0;				// allways 0 on grayscale image
	int colour = brushfireMap->getPixelValuei(anEdge[0][0], anEdge[0][1], channel);
	vector<int> current_point;
	vector<vector<int> > borderLinePoints;


	// do exaustive brushfire
	while (anEdge.size() != 0)
	{
		// pop new pixel
		current_point = anEdge.back();
		anEdge.pop_back();

		//check for childes
		for (int i = 0; i < 4; i++)
		{
			if (validPoint(current_point[0] + relIderat[i][0], current_point[1] + relIderat[i][1]))
			{
				int pixVal = brushfireMap->getPixelValuei(current_point[0] + relIderat[i][0], current_point[1] + relIderat[i][1], channel);

				// pixel is a new white pixel
				if (pixVal == 255)
				{
					// colour point and add to the borderLineStack
					vector<int> pointHolder = { current_point[0] + relIderat[i][0], current_point[1] + relIderat[i][1] };
					brushfireMap->setPixel8U(pointHolder[0], pointHolder[1], colour);
					borderLinePoints.push_back(pointHolder);
				}
			}
		}
	}

	return borderLinePoints;
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


