#include "stdafx.h"
#include <iostream>
#include "Graph.h"
#include <string>
#include <vector>

using namespace std;


Graph::Graph()
{
}

Graph::Graph(unsigned int numOfVerteies)
{
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
