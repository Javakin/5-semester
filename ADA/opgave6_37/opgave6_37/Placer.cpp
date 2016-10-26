#include "stdafx.h"
#include "Placer.h"
#include <vector>
using namespace std;

Placer::Placer()
{
	boxSize = 5;
	boxVector.clear();
}

Placer::Placer(int aBoxSize)
{
	boxSize = aBoxSize;
	boxVector.clear();
}


Placer::~Placer()
{
}

bool Placer::first_match(int aWeight)
{
	// returns false if there is no match
	for (Box aBox : boxVector)
	{
		// to do: begin 
	}
	return false;
}
