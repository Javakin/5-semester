#pragma once

#include "Balls_and_bins.h"

//#include <math.h>
#include <iostream>
//#include <stdlib.h>
//#include <time.h>

int main()
{
	while (1)
	{
		int n;
		cout << "Write number:\n";
		cin >> n;

		Balls_and_bins bal1(n);
		Balls_and_bins bal2(n);

		bal1.addBalls1(n);
		bal2.addBalls2(n);

		bal1.print_balls_and_bins();
		bal2.print_balls_and_bins();
	}

	system("pause");
	return 0;

}