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

	
}


SeekAndDeliver::~SeekAndDeliver()
{
	delete map;
}

void SeekAndDeliver::saveAllAsPGM()
{
	
	// for debugging 
	/*point start = { 10,10 };
	point end = { 190,190 };
	fireMap->dijkstra(start, end);
	fireMap->getPathMap()->saveAsPGM("pathMap.pgm");*/

	fireMap->getBrushfireMap()->saveAsPGM("brushfire.pgm");
	fireMap->getBrushfireMapWObj()->saveAsPGM("brushfireWObj.pgm");
	fireMap->getBrushfireMapInc()->saveAsPGM("brushfireInc.pgm");
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
