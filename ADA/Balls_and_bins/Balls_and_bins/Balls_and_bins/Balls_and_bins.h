#pragma once

#include <math.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>

class Balls_and_bins
{
public:
	Balls_and_bins();

	//void Balls_and_bins(int bins, int balls);

	~Balls_and_bins();

	int random_number();

	int bins();

	int insert_ball();

private:
	int x;

	int y;
	std::vector<int> bins_vector;

};