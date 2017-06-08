#pragma once

#include<iostream>
#include<fstream>
#include<string>
#include"Engineer.h"

#define CARBASEPATH "Cars.txt"
#define ENGINEERBASEPATH "Engineers.txt"

class Sheikh : private Engineer{

private:
	
	std::string Name;
	long long budget;
	static const int myCarsPriceExpectation;

public:

	Sheikh(const char*, long long);
	
	void BuyCars(std::ostream& = std::cout) ;
	void BuyCars(const char* Fpath);


};

