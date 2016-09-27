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
	current_theta = 0;
	map = NULL;
}

Robot::Robot(rw::sensor::Image * aMap)
{

}

Robot::Robot(rw::sensor::Image* aMap, double x, double y, double theta)
{
	Point p(0, 0);
	current_point = p;
	current_theta = 0;
	map = aMap;
}

Robot::Robot(rw::sensor::Image* aMap, double x, double y, double theta)
{
	Point p(x, y);
	current_point = p;
	current_theta = theta;
	map = aMap;
}



Robot::~Robot()
{

}

//void Robot::goTo(double x, double y, double theta)
void Robot::goTo(Transform motion)
{

}

void Robot::goTo(Transform motion)
{
	

	// print motoin
	printMotionSequence(current_point, motion);

	// trace route
	traceRoute(motion);

	// calculate workspace
	std::cout << calcualteWorkSpace(motion) << std::endl;
}

void Robot::printMotionSequence(Point cur_point, Transform motion)
{
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
}

void Robot::traceRoute(Transform motion)
{
	std::cout << "her" << std::endl;
}

int Robot::calcualteWorkSpace(Transform motion)
{
	return 0;
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
