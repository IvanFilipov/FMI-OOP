#pragma once

#include<string>
#include<vector>
#include<fstream>

#include"SportCar.h"
#include"LuxuryCar.h"

class Engineer {

protected:
	
	std::string engName;
	std::string possibleExtras;
	unsigned int singleExtraCost;
	unsigned int singleHpCost;

public:

	Engineer() = default;

	void setParams(std::string, unsigned int, unsigned int);

	void getParams(std::string&, std::string&,unsigned int&, unsigned int &) const;

	long long getProfitFromSportCars(const std::vector<SportCar>&)const;
	long long getProfitFromLuxuryCars(const std::vector<LuxuryCar>&)const;

	void tuning(std::vector<SportCar>&)const;
	void addExtras(std::vector<LuxuryCar>&)const;

	void readFromFile(std::ifstream&);
};

