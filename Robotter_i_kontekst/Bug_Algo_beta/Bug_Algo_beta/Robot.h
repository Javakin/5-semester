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
	void goTo(double x, double y, double theta);
	void goTo(Transform motion);


	/*// Move the robot forward
	//void moveahead(int enafstand);

	// Rotate the robot
	//void rotate(int degrees);

	// Print the trajectory of the robot on the map
	//void printtrajectory();

	// 
	//void move(int x, int y, int rot);*/

	~Robot();

private:

	// Print out the movement from the input transformation
	void printMotionSequence(Point position, Transform motion);

	// Trace the movment of the robot on the map(image)
	void traceRoute(Transform motion);

	// Calcualte the requierd work space
	int calcualteWorkSpace(Transform motion);


	// variables
	double theta;

	Point current_point;
	
	double current_theta;
	
	//Point temporary_point;

	rw::sensor::Image* map;
};

