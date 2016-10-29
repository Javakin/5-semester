#pragma once

#include "AvlTree.h"

#include <iostream>


int main()
{
	AvlTree test;
	
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
	
	
	//std::cout << test[1];

	//std::cout << "height: " << test.height() << std::endl;
	/*
	std::cout << "Contains 0: " << test.contains(0) << std::endl;
	std::cout << "Contains 1: " << test.contains(1) << std::endl;
	std::cout << "Contains 2: " << test.contains(2) << std::endl;
	std::cout << "Contains 3: " << test.contains(3) << std::endl;
	std::cout << "Contains 4: " << test.contains(4) << std::endl;
	std::cout << "Contains 7: " << test.contains(7) << std::endl;
	std::cout << "Contains 11: " << test.contains(11) << std::endl;

	std::cout << test.findMax() << std::endl;
	std::cout << test.findMin() << std::endl;

	std::cout << std::endl << std::endl;

	std::cout << "Remove thing on node 1: " << std::endl;
	test.remove(1);

	std::cout << "Contains 0: " << test.contains(0) << std::endl;
	std::cout << "Contains 1: " << test.contains(1) << std::endl;
	std::cout << "Contains 2: " << test.contains(2) << std::endl;
	std::cout << "Contains 3: " << test.contains(3) << std::endl;
	std::cout << "Contains 4: " << test.contains(4) << std::endl;
	std::cout << "Contains 7: " << test.contains(7) << std::endl;
	std::cout << "Contains 11: " << test.contains(11) << std::endl;

	test.printTree();

	//test.height();
	*/

	test.value(0);
	test.printTree();
/*	std::cout << "test 1: " << test.value() << std::endl;
	std::cout << "test 2: " << test.value(2) << std::endl;
	std::cout << "test 3: " << test.value(3) << std::endl;
	std::cout << "test 4: " << test.value(4) << std::endl;
	std::cout << "test 5: " << test.value(5) << std::endl;
*/
	//std::cout << "Height: " << test.height();

	system("pause");
	return 0;
}