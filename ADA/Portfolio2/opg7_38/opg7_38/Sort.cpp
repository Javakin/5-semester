
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
