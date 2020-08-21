//MCS 360 - Project 3 <Thomas Gierach>
//Signal.cpp

#include "Signal.h"
#include <iostream>

using namespace std;

Signal::Signal() {
	state = 0;
	elapsed = 0;
}

int Signal::get_state() const{
	return state;
}

int Signal::get_elapsed() const{
	return elapsed;
}

void Signal::next() {
	if (state < 3) {
		state++;
	}
	else {
		state = 0;
	}
	elapsed++;
}

