#pragma once

#include <iostream>
#include <string>

#define PI 3.14159265358979323846 

class Point {
public:
	Point();

	Point(double x, double y);

	Point(const Point& p);

	void printPoint(std::string aName);

	~Point();
	

	double& operator()(size_t i);

	const double& operator()(size_t i) const;




private:
	double _p[3];

};
