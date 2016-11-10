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

	void brushfire();	
	void dijkstra(point startPoint, point stopPoint);

	Image* getBrushfireMap();
	Image* getBrushfireMapWObj();

	Image* getBrushfireMapInc();
	Image* getPathMap();

	Image* getVoronoiMap();

	Image * Mapping::getBrushfireMapInc();

	void Voronoi();
	
	vector<point> pointToParth(point aPoint);

	
	~Mapping();

private:
	
	vector<point> brushfireExhaustive(int xPos, int yPos, int colour);
	vector<point> brushfireSingleStep(vector<point> anEdge);
	void brushfireInc();
	bool validPoint(int xPos, int yPos);
	//vector<vector<int>> testvec(rows, vector<int>(cols, val));

	rw::sensor::Image* map;
	rw::sensor::Image* brushfireMap;
	rw::sensor::Image* brushfireMapWObj;
	rw::sensor::Image* brushfireMapInc;
	rw::sensor::Image* pathMap;
	rw::sensor::Image* voronoiMap;


};

