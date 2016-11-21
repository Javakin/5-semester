#include "stdafx.h"
#include "Sort.h"


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

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// sort vResult using vSource as source
// iBegin is inclusive; iEnd is exclusive
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Sort::vSplitMergSort(std::vector<int>& vSource, std::vector<int>& vResoult, unsigned int uiBegin, unsigned int uiEnd)
{
	// base case list size 0 or 1 is conciderd sorted
	if (uiEnd - uiBegin < 2)
		return;

	// splitting and sorting the sublists
	unsigned int uiMiddle = (uiBegin + uiEnd) / 2;

	vSplitMergSort(vResoult, vSource, uiBegin, uiMiddle - 1);
	vSplitMergSort(vResoult, vSource, uiMiddle, uiEnd - 1);

	// merg lists together once again
	vMerg( vSource, vResoult, uiBegin, uiMiddle, uiEnd);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Left source half is  vSource [ iBegin:iMiddle-1]
// Right source half is vSource [iMiddle:iEnd-1   ]
// Result is			vResoutl[ iBegin:iEnd-1   ]
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Sort::vMerg(std::vector<int>& vSource, std::vector<int>& vResoult, unsigned int uiBegin, unsigned int uiMiddle, unsigned int uiEnd)
{
	// setup
	unsigned int i = uiBegin;
	unsigned int j = uiMiddle;

	//

}


