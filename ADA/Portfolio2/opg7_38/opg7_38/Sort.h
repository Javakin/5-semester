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

using namespace std;

// application specific code


class Sort
{
public:
	// general code
	Sort();
	~Sort();

	void vMergSort(std::vector<int> & vUnsortedList);
	

	// application specific code

private: 
	// general code 
	void vSplitMergSort(std::vector<int> & vUnsortedList, std::vector<int> & vWorkList, unsigned int uiBegin, unsigned int uiEnd);
	void vMerg(std::vector<int> & vUnsortedList, std::vector<int> & vWorkList, unsigned int uiBegin, unsigned int uiMiddle, unsigned int uiEnd);

	// application specific code

};

