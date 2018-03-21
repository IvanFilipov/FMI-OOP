#include <iostream> //cin, cout
#include <iomanip> //setfill, setw
#include <time.h> /* time_t, struct tm, time, localtime */

#include "Clock.h"    

Clock::Clock() {

	hour = minute = second = 0;
}

Clock::Clock(int h, int m, int s) {
	
	//using the setter for easier validation
	setHour(h);
	setMinute(m);
	setSecond(s);
}

int Clock::getHour() const {

	return hour;
}

void Clock::setHour(int h) {

	if (h < 0 || h > MAX_HOURS)
		h = 0;

	hour = h;
}

int Clock::getMinute() const {

	return minute;
}

void Clock::setMinute(int m) {

	if (m < 0 || m > MAX_MINUTES)
		m = 0;

	minute = m;
}

// public getter for private data member second
int Clock::getSecond() const {

	return second;
}

// public setter for private data member second. No input validation
void Clock::setSecond(int s) {

	if (s < 0 || s > MAX_SECONDS)
		s = 0;

	second = s;
}



void Clock::print() const {

	std::cout << std::setfill('0') 
		<< std::setw(2) << hour << ":" 
		<< std::setw(2) << minute << ":" 
		<< std::setw(2) << second << std::endl;
}

// increase this instance by one second
void Clock::nextTick() {

	++second;
	if (second >= 60) {
		second = 0;
		++minute;
	}

	if (minute >= 60) {
		minute = 0;
		++hour;
	}

	if (hour >= 24) {
		hour = 0;
	}
}

void Clock::syncTime() {

	time_t curTime;
	time(&curTime); //reading the current time as a large number
				  // see more : UNIX UTC

	tm* timeInfo; //a pointer to structure in which we have separated fields
				//for minutes, seconds..etc

	timeInfo = localtime(&curTime); //formating the current time as local

	setHour(timeInfo->tm_hour);
	setMinute(timeInfo->tm_min);
	setSecond(timeInfo->tm_sec);
}
