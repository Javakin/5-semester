#include "SensorClass.h"
#include "Image.h"
#include "PPMLoader.h"


using namespace rw::loaders;
using namespace std;


SensorClass::SensorClass(Image* amap, Image* atargetmap)
{
	// make a copy of the maps
	map = amap->copyFlip(0, 0);
	targets = atargetmap->copyFlip(0, 0);
	
}

vector<pixel> SensorClass::sensoring(point theCurrentLocation)
{
	// setup
	point tempPoint;
	vector<pixel> pixelVector; 
	

	int testIt[9][2] = { {0, 0}, { 0, 1 },{ 0, -1 },{ 1, 0 },{ -1, 0 },{ 1, 1 },{ 1, -1 },{ -1,1 },{ -1,-1 } }; // the points relative to the current position that is to be scanned

	// scan the current location and surrounding 8 pixels on both the obstacle map and the targets map
	for (unsigned int i = 0; i < 9; i++)
	{
		// obstacle map
		tempPoint.xVal = theCurrentLocation.xVal + testIt[i][0];
		tempPoint.yVal = theCurrentLocation.yVal + testIt[i][1];

		// for debugging
		//cout << "x" << tempPoint2.xVal << "," << "y" << tempPoint2.yVal << "= " << sensorVector[tempPoint2.xVal][tempPoint2.yVal] << " " << endl;

		// test to see if one of the scanned pixels is a target. If it is then change the value of the pixel to 50
		outputPixel.xVal = tempPoint.xVal;
		outputPixel.yVal = tempPoint.yVal;
		outputPixel.colorVal = map->getPixelValuei(tempPoint.xVal, tempPoint.yVal, 0);

		if (targets->getPixelValuei(tempPoint.xVal, tempPoint.yVal, 0) == 0)
		{
			outputPixel.colorVal = 50;
			targets->setPixel8U(tempPoint.xVal, tempPoint.yVal, 125);
		}
		// push the pixels into the pixelVector
		pixelVector.push_back(outputPixel);
	}

	return pixelVector;
}

SensorClass::~SensorClass()
{
	// cleanup
	delete map;
	delete targets;
}

Image * SensorClass::getTargetMap()
{
	return targets;
}


