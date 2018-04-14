#ifndef __EXAMPLE_H__
#define __EXAMPLE_H__

#include <limits.h>


void f(int = 0, int = 1);

int max(int ,
	int = std::numeric_limits<int>::min(),
	int = std::numeric_limits<int>::min());

inline //for inlined function both definition and declaration
int doSomething(int x = 42) { //goes into the header file

	return x * x;
}

#endif // !__EXAMPLE_H__
