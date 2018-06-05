#pragma once

#include "Car.h"

class SportCar : public Car {

private:
	
	unsigned int horsePower;
	unsigned int tuningLimit;
	static const unsigned int singleHpProfit;
	
public:

	SportCar();
	SportCar(const char* , const char* , unsigned int , unsigned int,unsigned int);

public:

	unsigned int getTuningLimit() const;

	void printSp(std::ostream& = std::cout) const;
	void readSp(std::istream& = std::cin);

	unsigned int getHorsePower()const;
	void tuning();
	static const unsigned int getSingleHpProfit();
};
