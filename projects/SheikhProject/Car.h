#pragma once
#include<iostream>
#include<string>

#define DEBUG //used to toggle debugging output on and off

class Car {

protected:

	std::string brand;
	std::string model;
	unsigned int price;

public:
	
	//G4 not needed, because our nested object can care
	//for their dynamic memory
	Car();
	Car(const char*, const char*, int = 0);
	
public:

	const char* getModel() const;
	void setModel(const char*);

	unsigned int getPrice() const;

	void print(std::ostream& = std::cout) const;
	void read(std::istream& = std::cin);
};
