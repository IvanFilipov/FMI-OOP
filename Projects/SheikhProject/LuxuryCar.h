#pragma once

#pragma once

#include "Car.h"

class LuxuryCar : public Car {

private:

	std::string extras;
	static const unsigned int SingleExtraProfit;

public:

	LuxuryCar();
	LuxuryCar(const char*, const char*, unsigned int, const char*);
	LuxuryCar(const LuxuryCar&);
	LuxuryCar& operator=(const LuxuryCar&);
	~LuxuryCar();

    int GetExtrasCount() const;
	
	void Print(std::ostream& = std::cout) const;
	void Read(std::istream& = std::cin);

	void AddExtras(const char*);
	
	int HowManyDifferent(const char*) const;
	static unsigned int GetSingleExtraProfit();
	
	
};