#include "stdafx.h"
#include "Box.h"


Box::Box()
{
}

Box::Box(int aMaxWeight)
{
	currentWeight = 0;
	maxWeight = aMaxWeight;
}

bool Box::addWeight(int itemWeight)
{
	// returns 1 if the function added sucessfully. 
	if (currentWeight +itemWeight > maxWeight)
		return 0;

	currentWeight += itemWeight; 
	return 1;
}

int Box::getCurrentWeight()
{
	return currentWeight;
}

int Box::getMaxWeight()
{
	return maxWeight;
}


Box::~Box()
{
}
