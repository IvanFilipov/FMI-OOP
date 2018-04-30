#include "Dog.h"


Dog::Dog(const char* src) : Animal(src) {

}

void Dog::makeSound() {

	std::cout << "Dog with name " << name << " : bark! \n";
}

Animal* Dog::clone() {

	//this is how we make a new heap object as same as ours 
	//and we return base class pointer in order to use the polymorphism
	return new Dog(*this);
}