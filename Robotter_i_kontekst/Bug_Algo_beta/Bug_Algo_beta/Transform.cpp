#include "Transform.h"


Transform::Transform(double x, double y, double theta)
{
	double _mat[3][3];

	_mat[0][0] = cos(theta);
	_mat[0][1] = -sin(theta);
	_mat[1][0] = sin(theta);
	_mat[1][1] = cos(theta);

	_mat[0][2] = x;
	_mat[1][2] = y;
	_mat[2][0] = _mat[2][1] = 0;
	_mat[2][2] = 1;
}
Transform::~Transform()
{
}

Point Transform::mult(const Point & p)
{
	Point res(0, 0);
	for (size_t i = 0; i < 2; i++) {
		for (size_t j = 0; j < 3; j++) {
			res(i) += _mat[i][j] * p(j);
		}
	}
	return res;
}

double Transform::operator()(size_t i, size_t j)
{
	return _mat[i][j];
}

const double Transform::operator()(size_t i, size_t j) const
{
	return _mat[i][j];
}


