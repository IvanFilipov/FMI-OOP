#include <iostream>
#include "./inline_defaultParams.h"

void f(int x, int y) {

	std::cout << "my params are : "
		<< "x = " << x
		<< "  y = " << y << '\n';
}

int max(int x, int y, int z) {

	int temp = x;

	temp = (y > temp) ? y : temp;
	temp = (z > temp) ? z : temp;

	return temp;
}
