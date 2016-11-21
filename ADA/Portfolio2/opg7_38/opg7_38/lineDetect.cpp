#include "stdafx.h"
#include "lineDetect.h"
#include "structs.h"
#include <vector>
#include <iostream>
#include "Sort.h"


lineDetect::lineDetect()
{
}

std::vector<edge> lineDetect::getLines(std::vector<point> aPointList)
{
	// setup
	std::vector<edge> linePoints;
	double theta = 0;		// angle

	// iterate through the list													O(N)
	for (unsigned int i = 0; i < aPointList.size(); i++)
	{
		// given a target point ass center find the angle between each point	O(N)
		for (unsigned int j = 0; j < aPointList.size(); j++)
		{
			// x must not be the same
			double param = 0;
			(aPointList[j].xVal != aPointList[i].xVal) ? 
				theta = atan((aPointList[j].yVal - aPointList[i].yVal)/(aPointList[j].xVal - aPointList[i].xVal)) :
				theta = atan(INFINITY);

			linePoints.push_back(edge{ std::vector<point>{aPointList[i], aPointList[j]}, theta});

		}

		// sort the list relative to the value of the angle						O(Nlog(N))


		// iterate through the list, and find points with the same angle		O(N)

		
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
