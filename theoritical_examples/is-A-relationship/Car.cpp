#include <string.h>
#include <iostream>
#include "Car.h"

//help fnc
static void allocateAndCopy(char*& ptr, const char* value) {

	// If NULL has been passed, free the memory instead
	if (!value) {

		delete[] ptr;
		ptr = NULL;
		return;
	}

	// If a valid string has been passed, make a copy
	size_t bufferSize = strlen(value) + 1;

	char* buffer = new char[bufferSize];
	delete[] ptr;
	ptr = buffer;

	strcpy_s(ptr, bufferSize, value);
}


Car::Car() : brand(nullptr), model(nullptr), price(0) {

	std::cout << "[ Car ctor working ] at 0x" << this << " ]\n";
}

Car::Car(const char* br, const char* md , int pr) :
	brand(nullptr), model(nullptr) , price(pr){

	std::cout << "[ Car ctor with parameters working  at 0x" 
		      << this << " ]\n";

	try {

		allocateAndCopy(brand, br);
		allocateAndCopy(model, md);
	}
	catch (std::bad_alloc& e) {

		std::cerr << e.what();
		clear();

		throw;
	}
}


Car::~Car() {

	std::cout << "[Car destructor working at 0x" << this << " ]\n";
	clear();
}

Car::Car(const Car& other) : brand(nullptr) , model(nullptr) , price(0){

	std::cout << "[Car copy ctor working at 0x" << this 
			  << "with param at 0x" << &other <<" ]\n";
	try {

		copyFrom(other);
	}
	catch (std::bad_alloc& e) {

		std::cerr << e.what();
		clear();

		throw;
	}
}

Car& Car::operator=(const Car& other) {

	std::cout << "[Car operator= working at 0x" << this
		<< "with param at 0x" << &other << " ]\n";

	if (this != &other) {

		clear();

		try {

			copyFrom(other);
		}
		catch (std::bad_alloc& e) {

			std::cerr << e.what();
			clear();

			throw;
		}
	}

	return *this;
}


void Car::copyFrom(const Car& other) {

	allocateAndCopy(brand,other.brand);
	allocateAndCopy(model, other.model);

	price = other.price;
}

void Car::clear() {

	delete[] model;
	delete[] brand;

	brand = nullptr;
	model = nullptr;
}


const char * Car::getModel() const{

	return model ? model : "";
}

void Car::setModel(const char * value){

	allocateAndCopy(model, value);	
}


void Car::print(std::ostream& os) const {

	os	<< "A car object at 0x" << this << '\n'
		<< "\n  Brand : " << brand
		<< "\n  Model : " << model
		<< "\n  Price : " << price
		<< "\n";
}
