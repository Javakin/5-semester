#include "Robot.h"
#include "Point.h"
#include "Image.h"
#include "Transform.h"


Robot::Robot()
{
}



Robot::~Robot()
{
}

void Robot::goTo(double x, double y, double theta)
{

}

void Robot::printMotionSequence(Point, Transform)
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

void Robot::traceRoute(Transform motion)
{

}

int Robot::calcualteWorkSpace(Transform motion)
{
	return 0;
}