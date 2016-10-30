#pragma once

#include "Balls_and_bins.h"

//#include <math.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
//#include <ostream>

int main()
{/*
	Balls_and_bins def;

	Balls_and_bins bal(1000000);
	*/
	

	//std::cout << "log(log(100007)) = " << log(log(100007)) << std::endl;

	//std::cout << "log(100007) = " << log(100007) << std::endl;

	//int bins[11] = {0,0,0,0,0,0,0,0,0,0,0};

	Balls_and_bins test;

	std::cout << "Dette er storrelsen po bins vectoren: " << test.bins() << std::endl;
	std::cout << "Radom_number_test: " << test.random_number() << std::endl;

	//std::cout << "TEST " << "" << std::endl;

	std::cout << test.insert_ball();

	system("pause");
	return 0;

}