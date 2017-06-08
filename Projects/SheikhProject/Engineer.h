#pragma once

#include<string>
#include<vector>
#include<fstream>

#include"SportCar.h"
#include"LuxuryCar.h"

class Engineer{

protected:
	
	std::string EngName;
	std::string PossibleExtras;
	unsigned int SingleExtraCost;
	unsigned int SingleHpCost;


protected:

	Engineer();
	~Engineer();
	Engineer& operator=(const Engineer&);
	Engineer(const Engineer&);

public:

	void SetParams(std::string, unsigned int, unsigned int);

	void GetParams(std::string&, std::string&,unsigned int&, unsigned int &) const;

	long long GetProfitFromSportCars(const std::vector<SportCar>&)const;
	long long GetProfitFromLuxuryCars(const std::vector<LuxuryCar>&)const;

	void Tuning(std::vector<SportCar>&)const;
	void AddExtras(std::vector<LuxuryCar>&)const;

	void ReadFromFile(std::ifstream&);

};

