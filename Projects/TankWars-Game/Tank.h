#pragma once
#include<iostream>

class Tank {

private:

	char* name;
	size_t ShootPower;
	size_t ShellWeight;
	size_t pos;

public:

	Tank();
	Tank(const char*, size_t, size_t, size_t);
	Tank(const Tank&);
	Tank& operator=(const Tank&);

private:

	void CopyFrom(const Tank&);

private:

	static const int CalcWind();

	void DrawTheShot(int const,int const,int const,int const,std::ostream&)const;

public:

	//returns the difference between where the shot has fallen and where the flag is
    int Fire(size_t const FlagPos, std::ostream& = std::cout)const;

	void PrintInfo(std::ostream& = std::cout)const;

	static void PrintUnit(std::ostream& =std::cout);

	size_t GetPos()const;
};
