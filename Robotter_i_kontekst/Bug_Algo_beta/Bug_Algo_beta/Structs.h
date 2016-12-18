#pragma once

struct point {
	int xVal;
	int yVal;
	//int weight;
};


struct edge {
	int xVal1;
	int yVal1;
	int xVal2;
	int yVal2;
};

// p1 and p2 is inclusive
struct Cell
{
	point p1, p2;
};

struct pixel
{
	unsigned int xVal, yVal, colorVal;
};
