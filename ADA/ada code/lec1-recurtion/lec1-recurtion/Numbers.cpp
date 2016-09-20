#include "Numbers.h"
#include <iostream>


Numbers::Numbers()
{
}

int Numbers::NatNumSum(int number)
{
	if (number != 0) {
		return number + NatNumSum(number - 1);
	}
	else {
		return 0;
	}
}



Numbers::~Numbers()
{
}
