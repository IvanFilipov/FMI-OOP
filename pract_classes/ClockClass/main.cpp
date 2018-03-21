#include <iostream>

#include "Clock.h"

int main() {

	//sync / set test
	std::cout << "default clock ..\n";
	Clock c; //defalut clock

	c.print();
	c.syncTime();
	std::cout << "after sync :\n";
	c.print();

	c.setHour(11);
	std::cout << "after set hour to 11 :\n";
	c.print();

	c.setMinute(1213);
	std::cout << "after set minutes to invalid value :\n";
	c.print();
	

	std::cout << "\n\ntesting clock 2 started at :\n";
	Clock c2(3, 1, 2);
	c2.print();

	std::cout << "\nunformatted print\n";
	std::cout << c2.getHour() << ' '
		<< c2.getMinute() << ' '
		<< c2.getSecond() << '\n';

	//next tick test

	std::cout << "\n\nsome ticking .. from \n";
	Clock c3(10, 59, 58);

	c3.print();
	c3.nextTick();
	c3.print();
	c3.nextTick();
	c3.print();

	return 0;
}