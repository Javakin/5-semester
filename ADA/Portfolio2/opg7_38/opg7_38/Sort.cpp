
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

bool Sort::findInt(std::vector<int> vSortedList, int aVal)
{
	unsigned int a = 0;							// a is inclusive
	unsigned int b = vSortedList.size();		// b is exclusive
	unsigned int mid = 0;							// mid is exclusive 

	while (b - a > 1)
	{
		// calculate midpoint
		mid = (a + b) / 2;

		// is the goal reached?
		if (vSortedList[mid] == aVal)
			return 1;

		// if no now what?
		(vSortedList[mid] > aVal) ? b = mid : a = mid;
	}

	return 0;
}

bool Sort::nSquared(std::vector<int> vUnsortedList, int k)
{
	int q = 0;
	for (int i = 0; i < vUnsortedList.size(); i++)			// O(N)
	{
		for (int b = 0; b < vUnsortedList.size(); b++)		// O(N)
		{
			if (vUnsortedList.at(i) + vUnsortedList.at(b) == k)
			{	
				q = 1;
				// For debugging
				//std::cout << "Element " << i + 1 << " is: " << test.at(i) << " and element " << b + 1 << " is: " << test.at(b) << ". Together they give: " << test.at(i) + test.at(b) << std::endl;
			}
		}
	}
	
	(q) ? 
		std::cout << "There are two or more elements that when summed gives " << k << std::endl :
		std::cout << "There are no elements that when summed gives " << k << std::endl;
	
	return (bool)q;
}

bool Sort::nLogN(std::vector<int> vUnsortedList, int k)
{
	// sort list											// O(Nlog(N))
	vMergSort(vUnsortedList);		

	for (int i = 0; i < vUnsortedList.size(); i++)			// O(N)
	{
		// calculate value to find
		int targetint = k - vUnsortedList[i];

		// search for the value
		if (findInt(vUnsortedList, targetint))
			return 1;
	}

	return 0;
}

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

void Sort::truefalse(std::vector<std::string>  & vUnsortedList)
{

	std::string a = "false";
	int spot = 0;
	std::string tempstring;

	for (int i = 0; i < vUnsortedList.size(); i++)
	{
		if (vUnsortedList.at(i).compare(a) == 0)
		{
			tempstring = vUnsortedList.at(spot);
			vUnsortedList.at(spot) = "false";
			vUnsortedList.at(i) = tempstring;
			spot++;
		}
	}
	for (int i = 0; i < vUnsortedList.size(); i++)
	{
		std::cout << vUnsortedList.at(i) << " ";
	}
	std::cout << std::endl;
}