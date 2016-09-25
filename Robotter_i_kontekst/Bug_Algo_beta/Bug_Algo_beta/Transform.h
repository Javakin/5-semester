#pragma once

#include "Point.h"

class Transform {
public:
	Transform(double x, double y, double theta);


	~Transform();


	Point mult(const Point& p);
		


	double& operator()(size_t i, size_t j);


	const double& operator()(size_t i, size_t j) const;



private:
	double** _mat;

};
