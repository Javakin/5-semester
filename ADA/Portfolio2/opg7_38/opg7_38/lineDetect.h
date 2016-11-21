#pragma once
#include <vector>
#include "structs.h"

class lineDetect
{
public:
	lineDetect();
	
	std::vector<edge> getLines(std::vector<point> aPointList);

	~lineDetect();

private:
	
};

