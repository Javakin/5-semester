#pragma once

#include <vector>
#include "Box.h"



class Placer
{
public:
	Placer();
	Placer(int aBoxSize);
	~Placer();

	// placing strategies
	bool first_match(int aWeight);

	// debugging programs

private:
	vector<Box> boxVector; 
	int boxSize;
};

