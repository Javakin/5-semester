#include "Balls_and_bins.h"


Balls_and_bins::Balls_and_bins()
{
	// setup the binvector
	bin_vector.clear();
	bin_vector.resize(DEFOULT_VECTOR_SIZE, 0);

	cout << "size: " << bin_vector.size() << endl;
}

Balls_and_bins::Balls_and_bins(int bins)
{
	// setup the bin vector
	bin_vector.clear();
	bin_vector.resize(bins, 0);
	
	cout << "size: " << bin_vector.size() << endl;
}


Balls_and_bins::~Balls_and_bins()
{
}
