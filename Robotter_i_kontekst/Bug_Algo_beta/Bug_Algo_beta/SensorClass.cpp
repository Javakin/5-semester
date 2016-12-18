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
	pixelVector.clear();
	// get the dimensions of the picture
	rows = map->getHeight();
	cols = map->getWidth();

	val = 0; // value of the pixel
	point tempPoint2; // used to contain the position of the pixel being scanned

	// get the dimensions of the picture
	rows2 = targets->getHeight();
	cols2 = targets->getWidth();

	val2 = 0; // value of the pixel
	point tempPoint3; // used to contain the position of the pixel being scanned

	vector<vector<int>> outputVector(rows, vector<int>(cols, val)); // contains the value and position of the pixels scanned with targets
	vector<vector<int>> sensorVector(rows, vector<int>(cols, val)); // contains the value and position of the pixels scannd in the obstacle map
	
	int channel = 0;

	// iterate through the map
	for (unsigned int x = 0; x < map->getWidth(); ++x) {
		for (unsigned int y = 0; y < map->getHeight(); ++y) {
			int val = map->getPixelValuei(x, y, channel);

			sensorVector[x][y] = val; // Put the value of the pixel into the vector
		}
	}


	vector<vector<int>> targetsVector(rows2, vector<int>(cols2, val2)); // contains the value and position of the pixels scannd in the targets map
	
	int channel2 = 0;

	// iterate through the map
	for (unsigned int x = 0; x < targets->getWidth(); ++x) {
		for (unsigned int y = 0; y < targets->getHeight(); ++y) {
			int val2 = targets->getPixelValuei(x, y, channel2);

			targetsVector[x][y] = val2; // Put the value of the pixel into the vector
		}
	}

	int testIt[9][2] = { {0, 0}, { 0, 1 },{ 0, -1 },{ 1, 0 },{ -1, 0 },{ 1, 1 },{ 1, -1 },{ -1,1 },{ -1,-1 } }; // the points relative to the current position that is to be scanned

	// scan the current location and surrounding 8 pixels on both the obstacle map and the targets map
	for (unsigned int i = 0; i < 9; i++)
	{
		// obstacle map
		tempPoint2.xVal = theCurrentLocation.xVal + testIt[i][0];
		tempPoint2.yVal = theCurrentLocation.yVal + testIt[i][1];

		// for debugging
		//cout << "x" << tempPoint2.xVal << "," << "y" << tempPoint2.yVal << "= " << sensorVector[tempPoint2.xVal][tempPoint2.yVal] << " " << endl;

		// targets map
		tempPoint3.xVal = theCurrentLocation.xVal + testIt[i][0];
		tempPoint3.yVal = theCurrentLocation.yVal + testIt[i][1];

		// for debugging
		//cout << "x" << tempPoint3.xVal << "," << "y" << tempPoint3.yVal << "= " << targesVector[tempPoint3.xVal][tempPoint3.yVal] << " " << endl;
		
		// test to see if one of the scanned pixels is a target. If it is the change the value of the pixel to 50
		if (targetsVector[tempPoint3.xVal][tempPoint3.yVal] == 0)
		{
			outputVector[tempPoint2.xVal][tempPoint2.yVal] = 50;
		}
		else // take the value of the pixel from the obstacle map
		{
			outputVector[tempPoint2.xVal][tempPoint2.yVal] = sensorVector[tempPoint2.xVal][tempPoint2.yVal];
		}
		// for debugging
		cout << "x" << tempPoint2.xVal << "," << "y" << tempPoint2.yVal << "= " << outputVector[tempPoint2.xVal][tempPoint2.yVal] << " " << endl;

		// put the value and position of the output vector into a pixel struct
		outputPixel.xVal = tempPoint2.xVal;
		outputPixel.yVal = tempPoint2.yVal;
		outputPixel.colorVal = outputVector[tempPoint2.xVal][tempPoint2.yVal];

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


