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
	//Robot(rw::sensor::Image* aMap, double x, double y, double theta);


	// Move robot to new position
	// @ - goal for robot
	void goTo(Transform motion);

	// Move the robot forward
	void moveahead(double aDistance);

	// Rotate the robot
	void rotate(double degrees);

	// Print the movement of the robot to the therminal
	void printpoint(Transform aMatrix);

	// The function that uses the rotate and moveahead function
	void move(double enx, double eny, double enrot);

	// returns a the orientation of the transformation matrix
	double getOrientation(Transform aMatrix);

	~Robot();

private:

	
	double orientation = 0;
	double hyp = 0;
	int counter = 0;


	// Calcualte the requierd work space
	void calcualteWorkSpace(Transform motion);

	Point delta_point;				// holds the intervals in witch the robot is to move at a time. 
	Point current_point;			// holds the current possition of the robot
	Point target_point;				// holds the destination of the robot

	Transform initial_trans;		// holds the position and orientation of the robot
	Transform current_trans;		// holds the current possition of the robot
	Transform new_trans;			// the transform to the new point

	rw::sensor::Image* map;
};

