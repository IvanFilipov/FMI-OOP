//let's just open the Pandora's box...
//example showing some of the problems
//related with "diamond problem"
//https://en.wikipedia.org/wiki/Multiple_inheritance

#include<iostream>

//base class
class Mercedes_Car {

protected:

	int price;

	Mercedes_Car(){ std::cout << "mercedes ctor\n"; }

	Mercedes_Car(int pr) : price(pr) {

		std::cout << "BENZ ctor\n";
	}

public :
	
	//virtual method, which will be overridden ONLY in one child
	virtual void start_engine() {

		std::cout << "engine powered by BENZ\n";
	}

	//by rule the destructor should be virtual
	virtual ~Mercedes_Car() {};
};

//for A_Class, Merecedes_Car is a VIRTUAL BASE class
class A_Class : virtual public Mercedes_Car {
	
public:

	A_Class(){ std::cout << "default AAAAAAAAAA\n"; }
	A_Class(int price) : Mercedes_Car(price) {

		std::cout << "A class ...\n";
	}

	//override of the virtual function
	virtual void start_engine() override {

		std::cout << "A class engine started...";
	}

	//virtual ~A_Class(){} already created by the compiler
};

class C_Class : virtual public Mercedes_Car {

public:

	C_Class() { std::cout << "default C\n"; }

	C_Class(int price) : Mercedes_Car(price) {

		std::cout << "C class ...\n";
	}

	//new method
	void stop_engine() {

		std::cout << "engine stopped!\n";
	}
};

//CLA derives both A_Class and C_Class
//the memory layout due to virtual inheritance
//is interesting...
class CLA : public A_Class, public C_Class {

public:

	//calls default constructors for A,C class
	//and constructor with parameter for Mercedes_Car
	CLA(int price) : Mercedes_Car(price) {

		std::cout << "CLA constructed\n";
	}

	int getPrice() const {

		return price;
	}
};

void f(C_Class& c) {

	c.stop_engine();
}

int main() {

	CLA c1(10); //watch the constructors...
	//I got the warning : 
	//"'CLA': inherits 'A_Class::A_Class::start_engine' via dominance"

	Mercedes_Car* mp = new CLA(20);
	mp->start_engine(); //the overridden method
	//in class A_Class "hides" the method is Mercedes_car

	//ok c1 is CLA, CLA is also C_class
	f(c1);

	delete mp;
	return 0;
}