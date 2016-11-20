// opg7_38.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <random>
#include "structs.cpp"
#include "lineDetect.h"



int main()
{
	// for detection of memory leaks 
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	// make a list of randum points
	std::vector<point> points;
	std::random_device rd;							// obtain a random number from hardware
	std::mt19937 eng(rd());							// seed the generator
	std::uniform_int_distribution<> distr(0, 99);	// define the range

	for (int i = 0; i < 10; ++i)
		points.push_back(point{ distr(eng), distr(eng) });

	// finde all lines with more then 4 points
	std::vector<edge> solution;
	lineDetect opg7_38;

	solution = opg7_38.getLines(points);

	// program terminates
	system("pause");
    return 0;
}

