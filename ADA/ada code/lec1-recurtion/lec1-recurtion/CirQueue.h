#pragma once
#define LENGTH = 10

class CirQueue
{
public:
	CirQueue();
	
	bool pushQueue(int value);
	bool popQueue(int& value);

	~CirQueue();

private:
	
	int  memory[10];		// size of queue
	unsigned int front;		// points at the front location in the queue
	unsigned int size;		// queue lenth
	unsigned int end;		// points at the next empty location 

};

