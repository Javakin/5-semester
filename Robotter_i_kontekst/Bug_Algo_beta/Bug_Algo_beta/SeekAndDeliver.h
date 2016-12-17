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
	void coverragePlaning(int aStartX, int aStartY);


private: 
	bool deliverCoin(unsigned int xVal, unsigned int yVal);
	bool hasConpleted();
	void addNeighbour(int anX, int anY);
	Image* map; 
	Mapping* fireMap;
};

