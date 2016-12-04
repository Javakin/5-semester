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
	return vector<unsigned int>();
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
