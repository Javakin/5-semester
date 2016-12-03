#include "Transform.h"


Transform::Transform()
{
	// fill it with zeros
	for (size_t i = 0; i < 3; i++) {
		for (size_t j = 0; j < 3; j++) {
			_mat[i][j] = 0;
		}
	}
}

Transform::Transform(double x, double y, double theta)
{
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
	Point res;
	for (size_t i = 0; i < 3; i++) {
		for (size_t j = 0; j < 3; j++) {
			res(i) += _mat[i][j] * p(j);
		}
	}
	return res;
}

Transform Transform::mult(const Transform & T)
{
	Transform res;
	
	for (size_t i = 0; i < 3; i++) {
		for (size_t j = 0; j < 3; j++) {
			// for each unit in the result matrice
			for (size_t k = 0; k < 3; k++) {
				// do the three multiplications
				res(i, j) += _mat[i][k]*T(k, j);
			}
		}
	}
	return res;

}

double & Transform::operator()(size_t i, size_t j)
{
	return _mat[i][j];
}

const double & Transform::operator()(size_t i, size_t j) const
{
	return _mat[i][j];
}

void Transform::printTransform(std::string aName)
{
	// display the content of the transformation matrix
	std::cout << aName << ": " << std::endl;
	for (int i = 0; i < 3; i++) {
		std::cout << _mat[i][0] << "\t" << _mat[i][1] << "\t" << _mat[i][2] << std::endl;
	}
	std::cout << std::endl;
}




