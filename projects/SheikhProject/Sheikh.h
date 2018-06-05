#pragma once

#include<iostream>
#include<fstream>
#include<string>
#include"Engineer.h"

#define CARBASEPATH "Cars.txt"
#define ENGINEERBASEPATH "Engineers.txt"


//the Sheikh is implemented in terms of Engineer
class Sheikh : private Engineer{

private:
	
	std::string name;
	long long budget;
	static const int myCarsPriceExpectation;

public:

	Sheikh(const char*, long long);
	
	void buyCars(std::ostream& = std::cout);
	void buyCars(const char* Fpath);
};

