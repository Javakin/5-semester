#pragma once

#include "AvlTree.h"

#include <iostream>


int main()
{
	// setup
	AvlTree test;
	
	for (int i = 0; i < 32; i++)
		test.insert(i);
	/*
	test.insert(11);
	test.insert(0);
	test.insert(2);
	test.insert(4);
	test.insert(100);
	test.insert(20);
	test.insert(70);
	test.insert(74);
	test.insert(1);
	test.insert(33);
	test.insert(31);
	test.insert(32);
	test.insert(30);
	test.insert(35);
	test.insert(36);
	test.insert(37);
	*/
	test.printTree();

	// display output for the four print functions
	cout << endl << endl << "print pre-order" << endl;
	test.printPreOrder();

	cout << endl << endl << "print in-order" << endl;
	test.printInOrder();

	cout << endl << endl << "print post-order" << endl;
	test.printPostOrder();

	cout << endl << endl << "print level-order" << endl;
	//test.printLevelOrder();


	// pause program for debugging
	system("pause");
	return 0;
}