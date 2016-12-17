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

class SensorClass
{
public:
	SensorClass();
	SensorClass(Image * amap, Image * atargetmap/*, point acurrentLocation*/);
	~SensorClass();

	void sensoring(point acurrentLocation);

private:
	struct pixel
	{
		unsigned int xVal, yVal, colorVal;
	};

	Image* map;
	Image* targes;
	point currentLocation;
	
};