#include "Duck.h"

Duck::Duck(const char * src) : Animal(src) {

}

Duck::Duck(const Duck &other) : Animal(other) {

}

Duck& Duck::operator=(const Duck& other) {

	if (this != &other) {

		Animal::operator=(other);

	}

	return *this;
}

void Duck::MakeSound() {

	std::cout << "Duck with name " << name << " : quack ! \n";
}

Animal* Duck::clone() {

	//this is how we make a new heap object as same as ours 
	//and we return base class pointer in order to use the polymorphism
	return new Duck(*this);
}
