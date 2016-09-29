#pragma once

#include <iostream>
#include "Robot.h"
#include "Point.h"
#include "Image.h"
#include "Transform.h"
#include <cmath>

#define PI 3.14159265358979323846 


Robot::Robot()
{
	std::cout << "called robot default constructor" << std::endl;
	Point p(0,0);
	current_point = p;
	delta_point = p;
	target_point = p;

	Transform t(0, 0, 0);
	initial_trans= t;

	map = NULL;
}

Robot::Robot(rw::sensor::Image * aMap)
{
	Point p(0, 0);
	current_point = p;
	delta_point = p;
	target_point = p;

	Transform t(0, 0, 0);
	initial_trans = t;
	map = aMap;
}


double Robot::getOrientation(Transform aMatrix)
{
	// calculate startpoint
	Point start_point(0, 0);
	start_point = aMatrix.mult(start_point);

	// calculate endpoint
	Point end_point(0,0);
	Transform unit_motion(1, 0, 0);
	end_point = aMatrix.mult(unit_motion).mult(end_point);

	// return result
	return std::atan2(	end_point(1)-start_point(1), 
						end_point(0)-start_point(0));
}

Robot::~Robot()
{
	
}


void Robot::goTo(Transform motion)
{
	new_trans = motion;
	Point current_point(0, 0);

	// debugging
	motion.printTransform("motion");
	initial_trans.printTransform("Initial transform");
	initial_trans.mult(motion).printTransform("final transform");

	std::cout << getOrientation(initial_trans) << std::endl;
	std::cout << getOrientation(initial_trans.mult(new_trans)) << std::endl;


	// set target
	target_point = motion.mult(current_point);
	
	target_point.printPoint("Target point");
	current_point.printPoint("current ");
	std::cout << getOrientation(initial_trans.mult(new_trans)) << std::endl;

	// move robut to target
	move(target_point(0)-current_point(0), target_point(1)-current_point(1), getOrientation(initial_trans.mult(new_trans)));
		
	// update possition transformation
	initial_trans = initial_trans.mult(new_trans);
}

void Robot::moveahead(double enxafstand, double enyafstand)
{
	current_point(0) = target_point(0);
	current_point(1) = target_point(1);

	//target_point(0) += enxafstand;
	//target_point(1) += enyafstand;

	hyp = sqrt(enxafstand*enxafstand + enyafstand*enyafstand);
	delta_point(0) = enxafstand / hyp;
	delta_point(1) = enyafstand / hyp;
	std::cout << "Lenght is " << hyp << std::endl;
	std::cout << "DeltaX is " << delta_point(0) << std::endl;

	printpoint(location_trans);
}


void Robot::rotate(double radians)
{
	// initiate variables
	double orientation = getOrientation(initial_trans);
	double inc = 0.002;

	// if positive rotation rotate counter clockwise
	if (radians > 0)

		for (int i = 0; i < radians; i++) {
			orientation = orientation + inc;
			if (orientation > PI) {
				orientation = - PI;
			}
			std::cout << "The orientation is: " << orientation << " target: " << radians << std::endl;
		}

	// if negative rotation rotate clockwise
	if (radians < 0)
		for (int i = 0; i > radians; i--) {
			orientation = orientation - inc;
			if (orientation < - PI) {
				orientation = PI;
			}
			std::cout << "The orientation is: " << orientation << " target: " << radians << std::endl;
		}
}

void Robot::printpoint(Transform aMatrix)
{
	/*tempx += deltax;
	tempy += deltay;
	std::cout << counter << " The position is:	x: " << tempx << "	y: " << tempy << std::endl;

	if (round(tempx) != x || round(tempy) != y)*/


	/*target_point[0] += delta_point[0];
	std::cout << counter << " The position is:	x: " << tempx << "	y: " << tempy << std::endl;

	if (round(tempx) != x || round(tempy) != y)
	printtrajectory();*/
	while (round(current_point(0)) != target_point(0) || round(current_point(1)) != target_point(1))
	{
		current_point(0) = current_point(0) + target_point(0) / hyp;
		current_point(1) = current_point(1) + target_point(1) / hyp;
		std::cout << " The position is:	x: " << round(current_point(0)) << "	y: " << round(current_point(1)) << std::endl;
		map->setPixel8U(current_point(0), current_point(1), 0);
	}

}

void Robot::move(double enx, double eny, double enrot)
{

	double initial_orientation = getOrientation(initial_trans);
	double target_orientation = std::atan2(eny, enx);

	std::cout << "Initial orientation is: " << initial_orientation << " target orientation is: " << target_orientation << std::endl;

	// begin robot motion 
	rotate(target_orientation - orientation);
	moveahead(enx, eny);
	rotate(enrot - orientation);

}


/*void Robot::printMotionSequence(Point cur_point, Transform motion)
//{
// setup


// w = 1 rad/sec
// calculate step 1 - rotate


// calculate step 2 - motion


// calculate step 3 - rotate


//int sec;
//int x;
//int y;

// Tabel of the movement for the two wheels and the time they move
//std::cout << "| Wheel 1 " << "| Wheel 2 " << "| Time [sec] |" << std::endl;
//std::cout << "Step 1 | " << x << " | " << y << " | " << sec << " | " << std::endl;
//std::cout << "Step 2 | " << x << " | " << y << " | " << sec << " | " << std::endl;
//std::cout << "Step 3 | " << x << " | " << y << " | " << sec << " | " << std::endl;
//}*/


void Robot::calcualteWorkSpace(Transform motion)
{
	// her skal der udregnes et n*m workspace, som opdateres hvergang denne metode bliver kaldt


}


