#include "Dijkstra.h"

Dijkstra::Dijkstra()
{
}

Dijkstra::Dijkstra(rw::sensor::Image * aMap)
{
	map = aMap;
	_picHeight = 20;
	_picWidth = 20;
	cout << "loading picture with size width: " << _picWidth
		<< " and height: " << _picHeight << endl;
	_points.emplace_back(node{ 0,10,10,nullptr});
	_circleQueue.push(node{NULL,10,10 });
}

void Dijkstra::algorithm()
{
	node temppoint;
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
	cout << "Algorithm Done! Size of points is: " << _points.size() << endl;
}

bool Dijkstra::checkForDuplicate(int x, int y)
{
	bent++;
	cout << "Checking for duplicate number: " << bent << endl;
	isEquals = false;
	for (int i = 0; i < _points.size(); i++)
		if (x == _points[i].x && y == _points[i].y)
			isEquals = true;
	return isEquals;
}

Dijkstra::~Dijkstra()
{
}
