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
	//point start = { 0,0 };
	//point end = { 10,10 };
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

/*Run the bot*/
void SeekAndDeliver::coverragePlaning(int aStartX, int aStartY)
{


	addNeighbour(10, 10);

}

bool SeekAndDeliver::deliverCoin(unsigned int xVal, unsigned int yVal)
{
	return false;
}

bool SeekAndDeliver::hasConpleted()
{
	return false;
}


void SeekAndDeliver::addNeighbour(int anX, int anY)
{
	int neighbours[4][2] = { { anX + 1,anY },{ anX,anY + 1 },{ anX - 1,anY },{ anX,anY - 1 } };

	for (int i = 0; i < 4; i++)
		if (map->getPixelValuei(neighbours[i][1], neighbours[i][2], 0) == 255)

}
