
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

};

class Transform {
public:
	Transform(double x, double y, double theta) {
		_mat = new double*[3];
		_mat[0] = new double[3];
		_mat[1] = new double[3];
		_mat[2] = new double[3];

		_mat[0][0] = cos(theta);
		_mat[0][1] = -sin(theta);
		_mat[1][0] = sin(theta);
		_mat[1][1] = cos(theta);

		_mat[0][2] = x;
		_mat[1][2] = y;
		_mat[2][0] = _mat[2][1] = 0;
		_mat[2][2] = 1;
	}

	~Transform()
	{
		for (size_t i = 0; i < 3; i++) {
			delete[] _mat[i];
		}
		delete[] _mat;
	}

	Point mult(const Point& p) {
		Point res(0, 0);
		for (size_t i = 0; i < 2; i++) {
			for (size_t j = 0; j < 3; j++) {
				res(i) += _mat[i][j] * p(j);
			}
		}
		return res;
	}


	double& operator()(size_t i, size_t j)
	{
		return _mat[i][j];
	}

	const double& operator()(size_t i, size_t j) const
	{
		return _mat[i][j];
	}


private:
	double** _mat;

};



