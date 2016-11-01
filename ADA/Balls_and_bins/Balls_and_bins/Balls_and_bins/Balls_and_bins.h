#pragma once

#include <math.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <algorithm>

class Balls_and_bins
{
public:
	Balls_and_bins();

	//void Balls_and_bins(int bins, int balls);

	~Balls_and_bins();

	int random_number();

	int bins();

	int insert_ball();

	int power_of_two_choices();

private:
	int x; // Number of balls
	int y; // Number of bins
	
	std::vector<int> bins_vector;
	std::vector<int> ball_pos_vector;
	std::vector<int> two_choices;
	//std::vector<int> ball_in_bins;

};