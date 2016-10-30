#pragma once
#include <vector>
#include <iostream>

#define DEFOULT_VECTOR_SIZE		100

using namespace std;

class Balls_and_bins
{
public:
	Balls_and_bins();
	Balls_and_bins(int bins);

	void addBalls(int num_of_balls);
	void print_balls_and_bins();

	~Balls_and_bins();

private:
	vector<int> bin_vector;

};