#pragma once
#include <iostream>
using namespace std;
class Robot
{
public:
	Robot();
	void moveahead(double enxafstand, double enyafstand);
	void rotate(double degrees);
	void printtrajectory();
	void move(double enx, double eny, double enrot);
	~Robot();
private:
	double x = 0;
	double y = 0;
	double tempx = 0;
	double tempy = 0;
	double orientation = 0;
	double hyp = 0;
	double deltax = 0;
	double deltay = 0;
	int counter = 0;
};

