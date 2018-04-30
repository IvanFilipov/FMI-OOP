#include "Duck.h"

Duck::Duck(const char * src) : Animal(src) {

}

void Duck::makeSound() {

	std::cout << "Duck with name " << name << " : quack ! \n";
}

Animal* Duck::clone() {

	//this is how we make a new heap object as same as ours 
	//and we return base class pointer in order to use the polymorphism
	return new Duck(*this);
}
