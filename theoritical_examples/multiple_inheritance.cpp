//pretty basic example about
//multiple inheritance
#include<iostream>

class A_Class {

public:

	A_Class() { std::cout << "default A class constructor\n"; }

	void special_feature() {

		std::cout << "A class special feature activated...\n";
	}

	~A_Class() { std::cout << "A class destructor\n"; }
};

class C_Class {

public:

	C_Class() { std::cout << "default C class constructor\n"; }

	//new method
	void stop_engine() {

		std::cout << "engine stopped!\n";
	}

	~C_Class() { std::cout << "C class destructor\n"; }
};

//the memory layout depends on the
//sequence of base classes 
class CLA : public A_Class, public C_Class {

public:
	CLA() { std::cout << "default CLA class constructor\n"; }
	~CLA() { std::cout << "CLA class destructor\n"; }
};

void f(C_Class& c) {

	c.stop_engine();
}

void g(A_Class* pA) {

	pA->special_feature();
}

int main() {

	CLA c1; //watch the constructors...

	//sending the derived object
	//where base objects are 
	//supposed to be
	f(c1);
	g(&c1);

	return 0;
}