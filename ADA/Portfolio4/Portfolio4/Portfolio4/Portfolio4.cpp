// Portfolio4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Graph.h"

using namespace std;


int main()
{
	// for detection of memory leaks 
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	///////////////////////////////////////////////////////////////
	// Implement a graph
	///////////////////////////////////////////////////////////////

	Graph aGraph(4);
	aGraph.insertEdge(0, 1);
	aGraph.insertEdge(3, 1);
	aGraph.insertEdge(2, 3);

	aGraph.printGraph("Printed graph");

	///////////////////////////////////////////////////////////////
	// do topological sort
	///////////////////////////////////////////////////////////////

	vector<unsigned int> sortedList;
	sortedList = aGraph.topologicalSort();

	cout << "\nPrint Topological sort:\n";
	for (unsigned int i : sortedList)
		cout << i << ", "; 
	cout << endl;

	///////////////////////////////////////////////////////////////
	// do dijkstra
	///////////////////////////////////////////////////////////////

	Graph bGraph(10);
	
	bGraph.insertEdge(1, 2, 2);
	bGraph.insertEdge(1, 3, 1);
	bGraph.insertEdge(3, 4, 1);
	bGraph.insertEdge(2, 4, 1);
	bGraph.insertEdge(4, 5, 1);


	bGraph.printGraph("Printed graph for dijkstra");

	// setup
	vector<weighting> pathTree;
	vector<unsigned int> path;

	// find dijkstra tree using vertex 1 as root
	pathTree = bGraph.dijkstra(1);

	// find shortest path from vertex 1 to vertex 5
	path = bGraph.dijkstra(1, 5);

	// display resouts
	cout << "\nPrint dijkstra pathTree:\n";
	cout << "vertex | parrent | weight\n";
	for (unsigned int i = 0; i< pathTree.size(); i++)
		cout << i << "\t" <<  pathTree[i].parrentVertex << "\t" << pathTree[i].vertexWeighting << endl;
	cout << endl;

	cout << "\nPrint dijkstra path:\n";
	for (unsigned int i : path)
		cout << i << ", ";
	cout << endl;


	// program terminates
	system("pause");
    return 0;
}

