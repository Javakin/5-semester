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
	/*pair<int, int> current;
	current.first = aStartX; current.second = aStartY;
	
	if (map->getPixelValuei(current.first, current.second, 0) == 0)
		if (checkCoin(current.first, current.second) == true)
			cout << "coin found!" << endl;*/

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

bool SeekAndDeliver::checkCoin(unsigned int x, unsigned int y)
{
	int neighbours[4][2] = { {x + 1,y}, {x,y + 1},{x - 1,y},{x,y - 1} };
	if (map->getPixelValuei(neighbours[1][1], neighbours[1][2], 0) == 255 &&
		map->getPixelValuei(neighbours[2][1], neighbours[2][2], 0) == 255 &&
		map->getPixelValuei(neighbours[3][1], neighbours[3][2], 0) == 255 &&
		map->getPixelValuei(neighbours[4][1], neighbours[4][2], 0) == 255)
		return true;
	else
		return false;
}

void SeekAndDeliver::addNeighbour(int anX, int anY)
{
	int neighbours[4][2] = { { anX + 1,anY },{ anX,anY + 1 },{ anX - 1,anY },{ anX,anY - 1 } };

	for (int i = 0; i < 4; i++)
		cout << "dinmor" << endl;
}
