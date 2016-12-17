#include "SeekAndDeliver.h"
#include "Image.h"
#include "Mapping.h"
#include <iostream>
#include "Point.h"
#include "Robot.h"



using namespace std;


//SeekAndDeliver::SeekAndDeliver()
//{
//}

SeekAndDeliver::SeekAndDeliver(Image* aMap, Mapping* aFireMap)
{
	map = aMap->copyFlip(0,0);
	fireMap = aFireMap;

	fireMap->brushfire();
	fireMap->Voronoi();

	// go to droppoint
	point start = { 0,0 };
	point end = { 10,10 };
	//fireMap->dijkstra(start, end);
}


SeekAndDeliver::~SeekAndDeliver()
{
	delete map;
}

void SeekAndDeliver::saveAllAsPGM()
{
	fireMap->getBrushfireMap()->saveAsPGM("brushfire.pgm");
	fireMap->getBrushfireMapWObj()->saveAsPGM("brushfireWObj.pgm");
	fireMap->getBrushfireMapInc()->saveAsPGM("brushfireInc.pgm");
	//fireMap->getPathMap()->saveAsPGM("pathMap.pgm");
	fireMap->getVoronoiMap()->saveAsPGM("voronoidPoints.pgm");
	map->saveAsPGM("original.pgm");	
}

void SeekAndDeliver::coverragePlaning()
{
}

bool SeekAndDeliver::deliverCoin(unsigned int xVal, unsigned int yVal)
{
	return false;
}

bool SeekAndDeliver::hasConpleted()
{
	return false;
}
