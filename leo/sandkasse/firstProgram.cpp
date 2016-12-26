#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
//#include <windows.h>

using namespace std;

// main () is where program execution begins
int main()
{
	while (1)
	{
		cout << "one more time\n";
		//ShowCursor(FALSE);//hides the cursor
		sleep(1);
		//ShowCursor(TRUE);//shows it again
		sleep(1);	
	}
	return 0;
}
