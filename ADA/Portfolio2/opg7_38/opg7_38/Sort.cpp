
#include "stdafx.h"
#include "Sort.h"

// general code

Sort::Sort()
{
}

Sort::~Sort()
{
}

void Sort::vMergSort(std::vector<int>& vUnsortedList)
{
	std::vector<int> vWorkList(vUnsortedList);
	
	// sort data from vWorkinglist into vUnsortedlist
	vSplitMergSort(vWorkList, vUnsortedList, 0, vUnsortedList.size());
}

void Sort::nSquared()
{
	int q = 0;
	int k = 10;
	for (int i = 0; i < test.size(); i++)
	{
		for (int b = 0; b < test.size(); b++)
		{
			if (i == b) continue;

			if (test.at(i) + test.at(b) == k)
			{	
				q = 1;
				// For debugging
				//std::cout << "Element " << i + 1 << " is: " << test.at(i) << " and element " << b + 1 << " is: " << test.at(b) << ". Together they give: " << test.at(i) + test.at(b) << std::endl;
			}

		}
	}
	if (q == 1)
	{
		std::cout << "There are two or more elements that when summed gives " << k << std::endl;
	}
}

void Sort::Mergesort()
{
	/*std::vector<int> b;
	vMergSort(test);*/

	//std::cout << vMergSort(test).at(1)

	int target = 10;
	int startint = 2;
	int targetint = target - startint;
	int h = 1;

	if (test.at(h) != targetint && h < test.size())
	{
		h++;
	}
	if (test.at(h) == targetint)
	{
		std::cout << "There are a combination of tow numbers that gives" << target;
	}

	std::cout << "debrug";
	/*while (test.at(h) != targetint && h < test.size())
	{
		h++;
	}*/


}

//void Sort::Mergesort()
//{
//
//}
//
//void Sort::truefalse()
//{
//	//std::string a = "false";
//	//int spot = 0;
//	//std::string tempstring;
//
//	//for (int i = 0; i < stringvector.size(); i++)
//	//{
//	//	if (stringvector.at(i).compare(a) == 0)
//	//	{
//	//		tempstring = stringvector.at(spot);
//	//		stringvector.at(spot) = "false";
//	//		stringvector.at(i) = tempstring;
//	//		spot++;
//	//	}
//	//}
//	//for (int i = 0; i < stringvector.size(); i++)
//	//{
//	//	std::cout << stringvector.at(i);
//	//}
//}

void Sort::vSplitMergSort(std::vector<int>& vSource, std::vector<int>& vResoult, unsigned int uiBegin, unsigned int uiEnd)
{
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// sort vResult using vSource as source
	// iBegin is inclusive; iEnd is exclusive
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// base case list size 0 or 1 is conciderd sorted
	if (uiEnd - uiBegin < 2)
		return;
	
	// splitting and sorting the sublists
	unsigned int uiMiddle = (uiBegin + uiEnd) / 2;

	vSplitMergSort(vResoult, vSource, uiBegin, uiMiddle);
	vSplitMergSort(vResoult, vSource, uiMiddle, uiEnd);

	// merg lists together once again
	vMerg( vSource, vResoult, uiBegin, uiMiddle, uiEnd);
}

void Sort::vMerg(std::vector<int>& vSource, std::vector<int>& vResoult, unsigned int uiBegin, unsigned int uiMiddle, unsigned int uiEnd)
{
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Left source half is  vSource [ iBegin:iMiddle-1]
	// Right source half is vSource [ iMiddle:iEnd-1  ]
	// Result is			vResoutl[ iBegin:iEnd-1   ]
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	// setup
	unsigned int i = uiBegin;
	unsigned int j = uiMiddle;

	// for every cell in the sources
	for (unsigned int k = uiBegin; k < uiEnd; k++)
	{
		if (i < uiMiddle && ((j >= uiEnd) || (vSource[i] <= vSource[j])))
		{
			// left side is selected
			vResoult[k] = vSource[i];
			i++;
		}
		else
		{
			// right side is selected
			vResoult[k] = vSource[j];
			j++;
		}

	}
}


void Sort::truefalse()
{
	std::string a = "false";
	int spot = 0;
	std::string tempstring;

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
		std::cout << stringvector.at(i) << " ";
	}
}

// application specific code
void Sort::vMergSort(std::vector<edge>& vUnsortedList)
{
	std::vector<edge> vWorkList(vUnsortedList);

	// sort data from vWorkinglist into vUnsortedlist
	vSplitMergSort(vWorkList, vUnsortedList, 0, vUnsortedList.size());
}

void Sort::vSplitMergSort(std::vector<edge>& vSource, std::vector<edge>& vResoult, unsigned int uiBegin, unsigned int uiEnd)
{
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// sort vResult using vSource as source
	// iBegin is inclusive; iEnd is exclusive
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// base case list size 0 or 1 is conciderd sorted
	if (uiEnd - uiBegin < 2)
		return;

	// splitting and sorting the sublists
	unsigned int uiMiddle = (uiBegin + uiEnd) / 2;

	vSplitMergSort(vResoult, vSource, uiBegin, uiMiddle);
	vSplitMergSort(vResoult, vSource, uiMiddle, uiEnd);

	// merg lists together once again
	vMerg(vSource, vResoult, uiBegin, uiMiddle, uiEnd);
}

void Sort::vMerg(std::vector<edge>& vSource, std::vector<edge>& vResoult, unsigned int uiBegin, unsigned int uiMiddle, unsigned int uiEnd)
{
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Left source half is  vSource [ iBegin:iMiddle-1]
	// Right source half is vSource [ iMiddle:iEnd-1  ]
	// Result is			vResoutl[ iBegin:iEnd-1   ]
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// setup
	unsigned int i = uiBegin;
	unsigned int j = uiMiddle;

	// for every cell in the sources
	for (unsigned int k = uiBegin; k < uiEnd; k++)
	{
		if (i < uiMiddle && ((j >= uiEnd) || (vSource[i].angle <= vSource[j].angle)))
		{
			// left side is selected
			vResoult[k] = vSource[i];
			i++;
		}
		else
		{
			// right side is selected
			vResoult[k] = vSource[j];
			j++;
		}

	}
}
