#pragma once
#include <vector>
#include <iostream>
#include <string>
class Sorting_class
{
public:
	Sorting_class();

	void nSquared();

	void Quicksort();

	void truefalse();

	~Sorting_class();
private:
	std::vector<int> test = { 4, 4, 5, 8, 2, 7, 3 };
	std::vector<std::string> stringvector = { "true", "false", "false", "true" };
	//std::vector<int> test2 = { 4, 4, 5, 8, 2, 7, 3 };
};

