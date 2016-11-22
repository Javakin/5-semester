// opg7_38.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <random>
#include "structs.h"
#include "lineDetect.h"

#include "Image.h"
#include "PPMLoader.h"
#include <string>

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;
using namespace rw::loaders;
using namespace rw::sensor;


int main()
{
	// for detection of memory leaks 
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);


	// loading image to debug
	cout << "Loading image \n";
	string filename = "PointMap.pgm";
	Image* img = PPMLoader::load(filename);
	

	// make a list of randum 
	vector<point> points;
	random_device rd;							// obtain a random number from hardware
	mt19937 eng(rd());							// seed the generator
	uniform_int_distribution<> distr(0, 180);	// define the range

	
	for (int i = 0; i < 200; ++i)
		points.push_back(point{ distr(eng), distr(eng) });

	// finde all lines with more then 4 points
	vector<edge> solution;
	lineDetect opg7_38;

	solution = opg7_38.getLines(points);
	
	// plot solution
	for (edge anEdge : solution)
	{
		// print the edge
		double x = anEdge.Lpoints[0].xVal;
		double y = anEdge.Lpoints[0].yVal;

		while (y < 200 && 0 <= y && x < 200 && x >= 0)
		{
			// inc part
			x += cos(anEdge.angle);
			y += sin(anEdge.angle);
			if (y < 200 && 0 <= y && x < 200 && x >= 0)
				img->setPixel8U((int)x, (int)y, 0);
		}
		// print the edge
		x = anEdge.Lpoints[0].xVal;
		y = anEdge.Lpoints[0].yVal;

		while (y < 200 && 0 <= y && x < 200 && x >= 0)
		{
			// inc part
			x -= cos(anEdge.angle);
			y -= sin(anEdge.angle);
			if (y < 200 && 0 <= y && x < 200 && x >= 0)
				img->setPixel8U((int)x, (int)y, 0);
		}

		// print all the points 
		for (point aPoint : anEdge.Lpoints)
		{
			img->setPixel8U(aPoint.xVal,     aPoint.yVal, 125    );
			img->setPixel8U(aPoint.xVal + 1, aPoint.yVal + 1, 0);
			img->setPixel8U(aPoint.xVal + 1, aPoint.yVal - 1, 0);
			img->setPixel8U(aPoint.xVal - 1, aPoint.yVal + 1, 0);
			img->setPixel8U(aPoint.xVal - 1, aPoint.yVal - 1, 0);
		}
	}
	
	// program terminates
	img->saveAsPGM("outPut.pgm");
	delete img;
	//system("pause");

    return 0;
}

