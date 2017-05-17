#include <string.h>
#include <iostream>
#include "Car.h"

//help fnc
void AllocateAndCopy(char*& ptr, const char* value) {

	// If NULL has been passed, free the memory instead
	if (!value) {

		delete[] ptr;
		ptr = NULL;
		return;
	}

	// If a valid string has been passed, make a copy
	size_t BufferSize = strlen(value) + 1;

	char* buffer = new char[BufferSize];
	delete[] ptr;
	ptr = buffer;

	strcpy_s(ptr, BufferSize, value);

}


Car::Car() : brand(nullptr),model(nullptr),price(0){

	std::cout << "[ Car ctor working ] at 0x" << this << " ]\n";
    
}

Car::Car(const char* br, const char* md , int pr) :
	brand(nullptr), model(nullptr) , price(pr){

	std::cout << "[ Car ctor with parameters working  at 0x" 
		      << this << " ]\n";

	try {
		AllocateAndCopy(brand, br);
		AllocateAndCopy(model, md);
	}
	catch (std::bad_alloc& e) {

		std::cerr << e.what();
		Clear();

		throw;
	}

}


Car::~Car(){

	std::cout << "[Car destructor working at 0x" << this << " ]\n";

	Clear();
}

Car::Car(const Car& other) : brand(nullptr) , model(nullptr) , price(0){

	std::cout << "[Car copy ctor working at 0x" << this 
			  << "with param at 0x" << &other <<" ]\n";
	try {
		CopyFrom(other);
	}
	catch (std::bad_alloc& e) {

		std::cerr << e.what();
		Clear();

		throw;
	}
}

Car& Car::operator=(const Car& other)
{
	std::cout << "[Car operator= working at 0x" << this
		<< "with param at 0x" << &other << " ]\n";

	if (this != &other) {

		Clear();

		try {
			CopyFrom(other);
		}
		catch (std::bad_alloc& e) {

			std::cerr << e.what();
			Clear();

			throw;
		}
	}

	return *this;
}


void Car::CopyFrom(const Car& other){

	AllocateAndCopy(brand,other.brand);
	AllocateAndCopy(model, other.model);

	price = other.price;

}

void Car::Clear() {

	delete[] model;
	delete[] brand;

	brand = nullptr;
	model = nullptr;

}


const char * Car::GetModel() const{

	return model ? model : "";
}

void Car::SetModel(const char * value){

		AllocateAndCopy(model, value);
	
}


void Car::Print(std::ostream& os) const{

	os	<< "A car object at 0x" << this << '\n'
		<< "\n  Brand : " << brand
		<< "\n  Model : " << model
		<< "\n  Price : " << price
		<< "\n";

}
