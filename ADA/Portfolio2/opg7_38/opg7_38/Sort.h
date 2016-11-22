#pragma once
/*
//
//	This is a genuen class that is ment to handle all sorting related tasks 
//		input vector of objects
//
*/

// general code
#include "stdafx.h"
#include <vector>
#include <iostream>
#include <string>

using namespace std;

// application specific code
#include "structs.h"



class Sort
{
public:
	// general code
	Sort();
	~Sort();

	void vMergSort(std::vector<int> & vUnsortedList);
	
	void nSquared();

	void Mergesort();

	void truefalse();

	// application specific code
	void vMergSort(std::vector<edge> & vUnsortedList);

private: 
	std::vector<int> test = { 4, 4, 5, 8, 2, 7, 3, 6 };
	std::vector<std::string> stringvector = { "true", "false", "false", "true", "true", "false", "false", "true", "true", "false", "false", "true" };
	// general code 
	void vSplitMergSort(std::vector<int> & vUnsortedList, std::vector<int> & vWorkList, unsigned int uiBegin, unsigned int uiEnd);
	void vMerg(std::vector<int> & vUnsortedList, std::vector<int> & vWorkList, unsigned int uiBegin, unsigned int uiMiddle, unsigned int uiEnd);

	// application specific code
	void vSplitMergSort(std::vector<edge> & vUnsortedList, std::vector<edge> & vWorkList, unsigned int uiBegin, unsigned int uiEnd);
	void vMerg(std::vector<edge> & vUnsortedList, std::vector<edge> & vWorkList, unsigned int uiBegin, unsigned int uiMiddle, unsigned int uiEnd);

};

