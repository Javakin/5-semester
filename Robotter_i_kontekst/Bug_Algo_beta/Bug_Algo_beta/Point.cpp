#include "Point.h"



Point::Point()
{
}

Point::Point(double x, double y)
{
	_p = new double[3];
	_p[0] = x;
	_p[1] = y;
	_p[2] = 1;
}

Point::Point(const Point & p)
{
	_p = new double[3];
	for (size_t i = 0; i < 3; i++)
		_p[i] = p._p[i];
}

void Point::printPoint(std::string aName)
{
	std::cout << aName << ":\n";
	for (int i = 0; i < 3; i++)
		std::cout << _p[i] << std::endl;
	std::cout << std::endl;
}

double & Point::operator()(size_t i)
{
	return _p[i];
}

const double & Point::operator()(size_t i) const
{
	return _p[i];
}



Point::~Point()
{
	delete[] _p;
}
