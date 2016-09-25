#include "Robot_3.h"



Robot_3::Robot_3()
{
}



Robot_3::~Robot_3()
{
}

void Robot_3::goTo(double x, double y, double theta)
{

}

void Robot_3::printMotionSequence(Point, Transform)
{
	int sec;
	int x;
	int y;

	// Tabel of the movement for the two wheels and the time they move
	//std::cout << "| Wheel 1 " << "| Wheel 2 " << "| Time [sec] |" << std::endl;
	//std::cout << "Step 1 | " << x << " | " << y << " | " << sec << " | " << std::endl;
	//std::cout << "Step 2 | " << x << " | " << y << " | " << sec << " | " << std::endl;
	//std::cout << "Step 3 | " << x << " | " << y << " | " << sec << " | " << std::endl;
}

void Robot_3::traceRoute(Transform motion)
{

}

int Robot_3::calcualteWorkSpace(Transform motion)
{
	return 0;
}