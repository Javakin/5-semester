#include "stdafx.h"
#include "lineDetect.h"
#include "structs.cpp"
#include <vector>
#include <iostream>
#include "AvlTree.h"


lineDetect::lineDetect()
{
}

std::vector<edge> lineDetect::getLines(std::vector<point> aPointList)
{
	// list all posible lines of two					O(N^2)
	std::vector<edge> pLines;		// list of all possible lines
	double a = 0;
	double b = 0;

	for (unsigned int i = 1; i < aPointList.size(); i++)
	{
		for (unsigned int j = 0; j < i; j++)
		{
			// x must not be the same
			if ((aPointList[j].xVal != aPointList[i].xVal))
			{
				// p1 = i ; p2 = j
				a = (aPointList[j].yVal - aPointList[i].yVal) / (aPointList[j].xVal - aPointList[i].xVal);
				b = aPointList[i].yVal - (a*aPointList[i].xVal);

				pLines.push_back(edge{ std::vector<point>{aPointList[i], aPointList[j]}, a, b });
			}
			else	// special case vertical line 
			{
				pLines.push_back(edge{ std::vector<point>{aPointList[i], aPointList[j]}, DBL_MAX, DBL_MIN});
			}
		}
	}

	// sort the list of lines via a-value and b-value	O(N^2*log(N))
	AvlTree edgeTree;
	for (edge anEdge : pLines)
	{
		edgeTree.insert(anEdge);
	}

	std::cout << std::endl;



	// iterate through the entire tree of trees to 
	// finde lines containing 4 or more points			O(N^2)
	

	// function done return resoult
	return std::vector<edge>();
}


lineDetect::~lineDetect()
{
}
