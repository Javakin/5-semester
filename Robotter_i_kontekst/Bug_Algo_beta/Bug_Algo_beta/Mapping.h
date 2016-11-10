#pragma once

#include "Image.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;
using namespace rw::sensor;

struct point {
	int xVal;
	int yVal;
};

struct edge {
	int xVal1;
	int yVal1;
	int xVal2;
	int yVal2;
};

class Mapping
{
public:
	Mapping();
	Mapping(Image* amap);

	void Brushfire();	

	Image* getBrushfireMap();
	Image* getBrushfireMapWObj();
	Image* getBrushfireMapInc();

	vector< point > pointToParth(point aPoint, vector<point> parth);
	
	~Mapping();

private:
	
	vector< point > brushfireExhaustive(int xPos, int yPos, int colour);
	vector< point > brushfireSingleStep(vector<point> anEdge);
	void brushfireInc();
	bool validPoint(int xPos, int yPos);

	rw::sensor::Image* map;
	rw::sensor::Image* brushfireMap;
	rw::sensor::Image* brushfireMapWObj;
	rw::sensor::Image* brushfireMapInc;

};

