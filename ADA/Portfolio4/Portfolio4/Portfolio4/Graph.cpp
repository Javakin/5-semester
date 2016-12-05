#include "stdafx.h"
#include <iostream>
#include "Graph.h"
#include <string>
#include <vector>

#define DEFAULT_SIZE	15

using namespace std;


Graph::Graph()
{
	vector<vector<unsigned int> > graph((DEFAULT_SIZE), vector<unsigned int>(DEFAULT_SIZE, 0));
	graphData = graph;
}

Graph::Graph(unsigned int numOfVerteies)
{
	vector<vector<unsigned int> > graph((numOfVerteies) , vector<unsigned int>(numOfVerteies, 0));
	graphData = graph;
}

bool Graph::insertEdge(unsigned int startVertex, unsigned int endVertex)
{
	return false;
}

bool Graph::insertEdge(unsigned int startVertex, unsigned int endVertex, unsigned int weighting)
{
	return false;
}

bool Graph::deleteEdge(unsigned int startVertex, unsigned int endVertex)
{
	return false;
}

void Graph::printGraph(string printMessage)
{
	cout << printMessage << ":" << endl;
	for (vector<unsigned int> v : graphData)
	{
		for (unsigned int ui : v)
			cout << ui << "  ";
		cout << endl; 
	}

}

vector<unsigned int> Graph::topologicalSort()
{
	// preconditions

	// setup
	vector<unsigned int> topSortList;
	vector<int> topSortDependencies(graphData.size(), 0);
	
	// generate dependencies list
	for (unsigned int i = 0; i < graphData.size(); i++)
	{
		for (unsigned int j = 0; j < graphData.size(); j++)
		{
			if (graphData[i][j] != 0)
				topSortDependencies[j]++;
		}
	}

	int topSem = 1;
	while (topSem != 0)
	{
		topSem = 0;
		// iterate through list
		for (unsigned int i = 0; i < topSortDependencies.size(); i++)
		{
			// finde values = 0
			if (topSortDependencies[i] == 0)
			{
				// the vertex is now at "false" state and will be ignored from here
				topSortDependencies[i] = -1;
				topSortList.push_back(i);
				topSem = 1;
				
				// Update topSortDependencies
				for (unsigned int j = 0; j < graphData.size(); j++)
				{
					if (graphData[i][j] != 0)
						topSortDependencies[j]--;
				}
			}

		}
	}
	
	return topSortList;
}

vector<weighting> Graph::dijkstra(unsigned int startVertex)
{
	// precondition
	if (startVertex >= graphData.size())
	{
		cout << "Invalid vertex number inserted\n";
		return vector<weighting>();
	}
		
	// setup
	weighting initWeight = {startVertex, 0, 1, 0};
	vector<weighting> dijkstraTable(graphData.size(), weighting{0, UINT_MAX, 0, 0});
	dijkstraTable[startVertex] = initWeight;


	// perform dijsktra
	int semDij = 1;
	while (semDij != 0)
	{
		semDij = 0;
		int minWeight = INT_MAX;
		unsigned int nearestVertex = UINT_MAX;

		// find closest vertex
		for (unsigned int i = 0; i < dijkstraTable.size(); i++)
		{
			// look for living branches
			if (dijkstraTable[i].known == 1 && dijkstraTable[i].taken == 0)
			{				
				// chek if better then any other 
				if (minWeight > dijkstraTable[i].vertexWeighting)
				{
					semDij = 1;
					minWeight = dijkstraTable[i].vertexWeighting;
					nearestVertex = i;
				}
			}
		}

		// if new vertex exists update table
		if (semDij != 0)
		{
			dijkstraTable[nearestVertex].taken = 1;

			// add any newly known vertecies
			for (unsigned int j = 0; j < graphData.size(); j++)
			{
				if (graphData[nearestVertex][j] != 0)
				{
					// found one update
					dijkstraTable[j].known = 1;
					if (dijkstraTable[nearestVertex].vertexWeighting + graphData[nearestVertex][j] < dijkstraTable[j].vertexWeighting)
					{
						dijkstraTable[j].parrentVertex = nearestVertex;
						dijkstraTable[j].vertexWeighting = dijkstraTable[nearestVertex].vertexWeighting + graphData[nearestVertex][j];
					}
				}
			}
		}
	}

	return dijkstraTable;
}

vector<unsigned int> Graph::dijkstra(unsigned int startVertex, unsigned int endVertex)
{
	return vector<unsigned int>();
}


Graph::~Graph()
{
}
