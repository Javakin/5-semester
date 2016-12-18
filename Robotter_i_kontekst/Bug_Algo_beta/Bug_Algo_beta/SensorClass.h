#pragma once

#include "Image.h"
#include <iostream>
#include <vector>
#include "Mapping.h"
#include <string>
#include "Robot.h"
#include <vector>

using namespace std;
using namespace rw::sensor;

struct pixel
{
	unsigned int xVal, yVal, colorVal;
};

class SensorClass
{
public:
	SensorClass();
	SensorClass(Image * amap, Image * atargetmap);
	~SensorClass();

	
	vector<pixel> sensoring(point theCurrentLocation);
	
	
private:
	int rows, cols, val;
	int rows2, cols2, val2;
	pixel outputPixel;
	vector<pixel> pixelVector;
	



	Image* map;
	Image* targets;
	
	
};