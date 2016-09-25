#pragma once

#include "Point.h"
#include "Image.h"
#include "Transform.h"

#include <iostream>

class Robot_3
{
public:
	Robot_3();

	// Construct a robot at the position x,y and with the facing theta
	Robot_3(double x, double y, double theta);

	// Move robot to new position
	void goTo(double x, double y, double theta);

	// Print out the movement from the input transformation
	void printMotionSequence(Point position, Transform motion);

	// Trace the movment of the robot on the map(image)
	void traceRoute(Transform motion);

	// Calcualte the requierd work space
	int calcualteWorkSpace(Transform motion);

	~Robot_3();

private:
	Point current_point;

	rw::sensor::Image* map;

	
};

