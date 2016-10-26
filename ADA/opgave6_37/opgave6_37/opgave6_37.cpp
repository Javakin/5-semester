// opgave6_37.cpp : Defines the entry point for the console application.
// solving the exercise in the ADA book
//

#include <iostream>
#include <vector>
#include "Placer.h"

using namespace std;


int main()
{
	Placer opgA(5);

	opgA.first_match(2);
	opgA.first_match(2);
	opgA.first_match(5);
	opgA.first_match(5);

    return 0;
}

