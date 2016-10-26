#include "List.h"
#include <vector>

using namespace std;

#define DEFAULT_SIZE	13

List::List()
{
	vector<string> list(DEFAULT_SIZE);

	for (int i = 0; i < list.size(); i++)
		list[i] = "";

	alist = list;
}

List::List(int tableSize)
{
	vector<string> list(tableSize);

	for (int i = 0; i < list.size(); i++)
		list[i] = "";

	alist = list;
}

int List::addQuadric(int address, string aString)
{
	return add(address, aString, 2);
}

int List::addPenta(int address, string aString)
{
	return add(address, aString, 5);
}

int List::add(int address, string aString, int aFactor)
{
	int status = 1;

	// insæt den extra unit
	

	return status;
}


List::~List()
{
}
