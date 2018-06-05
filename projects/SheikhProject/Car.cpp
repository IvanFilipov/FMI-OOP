#include <string.h>
#include <iostream>
#include "Car.h"



Car::Car() : price(0) {

#ifdef DEBUG
	std::cout << "[ Car ctor working ] at 0x" << this << " ]\n";
#endif
}

Car::Car(const char* br, const char* md, int pr) :
	brand(br), model(md), price(pr) {

#ifdef DEBUG
	std::cout << "[ Car ctor with parameters working  at 0x"
		<< this << " ]\n";
#endif // DEBUG
}


const char* Car::getModel() const {

	return model.c_str();
}

void Car::setModel(const char * value) {

	model = value;
}


void Car::print(std::ostream& os) const {

#ifdef DEBUG
	os << "A car object at 0x" << this << '\n';
#endif

	os << "\n  Brand : " << brand
		<< "\n  Model : " << model
		<< "\n  Price : " << price
		<< "\n";
}

void Car::read(std::istream & is) {

	is >> brand >> model >> price;
}

unsigned int Car::getPrice() const {

	return price;
}

