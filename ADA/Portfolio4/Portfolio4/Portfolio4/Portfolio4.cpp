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

	Graph aGraph(10);
	aGraph.insertEdge(1, 9);
	aGraph.insertEdge(9, 8);
	aGraph.insertEdge(7, 1); 
	aGraph.insertEdge(5, 2);
	aGraph.insertEdge(2, 6);
	aGraph.insertEdge(5, 1);
	aGraph.insertEdge(2, 5, 2);
	aGraph.insertEdge(9, 7, 3);

	aGraph.deleteEdge(1, 9);

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
	vector<weighting> pathTree;
	vector<unsigned int> path;
	pathTree = aGraph.dijkstra(1);
	path = aGraph.dijkstra(1, 8);

	cout << "\nPrint dijkstra pathTree:\n";
	for (weighting w : pathTree)
		cout << w.parrentVertex << "\t" << w.vertexWeighting << endl;
	cout << endl;

	cout << "\nPrint dijkstra path:\n";
	for (unsigned int i : path)
		cout << i << ", ";
	cout << endl;

	system("pause");
    return 0;
}

