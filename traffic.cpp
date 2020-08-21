//MCS 360 - Project 3 <Thomas Gierach>
//traffic.cpp

#include <iostream>
//#include "..\Common\Signal.h"
//#include "..\Common\Lane.h"
#include "Signal.h"
#include "Signal.cpp"
#include "Lane.h"
#include "Lane.cpp"

using namespace std;
/*
-Creates a vector of 12 lanes, after prompting the user for the
end of the time interval and the parameter. 
-The program has a vector of doubles to hold the 12 waiting times. 
-Before the simulation runs, make sure to store the sizes of each lane in a vector of 12 integers.
-These sizes are then used to compute the average waiting time for each lane, at the end of the simulation.
-The simulation ends when all lanes are empty.
-As the simulation cycles through the states, in even states 0 and 2, two queues are popped (the left
going lanes), and in odd states 1 and 3, four queues are popped (straight and right lanes). 
-In particular, in state 0, pop lanes 0 and 1,
				in state 1, pop lanes 2 through 5,
				in state 2, pop lanes 6 and 7,
				in state 3, pop lanes 8 through 11
*/

bool all_empty(vector<Lane> sizes);
bool Verbose();

int main() {

	int pos_int;
	cout << "Give a positive integer: ";
	cin >> pos_int;
	cout << endl;

	int lambda;
	cout << "Give lambda: ";
	cin >> lambda;
	cout << endl;

	bool v = Verbose();

	cout << "Generating the queues..." << endl;

	vector<Lane> lanes;
	lanes.reserve(12);

	vector<double> wait_times;
	wait_times.reserve(12);

	vector<int> sizes;
	sizes.reserve(12);

	cout << "Sizes of the lanes: ";
	for (int i = 0; i < 12; ++i) {
		lanes.push_back(Lane(pos_int, lambda, v));
		wait_times.push_back(0);
		sizes.push_back(lanes.back().size());
		cout << sizes.back() << " ";
	}

	cout << endl;
	
	Signal sig = Signal();
	int start_time = 0;
	int end_time = 1;
	
	do
	{
		cout << "State: " << sig.get_state() << " " << "elapsed time: " << sig.get_elapsed() << endl;
		
		
		/*
		if (end_time < 4) {
			start_time = 0;
		}
		else {
			start_time = end_time - 4;
		}
		*/
		switch (sig.get_state())
		{
		case 0:
			cout << "green for left traffic from north and south, red for all others\n";
			wait_times[0] += lanes[0].pop(start_time, end_time, v);
			wait_times[1] += lanes[1].pop(start_time, end_time, v);
			break;
		case 1:
			cout << "green for straight and right going traffic from north and south, red for all others\n";
			wait_times[2] += lanes[2].pop(start_time, end_time, v);
			wait_times[3] += lanes[3].pop(start_time, end_time, v);
			wait_times[4] += lanes[4].pop(start_time, end_time, v);// -start_time;
			wait_times[5] += lanes[5].pop(start_time, end_time, v);// -start_time;
			break;
		case 2:
			cout << "green for left traffic from west and east, red for all others\n";
			wait_times[6] += lanes[6].pop(start_time, end_time, v);// -start_time;
			wait_times[7] += lanes[7].pop(start_time, end_time, v) - start_time;
			break;
		case 3:
			cout << "green for straight and right going traffic from west and east, red for all others\n";
			wait_times[8] += lanes[8].pop(start_time, end_time, v);// -start_time;
			wait_times[9] += lanes[9].pop(start_time, end_time, v);// -start_time;
			wait_times[10] += lanes[10].pop(start_time, end_time, v);// -start_time;
			wait_times[11] += lanes[11].pop(start_time, end_time, v);// -start_time;
			break;
		}
		
		sig.next();
		start_time = sig.get_elapsed();
		end_time = sig.get_elapsed() + 1;

	} while (all_empty(lanes) != true);

	cout << "Average waiting times for each queue: " << endl;

	for (int i = 0; i < 12; ++i) {
		wait_times[i] = wait_times[i] / sizes[i];
		cout << "queue " << i << " : " << wait_times[i] << endl;
	}
	
	return 0;
}

bool all_empty(vector<Lane> sizes) {
	for (auto& i : sizes) {
		if (i.size() != 0) {
			return false;
		}
	}
	return true;
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