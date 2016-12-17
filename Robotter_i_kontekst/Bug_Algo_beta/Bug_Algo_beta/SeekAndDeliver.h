#pragma once
#include "Image.h"
#include <iostream>
#include <vector>
#include "Mapping.h"
#include <string>
#include "Robot.h"

using namespace std;
using namespace rw::sensor;

class SeekAndDeliver
{
public:
	//SeekAndDeliver();
	SeekAndDeliver(Image* amap, Mapping* aFireMap);
	~SeekAndDeliver();

	void saveAllAsPGM();
	void coverragePlaning();
	void deliverCoin(unsigned int xVal, unsigned int yVal);

private: 
	
	bool hasConpleted();

	unsigned int foundCoins;
	Image* map; 
	Image* deleveryMap;
	Mapping* fireMap;
	point currentLocation;
	vector<point> searchPath;
	vector<point> deleveryPath;
};

