#pragma once

#include "Image.h"
#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;
using namespace rw::sensor;

class Mapping
{
public:
	Mapping();
	Mapping(Image* amap);

	void Brushfire();
	void dijkstra();
	Image* getBrushfireMap();
	Image* getBrushfireMapWObj();
	Image* getDijkstraMap();
	Image * Mapping::getBrushfireMapInc();	
	~Mapping();

private:
	
	vector< vector< int > > brushfireExhaustive(int xPos, int yPos, int colour);
	vector< vector< int > > brushfireSingleStep(vector< vector< int > > anEdge);
	vector<pair<int,int>> dijkstra(vector<pair<int, int>> nodes, pair<int, int> start, pair<int, int> goal);
	void brushfireInc();
	bool validPoint(int xPos, int yPos);

	rw::sensor::Image* map;
	rw::sensor::Image* brushfireMap;
	rw::sensor::Image* brushfireMapWObj;
	rw::sensor::Image* brushfireMapInc;
	rw::sensor::Image* dijkstraMap;

};

