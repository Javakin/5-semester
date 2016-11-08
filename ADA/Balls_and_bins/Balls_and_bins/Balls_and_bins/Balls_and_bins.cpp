#include "Balls_and_bins.h"


Balls_and_bins::Balls_and_bins()
{
}
Balls_and_bins::~Balls_and_bins()
{
}

int Balls_and_bins::random_number()
{
	std::cout << "Insert number of balls" << std::endl;
	std::cin >> x;
	int j;
	srand((unsigned)time(NULL));

	for (int i = 0; i < x; i++)
	{
		j = rand() % y;
		ball_pos_vector.push_back(j);
	}
	return j;
}

int Balls_and_bins::bins()
{
	std::cout << "Insert number of bins" << std::endl;
	std::cin >> y;

	two_choices.resize(y, 0);
	bins_vector.resize(y,0);
	x = bins_vector.size();
	return x;
}

int Balls_and_bins::insert_ball()
{

	for (unsigned int i = 0; i < ball_pos_vector.size(); ++i)
	{
		bins_vector[ball_pos_vector[i]]++;
	}

	//// Bruges til debugging
	//std::vector <int>::iterator Iter;
	////std::cout << "Content of bins_vector: ";
	//for (Iter = bins_vector.begin(); Iter != bins_vector.end(); Iter++)
	//	std::cout << *Iter << " ";
	//std::cout << std::endl;

	for (unsigned int i = 0; i < ball_pos_vector.size(); i++)
	{
		int result = std::count(bins_vector.begin(), bins_vector.end(), i);
		if (0 < result)
		{
			std::cout << "There are " << result << " bins with " << i <<" balls in" << std::endl;
		}
	}
	return 0;
}

int Balls_and_bins::power_of_two_choices()
{
	for (unsigned int i = 0; i < ball_pos_vector.size(); i++)
	{
		//two_choices[1]++;
		int l = rand() % y;
		int k = rand() % y;

		if (two_choices[l] <= two_choices[k])
		{
			two_choices[l]++;
		}
		else if (two_choices[l] > two_choices[k])
		{
			two_choices[k]++;
		}
	}
	std::cout << std::endl << "This is power of two choices" << std::endl;
	for (unsigned int i = 0; i < ball_pos_vector.size(); i++)
	{
		int result2 = std::count(two_choices.begin(), two_choices.end(), i);
		if (0 < result2)
		{
			std::cout << "There are " << result2 << " bins with " << i << " balls in" << std::endl;
		}
	}
	/*for (unsigned int i = 0; i < ball_pos_vector.size(); i++)
	{
		if (i < ball_pos_vector.size()-1 && i > 1)
		{
			if (two_choices[ball_pos_vector[i]-1] < two_choices[ball_pos_vector[i]])
			{
				two_choices[ball_pos_vector[i]-1]++;
			}
			else
			{
				two_choices[ball_pos_vector[i]]++;
			}
		}
	}*/

/*
	// Bruges til debugging
	std::vector <int>::iterator Iter2;
	std::cout << "Content of two_choices: ";
	for (Iter2 = two_choices.begin(); Iter2 != two_choices.end(); Iter2++)
		std::cout << *Iter2 << " ";
	std::cout << std::endl;
*/

/*	for (unsigned int i = 0; i < ball_pos_vector.size(); i++)
	{
		int result2 = std::count(two_choices.begin(), two_choices.end(), i);
		if (0 < result2)
		{
			std::cout << "There are " << result2 << " bins with balls " << i << " in" << std::endl;
		}
	}
*/
	return 0;
}
