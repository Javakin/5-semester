#include "CirQueue.h"
#include <iostream>




CirQueue::CirQueue()
{
	size = 0;
	front = 0;
	end = 0;
}

bool CirQueue::pushQueue(int value)
{
	// is the push possible 
	if (size <= 10)
	{
		// it is
		memory[end] = value;
		end = (end + 1) % 10;
		size++;
		return true;
	}

	// it isn't 
	return false;
}

bool CirQueue::popQueue(int& value)
{
	// is the pop possible
	if (size > 0)
	{
		// it is
		value = memory[front];
		front = (front + 1) % 10;
		size--;
		return true; 
	}

	// it isn't
	return false;
}


CirQueue::~CirQueue()
{
}
