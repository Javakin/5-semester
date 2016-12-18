#include "SeekAndDeliver.h"
#include "Image.h"
#include "Mapping.h"
#include <iostream>
#include "Point.h"
#include "Robot.h"
#include "Structs.h"
#include "SensorClass.h"

#define OBJECTS_TO_COLLECT	10

using namespace std;


SeekAndDeliver::SeekAndDeliver(Image* aMap, Mapping* aFireMap, SensorClass* aSensor)
{
	map = aMap->copyFlip(0,0);
	deleveryMap = aMap->copyFlip(0, 0);
	coverageMap = aMap->copyFlip(0, 0);
	fireMap = aFireMap;
	sensor = aSensor;

	fireMap->brushfire();
	fireMap->Voronoi();
	
	point init = { 10, 10 };
	currentLocation = init;
	searchPath.clear();
	deleveryPath.clear();
	foundCoins = 0;
}


SeekAndDeliver::~SeekAndDeliver()
{
	delete map;
	delete deleveryMap;
	delete coverageMap;
}

void SeekAndDeliver::saveAllAsPGM()
{
	fireMap->getBrushfireMap()->saveAsPGM("Images/brushfire.pgm");
	fireMap->getBrushfireMapWObj()->saveAsPGM("Images/brushfireWObj.pgm");
	fireMap->getBrushfireMapInc()->saveAsPGM("Images/brushfireInc.pgm");
	fireMap->getVoronoiMap()->saveAsPGM("Images/voronoidPoints.pgm");
	fireMap->getCellDecMap()->saveAsPGM("Images/cellDecMap.pgm");

	deleveryMap->saveAsPGM("Images/deleveryMap.pgm");
	coverageMap->saveAsPGM("Images/coverageMap.pgm");
}

void SeekAndDeliver::coverragePlaning()
{
	// setup
	vector<Cell> vCells = fireMap->cellDecomp();
	vector<point> route; 
	vector<pixel> vPixels;

	// coverage planning - for every cell
	for (unsigned int i = 0; i < vCells.size(); i++)
	{
		// finde the starting point p1
		route = fireMap->dijkstra(currentLocation, vCells[i].p1);
		for (point p : route)
			searchPath.push_back(p);
		currentLocation = vCells[i].p1;

		// plan the coverage
		unsigned int uiXVal = vCells[i].p1.xVal;
		unsigned int uiYVal = vCells[i].p1.yVal;
		int semYNotFound = 1;
		int xIterator = 1;

		while (semYNotFound)
		{
			uiXVal += xIterator;

			while (uiXVal > vCells[i].p1.xVal && uiXVal < vCells[i].p2.xVal)
			{
				// semsor mesurment

				uiXVal += xIterator;

				// has we reached the bottom?
				
				// have we found an object?
			}
			xIterator = -xIterator;
		}

	}

	// update route and image
	for (point p : searchPath)
	{
		coverageMap->setPixel8U(p.xVal, p.yVal, 60);
	}
}

void SeekAndDeliver::deliverCoin(unsigned int xVal, unsigned int yVal)
{
	// setup
	point objectlocation = {(int) xVal, (int) yVal };
	point dropOffZone = {10, 10};
	foundCoins++;

	// from current to object
	vector<point> route = fireMap->dijkstra(currentLocation, objectlocation);
	for (point p : route)
		deleveryPath.push_back(p);

	// from object to drop of zone 
	route = fireMap->dijkstra(objectlocation, dropOffZone);
	for (point p : route)
		deleveryPath.push_back(p);


	// from drop off zone to cuttent location
	route = fireMap->dijkstra(dropOffZone, currentLocation);
	for (point p : route)
		deleveryPath.push_back(p);

	// update route and image
	for (point p : deleveryPath)
	{
		deleveryMap->setPixel8U(p.xVal, p.yVal, 60);
	}
}

bool SeekAndDeliver::hasConpleted()
{
	if (foundCoins >= OBJECTS_TO_COLLECT)
		return true;

	return false;
}
