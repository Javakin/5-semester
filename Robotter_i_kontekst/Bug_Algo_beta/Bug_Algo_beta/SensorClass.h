#pragma once

#include "Image.h"
#include <iostream>
#include <vector>
#include "Mapping.h"
#include <string>
#include "Robot.h"

using namespace std;
using namespace rw::sensor;

class SensorClass
{
public:
	SensorClass();
	SensorClass(Image * amap, Image * atargetmap);
	~SensorClass();

	void sensoring();

private:

	Image* map;
	Image* targes;
	point currentLocation;
	
};