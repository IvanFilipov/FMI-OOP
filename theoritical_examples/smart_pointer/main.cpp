#include <iostream>
#include "SmartPtr.hpp"

class myObj {

private:

	int val;

public:

	myObj(int v = 0) : val(v) { std::cout << "object created!\n"; }
	~myObj() { std::cout << "object destroyed!\n"; }

	//notice that op= and copy constructor are never called in this example
	myObj& operator=(const myObj& o) {

		val = o.val;
		std::cout << "object copied!\n"; 
	}

	myObj(const myObj& o) : val(o.val) { std::cout << "object copied!\n"; }

	int getVal() const { return val; }

};



int main() {

	//old style
	{
		myObj* pObj = new myObj;

		//....

		delete pObj; //could be easily forgotten
	}


	//following the idea of RAII :
	{
		SmartPtr<myObj> smpObj(new myObj);

	} //destructor of smpObj is called, so the memory is freed


	//some tests of our smart pointer functionality 
	{
		SmartPtr<myObj> ptr(new myObj(42));
		SmartPtr<myObj> other;

		other = ptr; //"other" takes the ownership

		std::cout << "the value of pointed object is : " 
			<< (*other).getVal() << std::endl;

		std::cout << "or taken by the pointer : "
			<< other->getVal() << std::endl;

	} //memory for myObj(42) is freed 

	return 0;
}