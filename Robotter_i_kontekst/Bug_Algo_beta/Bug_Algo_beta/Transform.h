#pragma once

#include "Point.h"
#include <iostream>
#include <string>

class Transform {
public:
	Transform(double x, double y, double theta);

	~Transform();

	Point mult(const Point& p);
		
	double& operator()(size_t i, size_t j);

	const double& operator()(size_t i, size_t j) const;
	
	void printTransform(std::string aName);
	
	void remove();




private:
	double** _mat;

};
