#pragma once

#include "Car.h"

class SportCar : public Car {

private:
	
	unsigned int horsePower;
	unsigned int TuningLimit;
	static const unsigned int SingleHpProfit;
	
public:

	SportCar();
	SportCar(const char* , const char* , unsigned int , unsigned int,unsigned int);
	SportCar(const SportCar& );
	SportCar& operator=(const SportCar&);
	~SportCar();

	unsigned int GetTuningLimit() const;

	void Print(std::ostream& = std::cout) const;
	void Read(std::istream& = std::cin);


	unsigned int GetHorsePower()const;
	void Tuning();
	static const unsigned int GetSingleHpProfit();
	
};
