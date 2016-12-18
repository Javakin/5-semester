#pragma once

#include "Image.h"
#include <iostream>
#include <vector>
#include "Mapping.h"
#include <string>
#include "Robot.h"
#include <vector>
#include "Structs.h"

using namespace std;
using namespace rw::sensor;


class SensorClass
{
public:
	SensorClass(Image* amap, Image* atargetmap);
	~SensorClass();
	
	Image* getTargetMap();

	vector<pixel> sensoring(point theCurrentLocation);
	
private:
	int rows, cols, val;
	int rows2, cols2, val2;
	pixel outputPixel;
	

	Image* map;
	Image* targets;
};