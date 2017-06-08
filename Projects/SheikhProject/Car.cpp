#include <string.h>
#include <iostream>
#include "Car.h"



Car::Car() : price(0){

#ifdef DEBUG

	std::cout << "[ Car ctor working ] at 0x" << this << " ]\n";

#endif

}

Car::Car(const char* br, const char* md , int pr) :
	brand(br), model(md) , price(pr){

#ifdef DEBUG

	std::cout << "[ Car ctor with parameters working  at 0x" 
		      << this << " ]\n";

#endif // DEBUG


}


Car::~Car(){

#ifdef DEBUG
	std::cout << "[Car destructor working at 0x" << this << " ]\n";
#endif
	Clear();
}

Car::Car(const Car& other) : brand(other.brand) , model(other.model) , price(other.price){

#ifdef DEBUG

	std::cout << "[Car copy ctor working at 0x" << this 
			  << "with param at 0x" << &other <<" ]\n";
#endif 

}

Car& Car::operator=(const Car& other){


#ifdef DEBUG

	std::cout << "[Car operator= working at 0x" << this
		<< "with param at 0x" << &other << " ]\n";
#endif

	if (this != &other) {

		Clear();
		CopyFrom(other);

	}


	return *this;
}


void Car::CopyFrom(const Car& other){

	brand = other.brand;
	model =  other.model;

	price = other.price;

}

void Car::Clear() {

	brand.clear();
	model.clear();
}


const char * Car::GetModel() const{

	return model.c_str();
}

void Car::SetModel(const char * value){

		model = value;
	
}


void Car::Print(std::ostream& os) const{

#ifdef DEBUG
	os << "A car object at 0x" << this << '\n';
#endif

	os  << "\n  Brand : " << brand
		<< "\n  Model : " << model
		<< "\n  Price : " << price
		<< "\n";

}

void Car::Read(std::istream & is){

	is >> brand >> model >> price;

}

unsigned int Car::GetPrice() const {
	return price;
}

