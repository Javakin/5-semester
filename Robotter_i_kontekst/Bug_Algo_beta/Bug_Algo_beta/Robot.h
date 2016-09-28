#pragma once

#include "Point.h"
#include "Image.h"
#include "Transform.h"
#include <iostream>
#include <string>



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

	// Move the robot forward
	void moveahead(double enxafstand, double enyafstand);

	// Rotate the robot
	void rotate(double degrees);

	// Print the movement of the robot to the therminal
	void printtrajectory();

	// The function that uses the rotate and moveahead function
	void move(double enx, double eny, double enrot);

	~Robot();

private:

	/*double x = 0;
	double y = 0;
	double tempx = 0;
	double tempy = 0;*/
	double orientation = 0;
	double hyp = 0;
	//double deltax = 0;
	//double deltay = 0;
	int counter = 0;


	// Print out the movement from the input transformation
	//void displayPoint(Point position);

	// Trace the movment of the robot on the map(image)
	//void traceRoute(Transform motion);

	// Calcualte the requierd work space
	void calcualteWorkSpace(Transform motion);

	Point delta_point;
	Point current_point;
	Point target_point;

	rw::sensor::Image* map;
};

