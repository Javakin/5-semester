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
	vectorWithPoints.push_back(node{ 0 , _startX, _startY ,nullptr});
	_circleQueue.push(node{ NULL, _startX, _startY });
}
void Dijkstra::algorithm()
{
	arrangelists();
	xValues[_startX][_startY].visited = true;
	node tempPoint;
	int counter = 0;
	while (_circleQueue.empty() == false)
	{
		tempPoint = _circleQueue.front();
		_circleQueue.pop();
		if (tempPoint.x + 1 < _picWidth && xValues[tempPoint.x + 1][tempPoint.y].visited == false)
		{
			vectorWithPoints.push_back({ counter + 1 , tempPoint.x + 1 , tempPoint.y, &vectorWithPoints[counter] });
			_circleQueue.push(node{ NULL , tempPoint.x + 1 , tempPoint.y });
			xValues[tempPoint.x + 1][tempPoint.y].visited = true;
			if (tempPoint.x + 1 == _goalX && tempPoint.y == _goalY)
				findRoute();
		}
		if (tempPoint.y + 1 < _picHeight && xValues[tempPoint.x][tempPoint.y + 1].visited == false)
		{
			vectorWithPoints.push_back({ counter + 1 , tempPoint.x , tempPoint.y + 1 , &vectorWithPoints[counter] });
			_circleQueue.push(node{ NULL , tempPoint.x , tempPoint.y + 1 });
			xValues[tempPoint.x][tempPoint.y + 1].visited = true;
			if (tempPoint.x == _goalX && tempPoint.y + 1 == _goalY)
				findRoute();
		}
		if (tempPoint.x > 0 && xValues[tempPoint.x - 1][tempPoint.y].visited == false)
		{
			vectorWithPoints.push_back({ counter + 1 , tempPoint.x - 1 , tempPoint.y, &vectorWithPoints[counter] });
			_circleQueue.push(node{ NULL , tempPoint.x - 1 , tempPoint.y });
			xValues[tempPoint.x - 1][tempPoint.y].visited = true;
			if (tempPoint.x - 1 == _goalX && tempPoint.y == _goalY)
				findRoute();
		}
		if (tempPoint.y > 0 && xValues[tempPoint.x][tempPoint.y - 1].visited == false)
		{
			vectorWithPoints.push_back({ counter+1 , tempPoint.x , tempPoint.y - 1 , &vectorWithPoints[counter] });
			_circleQueue.push(node{NULL , tempPoint.x , tempPoint.y - 1 });
			xValues[tempPoint.x][tempPoint.y - 1].visited = true;
			if (tempPoint.x == _goalX && tempPoint.y - 1 == _goalY)
				findRoute();
		}
		counter++;
	}
	cout << counter << endl;
}

rw::sensor::Image * Dijkstra::getMap()
{
	return map;
}

void Dijkstra::arrangelists()
{
	for (int x = 0; x < _picWidth; x++)
	{
		for (int y = 0; y < _picHeight; y++)
			yValues.push_back(points{false});
		xValues.push_back(yValues);
		yValues.clear();
	}
}

void Dijkstra::findRoute()
{
		node * goalPointer = vectorWithPoints[vectorWithPoints.size()-1].parent;
		cout << "GOAL FOUND AT X: " << _goalX << " Y: " << _goalY << endl;
		cout << vectorWithPoints[vectorWithPoints.size() - 1].parent->parent->distance << endl;
		/*while (goalPointer->parent != nullptr)
		{
			//cout << "Current Pointer is at X: " << goalPointer->x << " And Y: " << goalPointer->y << endl;
			cout << "the distance to start is: " << goalPointer->distance << endl;
			map->setPixel8U(goalPointer->x, goalPointer->y, 0);
			goalPointer = goalPointer->parent;
		}*/

		for (int i = 0; i < 139; i++)
		{
			//cout << "Current Pointer is at X: " << goalPointer->x << " And Y: " << goalPointer->y << endl;
			cout << "the distance to start is: " << goalPointer->distance << endl;
			map->setPixel8U(goalPointer->x, goalPointer->y, 0);
			goalPointer = goalPointer->parent;
		}
}

Dijkstra::~Dijkstra()
{
}


/*node temppoint;
	while (_circleQueue.empty() == false)
	{
		temppoint = _circleQueue.front();
		_circleQueue.pop();
		if (temppoint.x < _picWidth-1)
		{
			if (checkForDuplicate(temppoint.x + 1, temppoint.y) == false)
			{
				_points.push_back(node{ temppoint.distance + 1,temppoint.x + 1,temppoint.y,&temppoint });
				_circleQueue.push(node{ NULL,temppoint.x + 1,temppoint.y });
			}
		}
		if (temppoint.x > 1)
		{
			if (checkForDuplicate(temppoint.x - 1, temppoint.y) == false)
			{
				_points.push_back(node{ temppoint.distance + 1,temppoint.x - 1,temppoint.y,&temppoint });
				_circleQueue.push(node{ NULL,temppoint.x-1,temppoint.y });
			}
		}
		if (temppoint.y < _picHeight-1)
		{
			if (checkForDuplicate(temppoint.x, temppoint.y+1) == false)
			{
				_points.push_back(node{ temppoint.distance + 1,temppoint.x,temppoint.y+1,&temppoint });
				_circleQueue.push(node{ NULL,temppoint.x, temppoint.y+1 });
			}
		}
		if (temppoint.y > 1)
		{
			if (checkForDuplicate(temppoint.x, temppoint.y - 1) == false)
			{
				_points.push_back(node{ temppoint.distance + 1,temppoint.x,temppoint.y-1,&temppoint });
				_circleQueue.push(node{ NULL,temppoint.x,temppoint.y-1 });
			}
		}
	}
	cout << "Algorithm Done! Size of points is: " << _points.size() << endl;*/



/*
		if (tempPoint.x == _goalX && tempPoint.y == _goalY)
		{
			node * goalPointer = vectorWithPoints[vectorWithPoints.size()-1].parent;
			cout << "GOAL FOUND AT X: " << _goalX << " Y: " << _goalY << endl;
			while (goalPointer->distance != 0)
			{
				cout << "Finding route" << endl;
				map->setPixel8U(goalPointer->x, goalPointer->y, 0);
				goalPointer = goalPointer->parent;
			}
			}*/