#pragma once

#include "Balls_and_bins.h"

#include <math.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>

int main()
{
	

	std::cout << "log(log(100007)) = " << log(log(100007)) << std::endl;

	std::cout << "log(100007) = " << log(100007) << std::endl;

	int bins[11] = {0,0,0,0,0,0,0,0,0,0,0};

	std::cout << bins[1] << std::endl;

	srand(time(NULL));
	int x = rand() % 10;
	std::cout << x << std::endl;



	return 0;

}