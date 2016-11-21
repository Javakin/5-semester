// opg7_38.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <random>
#include "structs.h"
#include "lineDetect.h"


using namespace std;

int main()
{
	// for detection of memory leaks 
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	// make a list of randum points
	vector<point> points = { point{1,1}, point{ 2,2 },point{ 3,3 },point{ 4,4 }};
	random_device rd;							// obtain a random number from hardware
	mt19937 eng(rd());							// seed the generator
	uniform_int_distribution<> distr(0, 10);	// define the range

	//for (int i = 0; i < 10; ++i)
		//points.push_back(point{ distr(eng), distr(eng) });

	// finde all lines with more then 4 points
	vector<edge> solution;
	lineDetect opg7_38;

	solution = opg7_38.getLines(points);



	// program terminates
	system("pause");
    return 0;
}

