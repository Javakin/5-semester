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
	std::vector<edge> vDetectedLines;
	double theta = 0;		// angle
	Sort anObj;
	double param = 2;

	// iterate through the list													O(N)
	for (unsigned int i = 0; i < aPointList.size(); i++)
	{
		// given a target point ass center find the angle between each point	O(N)
		findAngles(i, aPointList[i], linePoints, aPointList);

		// sort the list relative to the value of the angle						O(Nlog(N))
		anObj.vMergSort(linePoints);

		// iterate through the list, and find points with the same angle		O(N)
		edge eLineCandidate = linePoints[0];

		for (unsigned int j = 1; j < linePoints.size(); j++)
		{			
			// check if new edge is part of a line
			if (linePoints[j - 1].angle == linePoints[j].angle)
				eLineCandidate.Lpoints.push_back(linePoints[j].Lpoints[1]);
			else
			{
				if (eLineCandidate.Lpoints.size() > 3)
				{
					vDetectedLines.push_back(eLineCandidate);
				}
				eLineCandidate = linePoints[j];
			}
		}	
		if (eLineCandidate.Lpoints.size() > 3)
			vDetectedLines.push_back(eLineCandidate);
	}

	// remove doublicets														O(N^2)		
	std::vector<edge> temp = { vDetectedLines };
	vDetectedLines.clear();

	for (edge current : temp)
	{
		// setup
		point p0 = current.Lpoints[0];
		point p1 = current.Lpoints[1];
		int semP0 = 0;
		int semP1 = 0;
		
		// is the edge alredy in the list?
		for (edge existing : vDetectedLines)
		{
			if (existing.angle == current.angle)
			{
				for (point p : existing.Lpoints)
				{
					if ((p.xVal == p0.xVal) && (p.yVal == p0.yVal))
						semP0 = 1;

					if ((p.xVal == p1.xVal) && (p.yVal == p1.yVal))
						semP1 = 1;
				}
			}
		}
		if (!semP0 && !semP1)
		{
			vDetectedLines.push_back(current);
		}
	}

	// function done return resoult
	return vDetectedLines;
}

void lineDetect::findAngles(unsigned int i, point targetPoint, std::vector<edge> & aVect, std::vector<point> & aPointList)
{
	// setup
	double theta = 0;
	aVect.clear();

	for (unsigned int j = 0; j < aPointList.size(); j++)
	{
		// points must not be the same
		if (i != j)
		{
			(aPointList[j].xVal != aPointList[i].xVal) ?
				theta = atan(((double)aPointList[j].yVal - (double)aPointList[i].yVal) / ((double)aPointList[j].xVal - (double)aPointList[i].xVal)) :
				theta = atan(INFINITY);
			aVect.push_back(edge{ std::vector<point>{aPointList[i], aPointList[j]}, theta });
		}
	}
}


lineDetect::~lineDetect()
{
}
