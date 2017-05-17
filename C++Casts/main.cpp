//sources : 
// http://www.cplusplus.com/doc/tutorial/typecasting/
// Effective C++ Scott Mayers

#include<iostream>

void Print(char * str) {

	std::cout << str;

}


class Base { virtual void dummy() {} };

class Derived : public Base { int a; };


int main() {

	const char* myStr = "ConstCast?";

	//Print(myStr); :(
	Print(const_cast<char*>(myStr));

	//const_cast can be used to remove the constance 

	char c = 10;

	int* p = (int*)&c; // unsafe
	//*p = 15000; //run - time error stack around c is corrupted 

	//int *p1 = static_cast<int*>(c); //invalid type converse COMPILATION time error 
	// static_cast similar to C - style casts


	try {
		Base * pba = new Derived;
		Base * pbb = new Base;
		Derived * pd;

		pd = dynamic_cast<Derived*>(pba);
		if (pd == NULL) 
			std::cout << "Null pointer on first type-cast.\n";

		pd = dynamic_cast<Derived*>(pbb);
		if (pd == NULL) 
			std::cout << "Null pointer on second type-cast.\n";

	}
	catch (std::exception& e){
		std::cout << "Exception: " << e.what(); 
	}

	//dynamic_cast can be used for both upcasts and downcasts
	//when pointers used -> NULL 
	//when references -> exception
	

	class A { /* ... */ };
	class B { /* ... */ };
	A * a = new A;
	B * b = reinterpret_cast<B*>(a);

	//reinterpret_cast all to all , casting bits , so can be very unsafe
	//usage : casting between pointer to functions

	return 0;
}