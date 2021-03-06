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
	
	bool findInt(std::vector<int> vSortedList, int aVal);

	// application specific code
	void vMergSort(std::vector<edge> & vUnsortedList);
	
	bool nSquared(std::vector<int> vUnsortedList, int k);

	bool nLogN(std::vector<int> vUnsortedList, int k);

	void truefalse(std::vector<std::string> & vUnsortedList);

private: 
	
	// general code 
	void vSplitMergSort(std::vector<int> & vUnsortedList, std::vector<int> & vWorkList, unsigned int uiBegin, unsigned int uiEnd);
	void vMerg(std::vector<int> & vUnsortedList, std::vector<int> & vWorkList, unsigned int uiBegin, unsigned int uiMiddle, unsigned int uiEnd);

	// application specific code
	void vSplitMergSort(std::vector<edge> & vUnsortedList, std::vector<edge> & vWorkList, unsigned int uiBegin, unsigned int uiEnd);
	void vMerg(std::vector<edge> & vUnsortedList, std::vector<edge> & vWorkList, unsigned int uiBegin, unsigned int uiMiddle, unsigned int uiEnd);

};

