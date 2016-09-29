#pragma once

#include <iostream>
#include "Robot.h"
#include "Point.h"
#include "Image.h"
#include "Transform.h"
#include <cmath>

#define PI 3.14159265358979323846 
#define DELTA_PHI 0.02
#define DELTA_DIST 1


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

		// display result
		p = current_trans.mult(p);
		std::cout << "The location is x: " << p(0) << " \ty: " << p(1) << std::endl;
	}
	

	printpoint(current_trans);
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
			std::cout << "The orientation is: " << getOrientation(current_trans) << "\ttarget: " << radians << std::endl;
		}

	// if negative rotation rotate clockwise
	if (radians < 0)
		while (getOrientation(current_trans) > radians ) {
			current_trans = current_trans.mult(delta_trans2);
			std::cout << "The orientation is: " << getOrientation(current_trans) << "\ttarget: " << radians << std::endl;
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

void Robot::calcualteWorkSpace(double ennx, double enny)
{
	//double temp_x = 0;
	//double temp_y = 0;
		
	//if (enh > temp_x)
	//	temp_x = enh;
	//if (enb > temp_y)
	//	temp_y = enb;

	//std::cout << "The required workspace is: " << " x " << temp_x << " y " << temp_y << std::endl;
	//std::cout << temp_x << std::endl;
	//std::cout << temp_y << std::endl;
	// her skal der udregnes et n*m workspace, som opdateres hvergang denne metode bliver kaldt

	//lower_lim(0) = 0;
	//lower_lim(1) = 0;
	//upppppppppper_lim(0) = 0;
	//upppppppppper_lim(1) = 0;

	if (ennx > lower_lim(0))
		lower_lim(0) = ennx;
	if (enny > lower_lim(1))
		lower_lim(1) = enny;

	if (lower_lim(0) > upppppppppper_lim(0))
		upppppppppper_lim(0) = lower_lim(0);
	if (lower_lim(1) > upppppppppper_lim(1))
		upppppppppper_lim(1) = lower_lim(1);


	//upppppppppper_lim(0) = 0;
	//upppppppppper_lim(1) = 0;

	//if (ennx > upppppppppper_lim(0))
	//	lower_lim(0) = enh;
	std::cout << "The required workspace is: " <<" x " << upppppppppper_lim(0) << " y " << upppppppppper_lim(1) << std::endl;
}


	double initial_orientation = getOrientation(initial_trans);
	double target_orientation = std::atan2(eny, enx);
	double hyp = sqrt(enx*enx + eny*eny);

	std::cout << "Step 1: " << std::endl;
	std::cout << "Initial orientation is: " << initial_orientation << " target orientation is: " << target_orientation << std::endl;

	// begin robot motion 
	rotate(target_orientation);
	moveahead(hyp);
	rotate(enrot);

	calcualteWorkSpace(enx, eny);
	
	std::cout << "test222222" << std::endl;
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


