#pragma once

#include "Point.h"
#include "Image.h"
#include "Transform.h"
#include <iostream>



class Robot
{
public:
	Robot();

	Robot(rw::sensor::Image* aMap);

	// Construct a robot at the position x,y and with the facing theta
	Robot(rw::sensor::Image* aMap, double x, double y, double theta);


	// Move robot to new position
	// @ - goal for robot
	void goTo(Transform motion);

	// bugalgorithms deciding the next move
	void bug0();
	void bug1();
	void bug2();

	~Robot();

private:

	// Print out the movement from the input transformation
	void displayPoint(Point position);

	// Trace the movment of the robot on the map(image)
	//void traceRoute(Transform motion);

	// Calcualte the requierd work space
	void calcualteWorkSpace(Transform motion);

	Point current_point;
	Point target_point;

	rw::sensor::Image* map;
};

