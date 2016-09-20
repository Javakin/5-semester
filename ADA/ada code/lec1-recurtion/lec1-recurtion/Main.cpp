#include <iostream>
#include "Numbers.h"
#include "TextHandle.h"
#include "CirQueue.h"

//using namespace std;

int main() {
	CirQueue inst;
	int input = 0;
	int output = 0;

	for (int i = 0; i < 5; i++)
	{
		std::cin >> input;
		inst.pushQueue(input);
	}
	

	for (int i = 0; i < 10; i++) {
		if (inst.popQueue(output))
		{
			std::cout << output << std::endl;

		}
	}

	// Program over, freez terminal
	system("pause");
	return 0;
}