#pragma once
#include<iostream>

class Tank {

private:

	char* name;
	size_t shootPower;
	size_t shellWeight;
	size_t pos;

public:

	Tank();
	Tank(const char*, size_t, size_t, size_t);
	Tank(const Tank&);
	Tank& operator=(const Tank&);

private:

	void copyFrom(const Tank&);

private:

	static const int calcWind();

	void drawTheShot(int const, int const, int const, int const, std::ostream&) const;

public:

	//returns the difference between where the shot has fallen and where the flag is
    int fire(size_t const FlagPos, std::ostream& = std::cout) const;

	void printInfo(std::ostream& = std::cout) const;

	static void printUnit(std::ostream& =std::cout);

	size_t getPos() const;
};
