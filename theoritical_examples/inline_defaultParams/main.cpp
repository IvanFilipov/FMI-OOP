#include<iostream>

#include "./inline_defaultParams.h"

int main() {

	f();
	f(10);
	f(20);

	std::cout << "\n\n\n";
	
	std::cout << "max of 10 , 20 , 11 : "
		<< max(10, 20, 11) << '\n';

	std::cout << "max of 10 , 20 : "
		<< max(10, 20) << '\n';

	std::cout << "max(10) : " 
		<< max(10) << '\n';

	std::cout << doSomething();
	//std::cout << 42 * 42;

	return 0;
}