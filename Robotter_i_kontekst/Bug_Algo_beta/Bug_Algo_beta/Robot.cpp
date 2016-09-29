#pragma once

#include <iostream>
#include "Robot.h"
#include "Point.h"
#include "Image.h"
#include "Transform.h"
#include <cmath>

#define PI				3.14159265358979323846 
#define DELTA_PHI		0.02
#define DELTA_DIST		0.1
#define WEEL_DIST		40
#define WEEL_RADIUS		1
#define ROT_SPEED		1


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
	// setup
	new_trans = motion;
	Point p(0, 0);
	current_point = initial_trans.mult(p);
	target_point = motion.mult(current_point);
	current_trans = initial_trans;

	// move robut to target
	move(target_point(0)-current_point(0), target_point(1)-current_point(1), getOrientation(initial_trans.mult(new_trans)));
		
	// update possition transformation
	initial_trans = initial_trans.mult(new_trans);
}

void Robot::moveahead(double aDistance)
{
	// initiate variables
	Transform delta_trans(DELTA_DIST, 0, 0);
	double current_dist = 0;
	Point p(0, 0);

	// move the distance
	while (current_dist < aDistance) {
		current_trans = current_trans.mult(delta_trans);
		current_dist += DELTA_DIST;

		// print point on the image
		printpoint(current_trans);

		// display result - for debugging
		//p = current_trans.mult(p);
		//std::cout << "The location is x: " << p(0) << " \ty: " << p(1) << std::endl;
	}
}

void Robot::rotate(double radians)
{
	// initiate variables	
	Transform delta_trans1(0, 0, DELTA_PHI);
	Transform delta_trans2(0, 0, -DELTA_PHI);

	// if positive rotation rotate counter clockwise
	if (radians > 0)
		while (getOrientation(current_trans) < radians) {
			current_trans = current_trans.mult(delta_trans1);

			// print point on the image
			printpoint(current_trans);

			// display - for debugging
			//std::cout << "The orientation is: " << getOrientation(current_trans) << "\ttarget: " << radians << std::endl;
		}

	// if negative rotation rotate clockwise
	if (radians < 0)
		while (getOrientation(current_trans) > radians ) {
			current_trans = current_trans.mult(delta_trans2);

			// print point on the image
			printpoint(current_trans);

			// display - for debugging
			//std::cout << "The orientation is: " << getOrientation(current_trans) << "\ttarget: " << radians << std::endl;
		}
}

void Robot::printpoint(Transform aMatrix)
{	
	// setup 
	Point p1(0, 0);
	Point p2(0, 0);
	Transform wl(0, WEEL_DIST, 0);
	Transform wr(0, -WEEL_DIST, 0);

	// calculate weellocation
	p1 = aMatrix.mult(wl).mult(p1);
	p2 = aMatrix.mult(wr).mult(p2);

	// paint pixel black
	//std::cout << (int)p1(0) << " " << (int)p1(1) << std::endl;
	//std::cout << (int)p2(0) << " " << (int)p2(1) << std::endl;

	// display the point
	if ((int)p1(0) >= 0 && (int)p1(1)>=0)
		map->setPixel8U((int)p1(0), (int)p1(1), 0);
	if ((int)p2(0) >= 0 && (int)p2(1) >= 0)
		map->setPixel8U((int)p2(0), (int)p2(1), 0);

}
void Robot::calcualteWorkSpace(double ennx, double enny)
{


	if (ennx > lower_lim(0))
		lower_lim(0) = ennx;
	if (enny > lower_lim(1))
		lower_lim(1) = enny;

	if (lower_lim(0) > upppppppppper_lim(0))
		upppppppppper_lim(0) = lower_lim(0);
	if (lower_lim(1) > upppppppppper_lim(1))
		upppppppppper_lim(1) = lower_lim(1);



	std::cout << "The required workspace is: " << " x " << upppppppppper_lim(0) << " y " << upppppppppper_lim(1) << std::endl;
}

void Robot::move(double enx, double eny, double enrot)
{
	double initial_orientation = getOrientation(initial_trans);
	double target_orientation = std::atan2(eny, enx);
	double hyp = sqrt(enx*enx + eny*eny);



	//std::cout << "Step 1: " << std::endl;
	//std::cout << "Initial orientation is: " << initial_orientation << " target orientation is: " << target_orientation << std::endl;

	

	// begin robot motion 
	rotate(target_orientation);
	moveahead(hyp);
	rotate(enrot);
	calcualteWorkSpace(enx, eny);

	// display
	double sec1 = abs((target_orientation - initial_orientation) * WEEL_DIST /
						(WEEL_RADIUS * (ROT_SPEED * 2)));

	double sec3 = abs((enrot - target_orientation)* WEEL_DIST /
						(WEEL_RADIUS * (ROT_SPEED * 2)));


	int x = ROT_SPEED;
	int y = ROT_SPEED;

	if (target_orientation > initial_orientation)
		x *= -1;
	if (target_orientation < enrot)
		y *= -1;

	
	// Tabel of the movement for the two wheels and the time they move
	std::cout << "\t| Wheel L [rad/sec] " << "| Wheel R [rad/sec] " << "| Time [sec] |" << std::endl;

	std::cout << "Step 1 | \t" << x << " \t|\t" << -x << " \t|\t " << sec1 << " \t|\t " << std::endl;

	std::cout << "Step 2 | \t" << ROT_SPEED << " \t|\t " << ROT_SPEED << "\t|\t " << hyp/(WEEL_RADIUS * ROT_SPEED) << " | " << std::endl;

	std::cout << "Step 3 | \t" << y << "\t|\t " << -y << "\t|\t" << sec3 << " \t|\t " << std::endl;
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


//void Robot::calcualteWorkSpace(double enx, double eny)
//{
//	std::cout << "test" << std::endl;
//	// her skal der udregnes et n*m workspace, som opdateres hvergang denne metode bliver kaldt
//
//
//}


