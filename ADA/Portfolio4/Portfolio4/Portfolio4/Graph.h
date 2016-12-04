#pragma once
#include "stdafx.h"
#include "Graph.h"
#include <string>
#include <vector>

using namespace std;


struct weighting
{
	unsigned int parrentVertex;
	unsigned int vertexWeighting;
	bool known; 
	bool taken;
};


class Graph
{
public:
	Graph();
	Graph(unsigned int numOfVerteies);
	bool insertEdge(unsigned int startVertex, unsigned int endVertex);
	bool insertEdge(unsigned int startVertex, unsigned int endVertex, unsigned int weighting);
	bool deleteEdge(unsigned int startVertex, unsigned int endVertex);
	void printGraph(string printMessage);

	vector<unsigned int> topologicalSort();

	vector<weighting> dijkstra(unsigned int startVertex);
	vector<unsigned int> dijkstra(unsigned int startVertex, unsigned int endVertex);

	~Graph();

private:
	vector<vector<unsigned int> > graphData;
};

