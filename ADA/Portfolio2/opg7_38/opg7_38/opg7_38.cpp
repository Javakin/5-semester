// opg7_38.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <random>
#include "structs.h"
#include "lineDetect.h"
#include "Sort.h"
#include <string>
#include <chrono>

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;



int main()
{
	// for detection of memory leaks 
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	

	// make a list of randum 
	random_device rd;							// obtain a random number from hardware
	mt19937 eng(rd());							// seed the generator

	uniform_int_distribution<> distr7_44(0, 1);	// define the range
	uniform_int_distribution<> distr7_53(0, 100);	// define the range
	uniform_int_distribution<> distr7_38(0, 180);	// define the range

	std::vector<std::string> stringvector;
	std::vector<int> iAList;
	vector<point> points;


	for (int i = 0; i < 50; ++i)
		(distr7_44(eng)) ? stringvector.push_back("true"): stringvector.push_back("false");

	for (int i = 0; i < 5000; ++i)
		iAList.push_back(distr7_53(eng));

	for (int i = 0; i < 200; ++i)
		points.push_back(point{ distr7_38(eng), distr7_38(eng) });
	

	//////////////////////////////////////////////////////////////////////////////
	// exercise 7_53
	//////////////////////////////////////////////////////////////////////////////
	Sort sorter;
	time_t timev;
	int oldTime = time(&timev);

	sorter.nSquared(iAList, 300);
	int newTime = time(&timev);
	cout << "n^2   runtime: " << newTime - oldTime << " s" << endl;
	oldTime = newTime;

	sorter.nLogN(iAList, 300);
	newTime = time(&timev);
	cout << "nLogn runtime: " << newTime - oldTime << " s"<< endl;


	//////////////////////////////////////////////////////////////////////////////
	// exercise 7_44
	//////////////////////////////////////////////////////////////////////////////
	Sort truefalseobj;
	truefalseobj.truefalse(stringvector);

	//////////////////////////////////////////////////////////////////////////////
	// exercise 7_38
	//////////////////////////////////////////////////////////////////////////////
	vector<edge> solution;
	lineDetect opg7_38;

	solution = opg7_38.getLines(points);
	
	opg7_38.printLines(solution);


	// program terminates
	
	system("pause");

    return 0;
}

