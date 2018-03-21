#include <iostream>

#include "Clock.h"

int main() {

	Clock c; //defalut clock

	c.print();
	c.syncTime();
	c.print();

	c.setHour(11);
	c.print();

	c.setMinute(1213);
	c.print();
	
	Clock c2(10, 11, 23);
	c2.print();

	std::cout << c2.getHour() << ' '
		<< c2.getMinute() << ' '
		<< c2.getSecond() << '\n';

	return 0;
}