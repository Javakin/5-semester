#pragma once
class List
{
public:
	List();
	List(int tableSize);

	int addQuadric(int address, string aString);
	int addPenta(int address, string aString);

	int add(int address, string aString, int aFactor);


	~List();

private:
	vector<string> alist;			// contains th list 
	double lambda;					// contains the load constant of the list
};

