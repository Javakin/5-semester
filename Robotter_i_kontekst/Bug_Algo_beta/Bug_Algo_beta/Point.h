#pragma once

#include <iostream>
#define PI 3.14159265358979323846 

class Point {
public:
	Point();

	Point(double x, double y);


	Point(const Point& p);
	

	~Point() {
		delete[] _p;
	}


	double& operator()(size_t i);

	const double& operator()(size_t i) const;




private:
	double* _p;

};
