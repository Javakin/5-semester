// ConsoleApplication1.cpp : Defines the entry point for the console application.
// We are given an array that contains N numbers.
// We want to determine if there are two numbers whose sum equals a given number K.
// For instance, if the input is 8, 4, 1, 6, and K is 10, then the answer is yes (4 and 6).
// A number may be used twice. Do the following:
// a. Give an O(N2) algorithm to solve this problem. 
// b. Give an O(NlogN) algorithm to solve this problem.
// (Hint: Sort the items ﬁrst. After that is done, you can solve the problem in linear time.)
// c. Code both solutions and compare the running times of your algorithms. 

#include "stdafx.h"

#include "Sorting.h"

#include <iostream>
#include <ostream>
#include <random>

int main()
{
	std::random_device rd;

	std::cout << rd.min() << std::endl;
	std::cout << rd.max() << std::endl;
	
	int i = 0;

	while (rd() <= rd.max())
	{
		i++;
		std::cout << i << std::endl;
	}
	

	
    return 0;
}

