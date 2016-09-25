#pragma once

#include "Point.h"
#include "Image.h"
#include "Transform.h"

#include <iostream>

class Robot
{
public:
	Robot();

	// Construct a robot at the position x,y and with the facing theta
	Robot(double x, double y, double theta);

	// Move robot to new position
	void goTo(double x, double y, double theta);

	// Print out the movement from the input transformation
	void printMotionSequence(Point position, Transform motion);

	// Trace the movment of the robot on the map(image)
	void traceRoute(Transform motion);

	// Calcualte the requierd work space
	int calcualteWorkSpace(Transform motion);

	~Robot();

private:
	Point current_point;
	double current_theta;

	rw::sensor::Image* map;

	
};

