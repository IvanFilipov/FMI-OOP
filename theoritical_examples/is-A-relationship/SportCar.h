#pragma once

#include "Car.h"

//the sport car is - a car
class SportCar : public Car {

private:
	
	//hidden from us we have all data members from Car
	unsigned int horsePower;
	static const unsigned int tuningLimit;
	
public:

	SportCar();
	SportCar(const char* , const char* , unsigned int , unsigned int);
	SportCar(const SportCar&);
	SportCar& operator=(const SportCar&);
	~SportCar();

public:

	//inlined methods get and set
	unsigned int getHP() const {

		return horsePower;
	}

	inline
	void setHP(unsigned int);

	//redefinition of the function print
	//that is inherited from the base class
	//not a good practice
	void print(std::ostream& = std::cout) const;

	void tune(unsigned int);
};

inline
void SportCar::setHP(unsigned int hp) {
	
	horsePower = hp;
}