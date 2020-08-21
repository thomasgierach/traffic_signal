//MCS 360 - Project 3 <Thomas Gierach>
//Signal.h
#pragma once

class Signal {
private:
	int state;
	int elapsed;
public:
	Signal();
	//default constructor; sets state and elapsed to 0;
	int get_state() const;
	//returns state;
	int get_elapsed() const;
	//returns elapsed;
	void next();
	/*moves the lights to the next state 
	//and increments the elapsed time*/
};