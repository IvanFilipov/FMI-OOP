#pragma once

#include "Car.h"

class SportCar : public Car {

private:
	
	unsigned int horsePower;
	static const unsigned int TuningLimit;
	
public:

	SportCar();
	SportCar(const char* , const char* , unsigned int , unsigned int);
	SportCar(const SportCar& );
	SportCar& operator=(const SportCar&);
	~SportCar();

	unsigned int GetHP() const;
	void SetHP(unsigned int value);

	void Print(std::ostream& = std::cout) const;
	
};
