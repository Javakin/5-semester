#include "Balls_and_bins.h"


Balls_and_bins::Balls_and_bins()
{
	// setup the binvector
	bin_vector.clear();
	bin_vector.resize(DEFOULT_VECTOR_SIZE, 0);


}

Balls_and_bins::Balls_and_bins(int bins)
{
	// setup the bin vector
	bin_vector.clear();
	bin_vector.resize(bins, 0);
	
	
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
