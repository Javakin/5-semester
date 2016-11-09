#pragma once
#include <iostream>
#include "Image.h"
#include <vector>
#include <queue>

using namespace std;

class Dijkstra
{
	struct node {
		int distance;
		int x;
		int y;
		node* parent;
	};

	struct points
	{
		bool visited;
	};

public:
	Dijkstra();
	Dijkstra(rw::sensor::Image* aMap);
	void algorithm();
	rw::sensor::Image* getMap();
	~Dijkstra();
private:
	rw::sensor::Image* map;
		int _picHeight, _picWidth, _goalX = 190, _goalY = 190, _startX = 10, _startY = 10;
		vector<node> vectorWithPoints;
		queue<node> _circleQueue;
		void arrangelists();
		void findRoute();

		vector <vector<points>> xValues;
		vector <points> yValues;
};

