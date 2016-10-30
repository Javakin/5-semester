#pragma once
#include <vector>
#include <iostream>

#define DEFOULT_VECTOR_SIZE		1000000

using namespace std;

class Balls_and_bins
{
public:
	Balls_and_bins();
	Balls_and_bins(int bins);


	~Balls_and_bins();

private:
	vector<int> bin_vector;

};