//MCS 360 - Project 3 <Thomas Gierach>
// Test_Lane.cpp : 

#include <iostream>
//#include "..\Common\Lane.h"
#include "Lane.h"
#include "Lane.cpp"

bool Verbose();

int main()
{
	int pos_int;
	cout << "Give a positive integer: ";
	cin >> pos_int;
	cout << endl;

	int lambda;
	cout << "Give lambda: ";
	cin >> lambda;
	cout << endl;

	bool v = Verbose();

	Lane test_lane = Lane(pos_int, lambda, v);

	int start_time;
	int end_time;

	cout << "Give a start time: ";
	cin >> start_time;
	cout << endl;

	cout << "Give an end time: ";
	cin >> end_time;
	cout << endl;

	test_lane.pop(start_time, end_time, v);

	return 0;
}

bool Verbose() {
	char answer;
	cout << "Verbose (y/n): " << endl;
	cin >> answer;

	if (answer == 'y') {
		return true;
	}
	else {
		return false;
	}

}
