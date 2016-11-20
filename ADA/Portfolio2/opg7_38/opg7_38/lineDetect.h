#pragma once
#include <vector>
#include "structs.cpp"

class lineDetect
{
public:
	lineDetect();
	
	std::vector<edge> getLines(std::vector<point> aPointList);

	~lineDetect();

private:
	
};

