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
		node *left;
		node *right;
		node *front;
	};

public:
	Dijkstra();
	Dijkstra(rw::sensor::Image* aMap);
	void algorithm();
	~Dijkstra();
private:
	rw::sensor::Image* map;
		int _picHeight, _picWidth, _goalX = 190, _goalY = 190, _startX = 10, _startY = 10;
		
		vector<node> points;
		void algorithm(node aNode);
};

