#include "SeekAndDeliver.h"
#include "Image.h"
#include "Mapping.h"
#include <iostream>
#include "Point.h"
#include "Robot.h"
#include "Structs.h"

#define OBJECTS_TO_COLLECT	10

using namespace std;


SeekAndDeliver::SeekAndDeliver(Image* aMap, Mapping* aFireMap)
{
	map = aMap->copyFlip(0,0);
	deleveryMap = aMap->copyFlip(0, 0);
	coverageMap = aMap->copyFlip(0, 0);
	fireMap = aFireMap;

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
	fireMap->getCellDecMap()->saveAsPGM("Images/cellDecMap");

	deleveryMap->saveAsPGM("Images/deleveryMap.pgm");
	coverageMap->saveAsPGM("Images/coverageMap.pgm");
}

void SeekAndDeliver::coverragePlaning()
{
	vector<Cell> vCells = fireMap->cellDecomp();
	cout << "\nnop\n";
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
