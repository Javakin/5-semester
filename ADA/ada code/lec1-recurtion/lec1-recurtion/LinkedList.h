#pragma once
#include <vector>

class LinkedList
{
public:
	LinkedList();
	int  getSize();
	void printList();
	bool contains(int value);
	bool addValueOnce(int value);
	bool removeValue(int value);

	~LinkedList();

private: 
	std::vector<SingleNode*> List;

};

class SingleNode
{
public:
	SingleNode();
	

	~SignleNode();

private:
	int data; 
	

};