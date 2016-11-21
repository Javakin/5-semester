#include "stdafx.h"
#include "lineDetect.h"
#include "structs.h"
#include <vector>
#include <iostream>
#include "Sort.h"

using namespace std;

lineDetect::lineDetect()
{
}

std::vector<edge> lineDetect::getLines(std::vector<point> aPointList)
{
	// setup
	std::vector<edge> linePoints;
	double theta = 0;		// angle
	Sort anObj;
	double param = 2;

	// iterate through the list													O(N)
	for (unsigned int i = 0; i < aPointList.size(); i++)
	{
		// given a target point ass center find the angle between each point	O(N)
		linePoints.clear();
		for (unsigned int j = 0; j < aPointList.size(); j++)
		{
			// points must not be the same
			if (i != j)
			{
				(aPointList[j].xVal != aPointList[i].xVal) ?
					theta = atan(((double)aPointList[j].yVal - (double)aPointList[i].yVal) / ((double)aPointList[j].xVal - (double)aPointList[i].xVal)) :
					theta = atan(INFINITY);
			}

			linePoints.push_back(edge{ std::vector<point>{aPointList[i], aPointList[j]}, theta});
		}

		// sort the list relative to the value of the angle						O(Nlog(N))
		anObj.vMergSort(linePoints);

		

		// iterate through the list, and find points with the same angle		O(N)
		edge oldEdge;
		for (edge e : linePoints)
		{
			oldEdge = e; 
		}
			

		
		
		/*for (unsigned int j = 0; j < i; j++)
		{
			
			
		}*/
	}

	// remove any doblicates in the list

	// function done return resoult
	return std::vector<edge>();
}


lineDetect::~lineDetect()
{
}
