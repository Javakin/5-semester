#include "stdafx.h"
#include "Sorting_class.h"


Sorting_class::Sorting_class()
{
}

void Sorting_class::nSquared()
{
	int k = 10;
	for (int i = 0; i < test.size(); i++)
	{
		for (int b = 0; b < test.size(); b++)
		{
			if (i == b) continue;

			if (test.at(i) + test.at(b) == k)
			{
				std::cout << "Element " << i + 1 << " is: " << test.at(i) << " and element " << b + 1 << " is: " << test.at(b) << ". Together they give: " << test.at(i)+test.at(b) << std::endl;
			}

		}
	}
}

void Sorting_class::Quicksort()
{
	//int i = left;
	//int j = right;

}

void Sorting_class::truefalse()
{
	std::string a = "false";
	int spot = 0;
	std::string tempstring;
	/*ret = strcmp(stringvector(i)*/
	for (int i = 0; i < stringvector.size(); i++)
	{
		if (stringvector.at(i).compare(a) == 0)
		{
			tempstring = stringvector.at(spot);
			stringvector.at(spot) = "false";
			stringvector.at(i) = tempstring;
			spot++;
		}
	}
	for (int i = 0; i < stringvector.size(); i++)
	{
		std::cout << stringvector.at(i);
	}
}


Sorting_class::~Sorting_class()
{
}
