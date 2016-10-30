#include "Balls_and_bins.h"


Balls_and_bins::Balls_and_bins()
{
	//// setup the binvector
	//bin_vector.clear();
	//bin_vector.resize(DEFOULT_VECTOR_SIZE, 0);


}
/*
Balls_and_bins::Balls_and_bins(int bins)
{
	// setup the bin vector
	bin_vector.clear();
	bin_vector.resize(bins, 0);
	
	
}
*/
//void Balls_and_bins::Balls_and_bins(int bins, int balls)
//{
//	int binss = bins;
//	//std::cout << binss << std::endl;
//	return binss;
//}

/*
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
*/
Balls_and_bins::~Balls_and_bins()
{
}

int Balls_and_bins::random_number()
{
	std::cout << "Insert number of balls" << std::endl;
	std::cin >> x;
	//int i, j;
	int j;
	srand((unsigned)time(NULL));

	for (int i = 0; i < x; i++)
	{
		j = rand() % y;
		ball_pos_vector.push_back(j);
		//std::cout << "Detter er de random verdier " << j << std::endl;
	}
	//j = rand() % y;
	//std::cout << "test 1: " << j << std::endl;
	//std::cout << "test 2: " << rand() % y << std::endl;
	return j;
}

int Balls_and_bins::bins()
{
	std::cout << "Insert number of bins" << std::endl;
	std::cin >> y;

	/*
	//std::vector<int> bins_vector(y);
	//std::cout << bins_vector.size() << std::endl;
	*/
	bins_vector.resize(y,0);
	x = bins_vector.size();
	//std::cout << "Dette er verdien po plads 2 i vectoren " << bins_vector.at(2) << std::endl;
	return x;
}

int Balls_and_bins::insert_ball()
{
	std::cout << "Test af 'insert_ball()' " << bins_vector.at(3) << std::endl;
	for (unsigned int i = 0; i < bins_vector.size(); i++)
	{
		//std::cout << "Random number in insert ball: " << random_number() << std::endl;
		//std::cout << "Value of ball_pos_vector on pos " << i << ": " << ball_pos_vector[i] << std::endl;
		//std::cout << "Value of bins_vector on pos " << i << ": " << bins_vector[i] << std::endl;
	}

	for (unsigned int i = 0; i < ball_pos_vector.size(); ++i)
	{
		bins_vector[ball_pos_vector[i]]++;
		//std::cout << "Number of balls in each bin " << i << ": " << bins_vector[i] << std::endl;
		//std::cout << ball_pos_vector[i] << std::endl;
	}


	//bins_vector[3] = 5;
	/*for (int i = 0; i < ; i++)
	{

	}*/
	std::vector<int>::iterator Iter;
	for (Iter = bins_vector.begin(); Iter != bins_vector.end(); Iter++)
		std::cout << *Iter << " ";
	//std::cout << std::endl;
	//int result = std::count(bins_vector.begin(), bins_vector.end(), 2);
	//std::cout << "Number of 2 in the vector is: " << result << std::endl;
	for (unsigned int i = 0; i < bins_vector.size(); i++)
	{
		int result = std::count(bins_vector.begin(), bins_vector.end(), i);
		std::cout << "Number of balls in bin "<< i << " is: " << result << std::endl;

		/*int result = std::count(bins_vector.begin(), bins_vector.end(), 2);
		std::cout << "Number of 2 in the vector"*/

		//int mycount = std::count(bins_vector.begin(), bins_vector.end(), i);
		//std::cout << "i bin " << i << " er der " << mycount << " bolte" << std::endl;
		
		//std::cout << "0 appears " << mycount << " times.\n";

		
	}/*
	int mycount1 = std::count(bins_vector.begin(), bins_vector.end(), 1);
	std::cout << "i bin " << "1" << " er der " << mycount1 << " bolte" << std::endl;
	int mycount2 = std::count(bins_vector.begin(), bins_vector.end(), 1);
	std::cout << "i bin " << "2" << " er der " << mycount2 << " bolte" << std::endl;
	int mycount3 = std::count(bins_vector.begin(), bins_vector.end(), 1);
	std::cout << "i bin " << "3" << " er der " << mycount3 << " bolte" << std::endl;*/
	//std::cout << std::count(bins_vector, bins_vector + 10, 2);
	//std::cout << "Number of balls in each bin " << i << ": " << bins_vector[i] << std::endl;

	std::cout << "Verdi af 3 position i vector: " << bins_vector[3] << std::endl;


	return 0;
}
