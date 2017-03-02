#pragma once
#include <vector>
#include <iostream>
#include <stdlib.h>				// srand, rand
#include <time.h>				// time seed for srand function
#include <random>

#define DEFOULT_VECTOR_SIZE		100

using namespace std;

class Balls_and_bins
{
public:
	Balls_and_bins();
	Balls_and_bins(int bins);

	void addBalls1(int num_of_balls);
	void addBalls2(int num_of_balls);
	void print_balls_and_bins();

	~Balls_and_bins();

private:
	unsigned long long int randPos();
	vector<int> bin_vector;
	std::random_device rd;
};