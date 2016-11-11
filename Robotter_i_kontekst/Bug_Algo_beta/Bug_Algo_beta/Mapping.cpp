#include "Mapping.h"
#include "Image.h"
#include <iostream>
#include <vector>
#include <string>
#include <deque>
using namespace std;
using namespace rw::sensor;
Mapping::Mapping()
{
	map = nullptr;
	brushfireMap = nullptr;
	brushfireMapWObj = nullptr;
	brushfireMapInc = nullptr;
}
Mapping::Mapping(Image* amap)
{
	map = amap->copyFlip(0, 0);
	brushfireMap = nullptr;
	brushfireMapWObj = nullptr;
	brushfireMapInc = nullptr;
	dijkstraMap = nullptr;
}
void Mapping::Brushfire()
{
	if (map == nullptr)
		return;

	// setup
	brushfireMap = map->copyFlip(0, 0);
	vector< vector< vector<int> > > borderlines;
	int channel = 0; // allways 0 on grayscale image
	int objectColour = 50;

	
	// identifying all objects 
	cout << "identifying all objects..." << endl;
	for (int x = 0; x < brushfireMap->getWidth(); x++)
	{
		for (int y = 0; y < brushfireMap->getHeight(); y++)
		{
			// for every pixel check for a black pixel and run prushfireexhaustive for a collor
			if (brushfireMap->getPixelValuei(x, y, channel) == 0)
			{
				cout << "new object detected\n";
				borderlines.push_back(brushfireExhaustive(x, y, objectColour));
				objectColour += 20; /* to do: lav en ordenlig funktion */
			}
		}
	}
	
	// debugging collor edges
	/*for (vector<vector<int> > edge : borderlines)
	{
		for (vector<int> point : edge)
		{
			brushfireMap->setPixel8U(point[0], point[1], 60);
		}
	}*/
	
	// generate inc map
	brushfireInc();

	// begin brushfiring
	int semEmpty = 1;
	while (semEmpty != 0)
	{
		semEmpty = 0;
		for (unsigned int i = borderlines.size(); i > 0; i--)
		{
			// for each object brushfire one step
			borderlines[i - 1] = brushfireSingleStep(borderlines[i - 1]);

			// vector still full?
			if (borderlines[i - 1].size() != 0)
				semEmpty = 1;
		}		
	}

	// update brushfireMapWObj
	brushfireMapWObj = brushfireMap->copyFlip(0, 0);
	for (int x = 0; x < brushfireMap->getWidth(); x++)
	{
		for (int y = 0; y < brushfireMap->getHeight(); y++)
		{
			if (map->getPixelValuei(x, y, channel) == 0)
			{
				brushfireMapWObj->setPixel8U(x, y, 0);
			}
		}
	}
}
void Mapping::dijkstra()
{
	if (map == nullptr)
		return;
	
	//Initialize variables//
	vector<pair<int, int>> voronoidNodes;
	pair <int, int> _start,_goal;
	_start.first = 10; _start.second = 10;
	_goal.first = 190; _goal.second = 190;


	voronoidNodes.emplace_back(11, 10);
	voronoidNodes.emplace_back(12, 10);
	voronoidNodes.emplace_back(12, 11);
	voronoidNodes.emplace_back(12, 12);
	voronoidNodes.emplace_back(13, 13);
	voronoidNodes.emplace_back(50, 65);
	voronoidNodes.emplace_back(50, 66);
	voronoidNodes.emplace_back(50, 67);


	dijkstra(voronoidNodes,_start,_goal);
}
vector<pair<int, int>> Mapping::dijkstra(vector<pair<int, int>> nodes, pair<int, int> start, pair<int, int> goal)
{
	dijkstraMap = map->copyFlip(0, 0);
	typedef struct node {
		inline node() {}
		inline node(bool vis, pair<int, int> cord) : visited(vis), coords(cord) {}
		bool visited;
		pair<int, int> coords;
	};

	vector<node> unsorted_vector;
	vector<pair<int, int>> vPair;
	queue <pair<int, int>> circleQueue;
	for (int i = 0; i < nodes.size(); i++)
	{
		unsorted_vector.emplace_back(false, nodes[i]);
	}
	circleQueue.push(make_pair(10, 10));
	vPair.emplace_back(make_pair(10, 10));
	int relIderat[8][2] = { { 0,1 },{ 0,-1 },{ 1,0 },{ -1,0 },{ 1,1 },{ -1,-1 },{ -1,1 },{ 1,-1 } };

	while (circleQueue.empty() == false)
	{
		for (int i = 0; i < unsorted_vector.size(); i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (unsorted_vector[i].coords.first == circleQueue.front().first + relIderat[j][0] && unsorted_vector[i].coords.second == circleQueue.front().second + relIderat[j][1] && unsorted_vector[i].visited == false)
				{
					circleQueue.push(unsorted_vector[i].coords);
					vPair.emplace_back(unsorted_vector[i].coords);
					unsorted_vector[i].visited = true;
				}
			}
		}
		cout << circleQueue.front().first << circleQueue.front().second << endl;
		circleQueue.pop();
	}


//	//Initialize Map//
//	dijkstraMap = map->copyFlip(0, 0);
//
//	vector <node>route;
//
//	route.emplace_back(0, false, make_pair(10, 10), nullptr);
//	route.emplace_back(0, false, make_pair(10, 10), &route[0]);
//	cout << route[1].parent->visited << endl;
//	
//	//Initialize variables//
//	vector<pair<int, int>> vPairs;
//
//	//queue<pair<int, int>> circleQueue;
//
//	//int relIderat[8][2] = { { 0,1 },{ 0,-1 },{ 1,0 },{ -1,0 },{ 1,1 },{ -1,-1 },{ -1,1 },{ 1,-1 } };
//
//	//vector<int> crossroads;
//
//	//crossroads.resize(nodes.size());
//
//	////Init start point//
//	//route.emplace_back(0,true,start,make_pair(0,0));
//	//vPairs.emplace_back(start);
//	//circleQueue.push(start);
//	////Find the shortest route//
//	//while (circleQueue.empty() == false)
//	//{
//	//	for (int i = 0; i < nodes.size() - 1; i++)
//	//	{
//	//		for (int j = 0; j < 8; j++)
//	//		{
//	//			if (nodes[i].first == circleQueue.front().first + relIderat[j][0] && nodes[i].second == circleQueue.front().second + relIderat[j][1])
//	//			{
//	//				//routes.emplace_back(nodes[i])
//	//				crossroads[i]++;
//	//				if (crossroads[i] > 1)
//	//				{
//
//	//				}
//	//				else
//	//				{
//	//					routes.push_back(nodes[i]);
//	//					circleQueue.push(nodes[i]);
//	//				}
//	//			}
//	//		}
//	//	}
//	//	circleQueue.pop;
//	//}
//
//
	return vPair;
}

Image* Mapping::getBrushfireMap()
{
	return brushfireMap;
}
Image * Mapping::getBrushfireMapWObj()
{
	return brushfireMapWObj;
}
Image * Mapping::getDijkstraMap()
{
	return dijkstraMap;
}
Image * Mapping::getBrushfireMapInc()
{
	return brushfireMapInc;
}
Mapping::~Mapping()
{
	delete map;
	delete brushfireMap;
	delete brushfireMapWObj;
	delete brushfireMapInc;
	delete dijkstraMap;
}
vector<vector<int> > Mapping::brushfireExhaustive(int xPos, int yPos, int colour)
{
	// setup
	int relIderat[4][2] = { { 0,1 },{ 0,-1 },{ 1,0 },{ -1, 0 } };
	int channel = 0;				// allways 0 on grayscale image
	vector<int> current_point = {xPos, yPos};
	vector<vector<int> > pointStack = { current_point };
	vector<vector<int> > borderLinePoints;
	brushfireMap->setPixel8U(xPos, yPos, colour);
	

	// do exaustive brushfire
	while (pointStack.size() != 0)
	{
		// pop new pixel
		current_point = pointStack.back();
		pointStack.pop_back();

		//check for childes
		for (int i = 0; i < 4; i++)
		{
			int semBorder = 0;

			if (validPoint(current_point[0] + relIderat[i][0], current_point[1] + relIderat[i][1]))
			{
				int pixVal = brushfireMap->getPixelValuei(current_point[0] + relIderat[i][0], current_point[1] + relIderat[i][1], channel);
				//case one: pixel is borderLine point
				if (semBorder == 0 && pixVal == 255)
				{
					// add borderline point
					borderLinePoints.push_back(current_point);
					semBorder++;
				}
				// case two: pixel is a new black pixel
				if (pixVal == 0)
				{
					// colour point and add to the pointstack
					vector<int> pointHolder = { current_point[0] + relIderat[i][0], current_point[1] + relIderat[i][1] };
					brushfireMap->setPixel8U(pointHolder[0], pointHolder[1], colour);
					pointStack.push_back(pointHolder);
				}
			}
		}
	}

	return borderLinePoints;
}
vector<vector<int>> Mapping::brushfireSingleStep(vector<vector<int>> anEdge)
{
	// precondition
	if (anEdge.size() == 0)
		return vector<vector<int> >();

	// setup
	int relIderat[4][2] = { { 0,1 },{ 0,-1 },{ 1,0 },{ -1, 0 } };
	int channel = 0;				// allways 0 on grayscale image
	int colour = brushfireMap->getPixelValuei(anEdge[0][0], anEdge[0][1], channel);
	vector<int> current_point;
	vector<vector<int> > borderLinePoints;


	// do exaustive brushfire
	while (anEdge.size() != 0)
	{
		// pop new pixel
		current_point = anEdge.back();
		anEdge.pop_back();

		//check for childes
		for (int i = 0; i < 4; i++)
		{
			if (validPoint(current_point[0] + relIderat[i][0], current_point[1] + relIderat[i][1]))
			{
				int pixVal = brushfireMap->getPixelValuei(current_point[0] + relIderat[i][0], current_point[1] + relIderat[i][1], channel);

				// pixel is a new white pixel
				if (pixVal == 255)
				{
					// colour point and add to the borderLineStack
					vector<int> pointHolder = { current_point[0] + relIderat[i][0], current_point[1] + relIderat[i][1] };
					brushfireMap->setPixel8U(pointHolder[0], pointHolder[1], colour);
					borderLinePoints.push_back(pointHolder);
				}
			}
		}
	}

	return borderLinePoints;
}
void Mapping::brushfireInc()
{
	brushfireMapInc = map->copyFlip(0, 0);

	int relIderat[4][2] = { { 0,1 },{ 0,-1 },{ 1,0 },{ -1, 0 } };
	int semWhite = 0;

	for (int collor = 1; collor < 255; collor++)
	{
		semWhite = 0;
		for (int x = 0; x < brushfireMap->getWidth(); x++)
		{
			for (int y = 0; y < brushfireMap->getHeight(); y++)
			{
				// for every pixel check for a black pixel and run prushfireexhaustive for a collor
				if (brushfireMapInc->getPixelValuei(x, y, 0) == 255)
				{
					semWhite = 1;
					for (int i = 0; i < 4; i++)
					{
						if (brushfireMapInc->getPixelValuei(x + relIderat[i][0], y + relIderat[i][1], 0) == collor - 1)
						{
							brushfireMapInc->setPixel8U(x, y, collor);
						}
					}
				}
			}
		}
		if (semWhite == 0)
		{
			break;
		}
	}
}
bool Mapping::validPoint(int xPos, int yPos)
{
	//out of bounce check xPos
	if (xPos < 0 || xPos >= brushfireMap->getWidth())
	{
		//cout << "error: wrong xpos on the map\n";
		return false;
	} 
	// oute of bounce check yPos
	if (yPos < 0 || yPos >= brushfireMap->getHeight())
	{
		//cout << "error: wrong ypos on the map\n";
		return false;
	}

	// nothing is wrong return true
	return true;
}


