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
	voronoiMap = nullptr;
}

Mapping::Mapping(Image* amap)
{
	map = amap->copyFlip(0, 0);
	brushfireMap = nullptr;
	brushfireMapWObj = nullptr;
	voronoiMap = nullptr;
}

void Mapping::Brushfire()
{
	if (map == nullptr)
		return;

	// setup
	brushfireMap = map->copyFlip(0, 0);
	vector< vector< vector<int> > > borderlines;
	int channel = 0; // allways 0 on grayscale image
	int objectColour = 50;

	
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
			if (map->getPixelValuei(x, y, channel) == 0)
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

Image * Mapping::getVoronoiMap()
{
	return voronoiMap;
}

void Mapping::Voronoi()
{
	if (map == nullptr)
		return;
	// Get the map
	voronoiMap = map->copyFlip(0, 0);

	int rows = voronoiMap->getHeight();
	int cols = voronoiMap->getWidth();
	int val = 0;
	int x = 0;
	int y = 0;

	vector<vector<int>> testvec(rows, vector<int>(cols, val));
	int channel = 0; // allways 0 on grayscale image


	// Iterate through the the picture
	for (unsigned int x = 0; x < voronoiMap->getWidth(); ++x) {
		for (unsigned int y = 0; y < voronoiMap->getHeight(); ++y) {
			int val = voronoiMap->getPixelValuei(x, y, channel);

			testvec[x][y] = val; // Put the value of the pixel into the vector
		
			if (x < voronoiMap->getWidth() - 1 && x > 1 && y < voronoiMap->getHeight() - 1 && y > 1)
			{
				if (testvec[x][y] != testvec[x - 1][y] && testvec[x][y] != testvec[x + 1][y]/* && testvec[x - 1][y] != 254 && testvec[x + 1][y] != 254*/)
				{
					testvec[x][y] = 254;
				}
				else if (testvec[x][y] != testvec[x][y - 1] && testvec[x][y] != testvec[x][y + 1]/* && testvec[x][y - 1] != 254 && testvec[x][y + 1] != 254*/)
				{
					testvec[x][y] = 254;
				}
			}
		}
	}
								 
								 // Check the values of the sourounding positions. If the positions to the side or top is the colored value "254" then don't change the value else do.
	//		if (x < voronoiMap->getWidth() - 1 && x > 1 && y < voronoiMap->getHeight() - 1 && y > 1)
	//		{
	//			if (testvec[x][y] != testvec[x - 1][y] && testvec[x][y] != testvec[x + 1][y] && testvec[x - 1][y] != 254 && testvec[x + 1][y] != 254)
	//			{
	//				testvec[x][y] = 254;
	//			}
	//			else if (testvec[x][y] != testvec[x][y - 1] && testvec[x][y] != testvec[x][y + 1] && testvec[x][y - 1] != 254 && testvec[x][y + 1] != 254)
	//			{
	//				testvec[x][y] = 254;
	//			}
	//		}
	//	}
	//}
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
	pair<int, int> apair;
	vector<pair<int, int> > v_temp;
	vector< vector<pair<int, int> > > pair2dvector;

	// Put the pairs into the vector
	for (int i = 0; i < voronoiMap->getWidth(); i++) {
		for (int j = 0; j < voronoiMap->getWidth(); j++) {
			if (testvec[i][j] == 254)
			{
				apair.first = i;
				apair.second = j;
				v_temp.push_back(apair);
			}
		}
		pair2dvector.push_back(v_temp);
		v_temp.clear();
	}

	// Iterate through the vector and print the pairs out
	for (vector< vector<pair<int, int> > >::iterator it = pair2dvector.begin(); it != pair2dvector.end(); ++it) {
		v_temp = *it;
		for (vector<pair<int, int> >::iterator it2 = v_temp.begin(); it2 != v_temp.end(); ++it2) {
			apair = *it2;
			cout << "(" << apair.first << "," << apair.second << ") ; ";
		}
		cout << '\n';
	}
		std::cout << "saving image Voronoi map" << std::endl;
		// save image
		voronoiMap->saveAsPGM("testout.pgm");
}
Mapping::~Mapping()
{
	delete map;
	delete brushfireMap;
	delete brushfireMapWObj;
	delete voronoiMap;
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


