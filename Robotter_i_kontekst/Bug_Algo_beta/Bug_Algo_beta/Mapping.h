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
	

	~Mapping();

private:
	
	vector< vector< int > > BrushfireExhaustive(int xPos, int yPos, int colour);
	bool validPoint(int xPos, int yPos);

	rw::sensor::Image* map;
	rw::sensor::Image* brushfireMap;

};

