//MCS 360 - Project 3 <Thomas Gierach>
//Lane.h

#pragma once
#include <queue>
using namespace std;

class Lane {
private:
	queue <double> arrivals;
public:
	Lane(int time_interval, double lambda, bool verbose);
	/*takes on input two integers:
	//1)the length of the time interval and 
	//2)the parameter, the average number of arrivals per time unit.
	////optionally: 
	////3) takes a bool verbose
	///////if true: the arrival time is written with each push to the queue
	///////if false: nothing is printed*/
	int size() const;
	/*returns size of arrivals*/

	double pop(int start, int end, bool verbose);
	/*
	input: int start and int end of the considered time 
		   interval, bool verbose
		   -if verbose == true, the popped arrival time with the
		    accumulated wait time is written with each removal from
			the queue
		   -if verbose == false, pop() remains silent
	other: removes from the arrival queue all the times that are 
		   less than the end of the interval.
	output: The sum of the wait times is returned by the pop()
	*/
};