#include <iostream>
#define PI 3.14159265358979323846 

class Point {
public:
	Point(double x, double y)
	{
		_p = new double[3];
		_p[0] = x;
		_p[1] = y;
		_p[2] = 1;
	}

	Point(const Point& p)
	{
		_p = new double[3];
		for (size_t i = 0; i<3; i++)
			_p[i] = p._p[i];
	}

	~Point() {
		delete[] _p;
	}


	double& operator()(size_t i)
	{
		return _p[i];
	}

	const double& operator()(size_t i) const
	{
		return _p[i];
	}




private:
	double* _p;
