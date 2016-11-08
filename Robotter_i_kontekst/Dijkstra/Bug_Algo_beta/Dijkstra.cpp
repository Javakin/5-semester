#include "Dijkstra.h"

Dijkstra::Dijkstra()
{
}

Dijkstra::Dijkstra(rw::sensor::Image * aMap)
{
	map = aMap;
	_picHeight = map->getHeight();
	_picWidth = map->getWidth();
	cout << "loading picture with size width: " << _picWidth
		<< " and height: " << _picHeight << endl;
	points.emplace_back(new node{ 0,10,10,nullptr,nullptr,nullptr });
}

void Dijkstra::algorithm()
{

}
void Dijkstra::algorithm(node aNode)
{
}
Dijkstra::~Dijkstra()
{
}
