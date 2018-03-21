#ifndef __CLOCK_H__
#define __CLOCK_H__

#include <stdint.h>

const int MAX_MINUTES = 60;
const int MAX_SECONDS = 60;
const int MAX_HOURS = 24;

class Clock {

private:  

	//integers only because time structure
	//have int members
	int hour;     // 0 - 23
	int minute;   // 0 - 59
	int second;   // 0 - 59

public:   

	//default constructor
	Clock();

	// Constructor with pramas
	Clock(int, int, int); 

	int getHour() const;   
	void setHour(int);

	int getMinute() const; 
	void setMinute(int); 

	int getSecond() const; 
	void setSecond(int);

	//outputs in format HH:MM:SS
	void print() const; 

	//moves the clock one second ahead
	void nextTick(); 

	//synchronize with the system time
	void syncTime();

}; 

#endif // !__CLOCK_H__
