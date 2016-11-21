#pragma once
#include "stdafx.h"
#include <vector>

struct point
{
	int xVal;
	int yVal;
};

struct edge
{
	std::vector<point> Lpoints;
	double angle;
};