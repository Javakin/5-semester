#pragma once

#include "Point.h"
#include <iostream>
#include <string>

class Transform {
public:
	Transform();

	Transform(double x, double y, double theta);

	~Transform();

	Point mult(const Point& p);

	Transform mult(const Transform & T);
		
	double& operator()(size_t i, size_t j);

	const double& operator()(size_t i, size_t j) const;
	
	void printTransform(std::string aName);
	
	void remove();




private:
	double _mat[3][3];
	//double** _mat;

};
