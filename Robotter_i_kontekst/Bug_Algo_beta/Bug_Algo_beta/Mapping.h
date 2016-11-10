#pragma once

#include "Image.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;
using namespace rw::sensor;

class Mapping
{
public:
	Mapping();
	Mapping(Image* amap);

	void Brushfire();	

	Image* getBrushfireMap();
	Image* getBrushfireMapWObj();
	Image* getVoronoiMap();

	void Voronoi();

	~Mapping();

private:
	
	vector< vector< int > > brushfireExhaustive(int xPos, int yPos, int colour);
	vector< vector< int > > brushfireSingleStep(vector< vector< int > > anEdge);
	bool validPoint(int xPos, int yPos);
	//vector<vector<int>> testvec(rows, vector<int>(cols, val));

	rw::sensor::Image* map;
	rw::sensor::Image* brushfireMap;
	rw::sensor::Image* brushfireMapWObj;
	rw::sensor::Image* voronoiMap;

};

