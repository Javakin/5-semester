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
	// loading image to debug
	cout << "Loading image \n";
	string filename = "PointMap.pgm";
	Image* img = PPMLoader::load(filename);


	// for detection of memory leaks 
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	// make a list of randum points
	vector<point> points = { point{1,1}, point{ 2,2 },point{ 3,3 },point{ 4,4 },point{ 0,17 } };
	random_device rd;							// obtain a random number from hardware
	mt19937 eng(rd());							// seed the generator
	uniform_int_distribution<> distr(0, 18);	// define the range

	for (int i = 0; i < 0; ++i)
		points.push_back(point{ distr(eng), distr(eng) });

	// finde all lines with more then 4 points
	vector<edge> solution;
	lineDetect opg7_38;

	solution = opg7_38.getLines(points);

	// plor solution
	for (edge anEdge : solution)
	{
		// print the edge
		for (unsigned int x = 0; x < img->getWidth(); x++)
		{

		}

		// print all the points 
		for (point aPoint : anEdge.Lpoints)
		{
			img->setPixel8U(aPoint.xVal,     aPoint.yVal, 0    );
			//img->setPixel8U(aPoint.xVal + 1, aPoint.yVal + 1, 0);
			//img->setPixel8U(aPoint.xVal + 1, aPoint.yVal - 1, 0);
			//img->setPixel8U(aPoint.xVal - 1, aPoint.yVal + 1, 0);
			//img->setPixel8U(aPoint.xVal - 1, aPoint.yVal - 1, 0);
		}
	}

	// program terminates
	img->saveAsPGM("outPut.pgm");
	//system("pause");
    return 0;
}

