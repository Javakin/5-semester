#pragma once

#include <iostream>
#include "Robot.h"
#include "Point.h"
#include "Image.h"
#include "Transform.h"


Robot::Robot()
{
	Point p(0,0);
	current_point = p;
	//current_theta = 0;
	map = NULL;
}

Robot::Robot(rw::sensor::Image * aMap)
{
	Point p(0, 0);
	current_point = p;
	//current_theta = 0;
	map = aMap;
}


Robot::Robot(rw::sensor::Image* aMap, double x, double y, double theta)
{
	Point p(x, y);
	current_point = p;
	//current_theta = theta;
	map = aMap;
}



Robot::~Robot()
{

}

//void Robot::goTo(double x, double y, double theta)


void Robot::goTo(Transform motion)
{
	// set target
	target_point = motion.mult(current_point);

	// move robit to target

		// print motoin


	// Target has been reatched - calculate
	std::cout << "done" << std::endl;
}

void Robot::moveahead(double enxafstand, double enyafstand)
{
	tempx = x;
	tempy = y;
	x += enxafstand;
	y += enyafstand;
	hyp = sqrt(enxafstand*enxafstand + enyafstand*enyafstand);
	deltax = enxafstand / hyp;
	deltay = enyafstand / hyp;
	std::cout << "Lenght is " << hyp << std::endl;
	std::cout << "DeltaX is  " << deltax << std::endl;

	printtrajectory();
}


void Robot::rotate(double degrees)
{
	if (degrees > 0)
		for (int i = 0; i < degrees; i++) {
			orientation++;
			if (orientation > 359) {
				orientation = 0;
			}
			std::cout << "The orientation is: " << orientation << " degrees" << std::endl;
		}
	if (degrees < 0)
		for (int i = 0; i > degrees; i--) {
			orientation--;
			if (orientation < 1) {
				orientation = 360;
			}
			std::cout << "The orientation is: " << orientation << " degrees" << std::endl;
		}
}

void Robot::printtrajectory()
{
	tempx += deltax;
	tempy += deltay;
	std::cout << counter << " The position is:	x: " << tempx << "	y: " << tempy << std::endl;

	if (round(tempx) != x || round(tempy) != y)
		printtrajectory();
}

void Robot::move(double enx, double eny, double enrot)
{
	double save_orientation = orientation;
	std::cout << atan(eny / enx) * 180 / 3.14159265358979323846;
	double temp_Orientation = atan(eny / enx) * 180 / 3.14159265358979323846;
	if (enx == 0)
		temp_Orientation = 90;
	if (eny == 0)
		temp_Orientation = 0;
	if (enx < 0 && eny > 0)
		temp_Orientation = 90 + atan(eny / -enx) * 180 / 3.14159265358979323846;
	if (enx < 0 && eny < 0)
		temp_Orientation = 180 + atan(-eny / -enx) * 180 / 3.14159265358979323846;
	if (eny < 0 && enx > 0)
		temp_Orientation = 270 + atan(-eny / enx) * 180 / 3.14159265358979323846;

	std::cout << "Current orientation is: " << orientation << " temp orientation is: " << temp_Orientation << std::endl;

	rotate(temp_Orientation - orientation);
	moveahead(enx, eny);
	rotate(save_orientation - orientation);

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

/*void Robot::moveahead(int enafstand)
{
	
	/*tempx = x;
	tempy = y;
	x = x + (enafstand * cos(theta * 3.14159265358979323846 / 180));
	y = y + (enafstand * sin(theta * 3.14159265358979323846 / 180));
	printtrajectory();
	Point
}*/
