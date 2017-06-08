#include "Horse.h"




Horse::Horse(const char * src) : Animal(src){

}

Horse::Horse(const Horse &other) : Animal(other){

}

Horse& Horse::operator=(const Horse& other){

	if (this != &other) {

		Animal::operator=(other);

	}

	return *this;
}

void Horse::MakeSound(){
	
	std::cout << "Horse with name " << name << " : whinny!\n";
}

Animal* Horse::clone(){

	//this is how we make a new heap object as same as ours 
	//and we return base class pointer in order to use the polymorphism
	return new Horse(*this);
}
