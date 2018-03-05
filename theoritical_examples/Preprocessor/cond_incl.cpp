#define C_lang 

#ifdef C_lang

#include <stdio.h>

#else 

#include <iostream>

#endif

void printVar(int x) {

#ifdef C_lang
	printf("%d", x);
#else 
	std::cout << x;
#endif

}

int main() {

	int x = 42;

	printVar(x);

	return 0;
}