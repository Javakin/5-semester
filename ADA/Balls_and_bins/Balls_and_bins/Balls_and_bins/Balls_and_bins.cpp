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

//void Balls_and_bins::Balls_and_bins(int bins, int balls)
//{
//	int binss = bins;
//	//std::cout << binss << std::endl;
//	return binss;
//}


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

int Balls_and_bins::random_number()
{
	//int i, j;
	int j;
	srand((unsigned)time(NULL));

	for (int i = 0; i < 10; i++)
	{
		j = rand() % y;
		std::cout << "Detter er de random verdier " << j << std::endl;
	}
	//j = rand() % y;
	return j;
}

int Balls_and_bins::bins()
{
	std::cin >> y;
	//std::vector<int> bins_vector(y);
	//std::cout << bins_vector.size() << std::endl;
	bins_vector.resize(y,0);
	x = bins_vector.size();
	//std::cout << "Dette er verdien po plads 2 i vectoren " << bins_vector.at(2) << std::endl;
	return x;
}

int Balls_and_bins::insert_ball()
{
	std::cout << "Test af 'insert_ball()' " << bins_vector.at(3) << std::endl;
	
	bins_vector[3] = 5;

	std::cout << bins_vector[3] << std::endl;


	return 0;
}
