#pragma once
#include "Car.h"

class LuxuryCar : public Car {

private:

	std::string extras;
	static const unsigned int singleExtraProfit;

public:

	LuxuryCar();
	LuxuryCar(const char*, const char*, unsigned int, const char*);
	
public:

    int getExtrasCount() const;
	
	void printLux(std::ostream& = std::cout) const;
	void readLux(std::istream& = std::cin);

	void addExtras(const char*);
	
	int howManyDifferent(const char*) const;
	static unsigned int getSingleExtraProfit();
};