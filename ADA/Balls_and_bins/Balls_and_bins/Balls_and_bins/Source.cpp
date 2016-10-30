#pragma once

#include "Balls_and_bins.h"

//#include <math.h>
#include <iostream>
//#include <stdlib.h>
//#include <time.h>

int main()
{
	Balls_and_bins def;

	Balls_and_bins bal(1000000);

	def.print_balls_and_bins();
	bal.print_balls_and_bins();

	/*std::cout << "log(log(100007)) = " << log(log(100007)) << std::endl;

	std::cout << "log(100007) = " << log(100007) << std::endl;

	int bins[11] = {0,0,0,0,0,0,0,0,0,0,0};

	
	std::cout << bins[1] << std::endl;
	int i, j;
	srand((unsigned)time(NULL));
	
	for (int i = 0; i < 10; i++)
	{
		j = rand() % 12;
		std::cout << j << std::endl;
	}
	*/
	




	system("pause");
	return 0;

}