#include <cstring>
#include <iostream>

#include "SportCar.h"

const unsigned int SportCar::tuningLimit = 50;

SportCar::SportCar() : horsePower(0) {

	std::cout << "[ SportCar ctor working ] at 0x" << this << " ]\n";
}


SportCar::SportCar(const char* br, const char* md , unsigned int pr, unsigned int hp )
	: Car(br, md, pr) , horsePower(hp) {

	std::cout << "[ SportCar ctor with parameters working  at 0x" 
		      << this <<  " ]\n";
}


SportCar::~SportCar(){

	std::cout << "[SportCar destructor working at 0x" << this << " ]\n";

	//WE DON'T REALLY NEED THIS , BEACUSE CAR'S DESTRUCTOR WORKS AFTER
	//SPORTCAR'S ONE AND WILL CLEAR ALL DYNAMIC MEMORY
	//Car::Clear();
}

SportCar::SportCar(SportCar const & other) : Car(other) {

	std::cout << "[Sport Car copy ctor working at 0x" << this
		<< "with param at 0x" << &other << " ]\n";

	horsePower = other.horsePower;
}

//second way :
///SportCar::SportCar(SportCar const & other){

///	Car::CopyFrom(other);
///	horsePower = other.horsePower;

///}

SportCar& SportCar::operator=(SportCar const& other){

	std::cout << "[Car operator= working at 0x" << this
		<< "with param at 0x" << &other << " ]\n";

    if (this != &other){

		Car::operator=(other);
        //or
		//Car::clear();
        //Car::CopyFrom(other);

		horsePower = other.horsePower;
    }

    return *this;
}


void SportCar::print(std::ostream& os) const {
	
	os << "A SportCar object at 0x" << this << '\n';
	Car::print(os);
	os	<< "\n  HP: " << horsePower << "\n";
}

void SportCar::tune(unsigned int addHp) {

	if (addHp > tuningLimit)
		throw std::logic_error("too much tunning!");

	horsePower += addHp;
	price += (addHp * 0.5); //price is accessible
	//because it is protected in the base class
}
