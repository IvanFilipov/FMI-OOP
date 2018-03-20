#include <iostream>

using namespace std; //brings here all names from std
using std::cout; //only cout

//name spaces are used in large project
//to separate the global name space

const int x = 10; //global var 

namespace myNamespace {

	const int x = 15;
}

namespace otherNamespace {

	const int x = 20;
}


struct Hero {

	enum Action {

		ATTACK,
		DEFEND

	}action;

	int otherVal;
};

int main() {

	std::cout << x << std::endl; // same as ::x -> global x
	std::cout << ::x << std::endl;

	std::cout << myNamespace::x << std::endl; //x from our new namespace

	std::cout << otherNamespace::x << std::endl;

	//if we want to use Action as a type
	//we should use the scope resolution operator ::

	//Action ac = ATTACK;
	Hero::Action ac = Hero::Action::ATTACK;

	std::cout << sizeof(Hero::otherVal);

	//for other usages see examples for classes

	return 0;
}
