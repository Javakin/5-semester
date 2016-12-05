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

bool Graph::insertEdge(unsigned int startVertex, unsigned int endVertex) // add edge at [startVertex][endVertex] without weighting
{
	if (startVertex < 0 || endVertex < 0 || startVertex > graphData.size() || endVertex > graphData.size()) // Checks if the edge is outside the matrix.
	{
		cout << "Can't make edge: " << startVertex << ", " << endVertex << endl;
	}
	else
	{
		graphData[startVertex - 1][endVertex - 1] = 1; // add the egde
	}

	return false;
}

bool Graph::insertEdge(unsigned int startVertex, unsigned int endVertex, unsigned int weighting) // add edge at [startVertex][endVertex] with weighting
{
	if (startVertex < 0 || endVertex < 0 || startVertex > graphData.size() || endVertex > graphData.size()) // Checks if the edge is outside the matrix.
	{
		cout << "Can't make edge: " << startVertex << ", " << endVertex << endl;
	}
	else
	{
		graphData[startVertex - 1][endVertex - 1] = weighting; // add the egde
	}
	

	return false;
}

bool Graph::deleteEdge(unsigned int startVertex, unsigned int endVertex) // delete the edge at [startVertex][endVertex]
{
	if (startVertex < 0 || endVertex < 0 || startVertex > graphData.size() || endVertex > graphData.size()) // Checks if the edge is outside the matrix.
	{
		cout << "Can't delete edge: " << startVertex << ", " << endVertex << endl;
	}
	else
	{
		graphData[startVertex - 1][endVertex - 1] = 0; // delete the egde
	}
	

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
	return vector<weighting>();
}

vector<unsigned int> Graph::dijkstra(unsigned int startVertex, unsigned int endVertex)
{
	return vector<unsigned int>();
}


Graph::~Graph()
{
}
