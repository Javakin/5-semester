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
