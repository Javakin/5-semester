#include "Robot.h"
#include <math.h>

Robot::Robot()
{
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
	cout << "Lenght is " << hyp << endl;
	cout << "DeltaX is  " << deltax << endl;

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
		cout << "The orientation is: " << orientation << " degrees" << endl;
	}
	if (degrees < 0)
		for (int i = 0; i > degrees; i--) {
			orientation--;
			if (orientation < 1) {
				orientation = 360;
			}
			cout << "The orientation is: " << orientation << " degrees" << endl;
		}
}


void Robot::printtrajectory()
{
	tempx += deltax;
	tempy += deltay;
	cout << counter << " The position is:	x: " << tempx << "	y: " << tempy << endl;

	if (round(tempx) != x || round(tempy) != y)
		printtrajectory();
}

void Robot::move(double enx, double eny, double enrot)
{
	double save_orientation = orientation;
	cout << atan(eny / enx) * 180 / 3.14159265358979323846;
	double temp_Orientation = atan(eny / enx) * 180 / 3.14159265358979323846;
	if (enx == 0)
		temp_Orientation = 90;
	if (eny == 0)
		temp_Orientation = 0;
	if (enx < 0 && eny > 0)
		temp_Orientation = 90+atan(eny/-enx) * 180/ 3.14159265358979323846;
	if (enx < 0 && eny < 0)
		temp_Orientation = 180 + atan(-eny / -enx) * 180 / 3.14159265358979323846;
	if (eny < 0 && enx > 0)
		temp_Orientation = 270 + atan(-eny / enx) * 180 / 3.14159265358979323846;

	cout << "Current orientation is: " << orientation << " temp orientation is: " << temp_Orientation << endl;
		
		rotate(temp_Orientation - orientation);
		moveahead(enx,eny);
		rotate(save_orientation - orientation);

}

Robot::~Robot()
{
}