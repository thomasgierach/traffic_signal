#include <iostream>
#include <chrono>
#include <random>

#include "Lane.h"
using namespace std;

Lane::Lane(int time_interval, double lambda, bool verbose) {

	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	default_random_engine generator(seed);

	/*cout << "Give a positive integer : ";
	int nbr;//length of the time interval 0 to nbr; 
	cin >> nbr;//number of times the signals change

	cout << "Give lambda : ";
	//lamba gives you the average number of arrivals
	cin >> lambda;*/

	poisson_distribution<int> distribution(lambda);
	if (verbose == true) 
	{
		cout << "Computing arrival times ..." << endl;
	}
	for (int i = 0; i < time_interval; ++i)
	{
		int rnd = distribution(generator);
		if (verbose == true) 
		{
			cout << "at step " << i << ", number of arrivals : " << rnd << endl;
		}
		if (rnd > 0)
		{
			double stepsize = 1.0 / (rnd + 1.0);
			for (int k = 0; k < rnd; k++)
			{
				if (verbose == true) 
				{
					cout << "-> pushing " << i + stepsize * (k + 1.0) << endl;
				}
				arrivals.push(i + stepsize * (k + 1.0));
			}
		}
	}
}

int Lane::size() const {
	return arrivals.size();
}

double Lane::pop(int start, int end, bool verbose) 
{
	/*
	pop simulates opening of the signal from time start to time end
	in this time all cars who arrived before start had to wait (this adds to the waiting time)
	all cars that came between start and end don't have to wait
	all cars that arrive after end don't get popped.
	All cars that had arrival time less than end get popped.
	*/
	double sum = 0;
	if (arrivals.size() == 0) {
		cout << "There are no cars waiting..." << endl;
		return sum;
	}
	if (verbose == true) 
	{
		while (arrivals.size() != 0)
		{
			cout << "Examining the top arrival: " << arrivals.front() << endl;
			if (arrivals.front() < start) {
				sum += arrivals.front();
				cout << "Popping arrival time: " << arrivals.front() << endl;
				cout << "Wait time: " << start - arrivals.front() << endl;
				arrivals.pop();
			}
			else if (arrivals.front() >= start && arrivals.front() <= end) {
				cout << "Popping arrival time: " << arrivals.front() << endl;
				cout << "Wait time: " << 0 << endl;
				arrivals.pop();
			}
			else {
				break;
			}
		}
	}
	else 
	{
		while (arrivals.size() != 0)
		{
			
			if (arrivals.front() <= end) {
				arrivals.pop();
			}
			else {
				break;
			}
		}
	}
	return sum;
}