#pragma once

#include "Balls_and_bins.h"

//#include <math.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
//#include <ostream>

int main()
{
	Balls_and_bins test;
	test.bins();
	test.random_number();
	test.insert_ball();
	//test.power_of_two_choices();
	//std::cout << "Dette er storrelsen po bins vectoren: " << test.bins() << std::endl;
	//std::cout << "Radom_number_test: " << test.random_number() << std::endl;

	////std::cout << "TEST " << "" << std::endl;

	//std::cout << test.insert_ball();

	system("pause");
	return 0;

}