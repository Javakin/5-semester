#include "Balls_and_bins.h"


Balls_and_bins::Balls_and_bins()
{
	// setup the binvector
	bin_vector.clear();
	bin_vector.resize(DEFOULT_VECTOR_SIZE, 0);

	// initiate rand using the current time as seed
	srand(time(NULL));

}

Balls_and_bins::Balls_and_bins(int bins)
{
	// setup the bin vector
	bin_vector.clear();
	bin_vector.resize(bins, 0);

	// initiate rand using the current time as seed
	srand(time(NULL));
	
}

void Balls_and_bins::addBalls1(int num_of_balls)
{
	for (int i = 0; i < num_of_balls; i++)
	{
		bin_vector[randPos()]++;
	}
}

void Balls_and_bins::addBalls2(int num_of_balls)
{
	unsigned long long val1 = 0;
	unsigned long long val2 = 0;

	for (int i = 0; i < num_of_balls; i++)
	{
		val1 = randPos();
		val2 = randPos();

		// by the power of two choices, i chose thee
		bin_vector[val1] < bin_vector[val2] ? bin_vector[val1]++ : bin_vector[val2]++;
	}
}

void Balls_and_bins::print_balls_and_bins()
{
	// setup
	vector<int> num_of_bals;

	// make the frequency table
	for (int bin : bin_vector)
	{
		// resize if needed
		while (bin >= num_of_bals.size())
			num_of_bals.push_back(0);

		num_of_bals[bin]++;
	}

	// display the frequency table
	cout << "Display Frequency table:\n";
	for (unsigned i = 0; i < num_of_bals.size(); i++)
		cout << i << " --> " << num_of_bals[i] << endl;
		
}

Balls_and_bins::~Balls_and_bins()
{
}

unsigned long long int Balls_and_bins::randPos()
{
	return  rd() % bin_vector.size();
}
