//MCS 360 - Project 3 <Thomas Gierach>
// Test_Signal.cpp : This file contains the 'main' function. 
//                   Program execution begins and ends there.


#include <iostream>
//#include "..\Common\Signal.h"
#include <Signal.h>
#include <Signal.cpp>

using namespace std;

int main()
{
	char answer;
	Signal sig = Signal();
	do
	{
		cout << "State: " << sig.get_state() << " " << "elapsed time: " << sig.get_elapsed() << endl;

		switch (sig.get_state())
		{
		case 0:
			cout << "green for left traffic from north and south, red for all others\n";
			break;
		case 1:
			cout << "green for straight and right going traffic from north and south, red for all others\n";
			break;
		case 2:
			cout << "green for left traffic from west and east, red for all others\n";
			break;
		case 3:
			cout << "green for straight and right going traffic from west and east, red for all others\n";
			break;
		}
		cout << "Move to the next state? (y/n) ";
		cin >> answer;
		sig.next();
	} while (answer == 'y');
	return 0;
}