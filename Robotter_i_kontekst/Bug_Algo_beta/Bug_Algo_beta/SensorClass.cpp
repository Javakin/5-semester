#include "SensorClass.h"



SensorClass::SensorClass()
{
}

SensorClass::SensorClass(Image * amap, Image * atargetmap)
{
	map = amap->copyFlip(0, 0);
	targes = atargetmap->copyFlip(0, 0);
	point init = { 10, 10 };
	currentLocation = init;
	//cout << endl << "test 1" << endl;
}

void SensorClass::sensoring(point acurrentLocation)
{
	currentLocation = acurrentLocation;
		
	// setup map
	if (map == nullptr)
	{
		return;
	}

	int rows = map->getHeight();
	int cols = map->getWidth();
	int val = 0;
	point tempPoint2;

	// setup targes
	if (targes == nullptr)
	{
		return;
	}
	/*cout << endl << "test 2" << endl;
	vector<point> test;*/

	/*int rows = map->getHeight();
	int cols = map->getWidth();
	int val = 0;
	point tempPoint2;*/

	int rows2 = targes->getHeight();
	int cols2 = targes->getWidth();
	int val2 = 0;
	point tempPoint3;

	vector<vector<int>> outputVector(rows, vector<int>(cols, val));

	vector<vector<int>> sensorVector(rows, vector<int>(cols, val));
	int channel = 0;

	for (unsigned int x = 0; x < map->getWidth(); ++x) {
		for (unsigned int y = 0; y < map->getHeight(); ++y) {
			int val = map->getPixelValuei(x, y, channel);

			sensorVector[x][y] = val; // Put the value of the pixel into the vector
		}
	}

	vector<vector<int>> targesVector(rows2, vector<int>(cols2, val2));
	int channel2 = 0;

	for (unsigned int x = 0; x < targes->getWidth(); ++x) {
		for (unsigned int y = 0; y < targes->getHeight(); ++y) {
			int val2 = targes->getPixelValuei(x, y, channel2);

			targesVector[x][y] = val2; // Put the value of the pixel into the vector
		}
	}

	//cout << "x" << currentLocation.xVal << "," << "y" << currentLocation.yVal << "= " << sensorVector[currentLocation.xVal][currentLocation.yVal] << " ";
	//int testIt[8][2] = { { 0, 1 },{ 0, -1 },{ 1, 0 },{ -1, 0 },{ 1, 1 },{ 1, -1 },{ -1,1 },{ -1,-1 } };

	//for (unsigned int i = 0; i < 8; i++)
	//{
	//	tempPoint2.xVal = currentLocation.xVal + testIt[i][0];
	//	tempPoint2.yVal = currentLocation.yVal + testIt[i][1];

	//	// for debugging
	//	//cout << "x" << tempPoint2.xVal << "," << "y" << tempPoint2.yVal << "= " << sensorVector[tempPoint2.xVal][tempPoint2.yVal] << " " << endl;
	//}

	//int testIt2[8][2] = { { 0, 1 },{ 0, -1 },{ 1, 0 },{ -1, 0 },{ 1, 1 },{ 1, -1 },{ -1,1 },{ -1,-1 } };

	//for (unsigned int i = 0; i < 8; i++)
	//{
	//	tempPoint3.xVal = currentLocation.xVal + testIt2[i][0];
	//	tempPoint3.yVal = currentLocation.yVal + testIt2[i][1];

	//	// for debugging
	//	//cout << "x" << tempPoint3.xVal << "," << "y" << tempPoint3.yVal << "= " << targesVector[tempPoint3.xVal][tempPoint3.yVal] << " " << endl;
	//}

	int testIt[9][2] = { {0, 0}, { 0, 1 },{ 0, -1 },{ 1, 0 },{ -1, 0 },{ 1, 1 },{ 1, -1 },{ -1,1 },{ -1,-1 } };
	//int testIt2[8][2] = { { 0, 1 },{ 0, -1 },{ 1, 0 },{ -1, 0 },{ 1, 1 },{ 1, -1 },{ -1,1 },{ -1,-1 } };
	for (unsigned int i = 0; i < 9; i++)
	{

		tempPoint2.xVal = currentLocation.xVal + testIt[i][0];
		tempPoint2.yVal = currentLocation.yVal + testIt[i][1];

		// for debugging
		//cout << "x" << tempPoint2.xVal << "," << "y" << tempPoint2.yVal << "= " << sensorVector[tempPoint2.xVal][tempPoint2.yVal] << " " << endl;

		tempPoint3.xVal = currentLocation.xVal + testIt[i][0];
		tempPoint3.yVal = currentLocation.yVal + testIt[i][1];

		// for debugging
		//cout << "x" << tempPoint3.xVal << "," << "y" << tempPoint3.yVal << "= " << targesVector[tempPoint3.xVal][tempPoint3.yVal] << " " << endl;
		if (targesVector[tempPoint3.xVal][tempPoint3.yVal] == 0)
		{
			outputVector[tempPoint2.xVal][tempPoint2.yVal] = 50;
		}
		else
		{
			outputVector[tempPoint2.xVal][tempPoint2.yVal] = sensorVector[tempPoint2.xVal][tempPoint2.yVal];
		}
		// for debugging
		cout << "x" << tempPoint2.xVal << "," << "y" << tempPoint2.yVal << "= " << outputVector[tempPoint2.xVal][tempPoint2.yVal] << " " << endl;

		outputPixel.xVal = tempPoint2.xVal;
		outputPixel.yVal = tempPoint2.yVal;
		outputPixel.colorVal = outputVector[tempPoint2.xVal][tempPoint2.yVal];

		pixelVector.push_back(outputPixel);
	}
	//return pixelVector;
}

SensorClass::~SensorClass()
{
	delete map;
}


