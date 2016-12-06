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
	aGraph.insertEdge(1, 2);
	aGraph.insertEdge(4, 2);
	aGraph.insertEdge(3, 4);


	/*
	aGraph.insertEdge(1, 9);
	aGraph.insertEdge(9, 8);
	aGraph.insertEdge(2, 5, 2);
	aGraph.insertEdge(9, 7, 3);
	*/
	//aGraph.deleteEdge(1, 9);

	aGraph.printGraph("Printed graph");

	///////////////////////////////////////////////////////////////
	// do topological sort
	///////////////////////////////////////////////////////////////
	vector<unsigned int> sortedList;
	sortedList = aGraph.topologicalSort();

	cout << "\nPrint Topological sort:\n";
	for (unsigned int i : sortedList)
		cout << i + 1 << ", "; 
	cout << endl;

	///////////////////////////////////////////////////////////////
	// do dijkstra
	///////////////////////////////////////////////////////////////

	Graph bGraph(10);
	bGraph.insertEdge(1, 2, 2);
	bGraph.insertEdge(2, 3, 7);
	bGraph.insertEdge(3, 4, 5);
	bGraph.insertEdge(4, 7, 1);
	bGraph.insertEdge(4, 5, 9);

	bGraph.printGraph("Printed graph 2");

	vector<weighting> pathTree;
	vector<unsigned int> path;
	pathTree = bGraph.dijkstra(0);
	path = bGraph.dijkstra(0, 5);

	cout << "\nPrint dijkstra pathTree:\n";
	cout << "vertex | parrent | weight\n";
	for (unsigned int i = 0; i< pathTree.size(); i++)
		cout << i + 1 << "\t" <<  pathTree[i].parrentVertex +1 << "\t" << pathTree[i].vertexWeighting << endl;
	cout << endl;

	cout << "\nPrint dijkstra path:\n";
	for (unsigned int i : path)
		cout << i << ", ";
	cout << endl;

	system("pause");
    return 0;
}

