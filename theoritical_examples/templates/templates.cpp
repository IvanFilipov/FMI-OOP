#include<iostream>

#include "Box.hpp"

//just an ordinary class
class myObj {

private :

	int x;

public:

	explicit myObj(int a) : x(a) {}

	friend std::ostream& operator<<(std::ostream& os, const myObj& o);

	bool operator<(const myObj& other) const {

		return x < other.x;
	}
};

std::ostream& operator<<(std::ostream& os, const myObj& o) {

	return os << o.x;
}


//a template function to compare two object
template<typename T>
const T& max(const T& rhs, const T& lhs) {

	std::cout << "using version with templates\n";

	return (lhs < rhs) ? rhs : lhs;
}


//overloading of template function
const char* const & max(const char* const & str, const char* const & str2) {

	if (strcmp(str, str2) <= 0)
		return str;

	return str2;
}

const int& max(const int& lhs, const int& rhs) {

	std::cout << "using version with ints\n";
	return (lhs < rhs) ? rhs : lhs;
}


void f(const Box<int>& b) {
	//...
}

int main() {

	std::cout << max("abc", "abd");


	std::cout << max(10, 20) << std::endl;

	std::cout << max(3.14, 2.15) << std::endl;
	
	char c = 42;

	std::cout << max<int>(c, 20) << std::endl;


	myObj obj(10);
	myObj obj1(20);

	std::cout << max(obj, obj1) << std::endl;

	Box<int> b1(13);

	Box<double> b2(3.13);

	std::cout << b1.getFoo() << std::endl;

	std::cout << b2.getFoo() << std::endl;

	f(b1); //ok type is Box<int>
	//f(b2); //problem type is not Box<int>

	Box<myObj> b3(obj);

	std::cout << b3.getFoo() << std::endl;

	//specialization class tests
	Box<int> b(11);
	std::cout << b.getFoo() << std::endl; //should return 53

	Box<char*> bstr("template string");
	std::cout << bstr.getFoo() << std::endl; 

	return 0;
}

