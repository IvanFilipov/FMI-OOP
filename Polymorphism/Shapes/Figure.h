#pragma once
#include<fstream>

class Figure{

public:

	virtual void Print()const =0;
	virtual void Read(std::ifstream&)=0;
	virtual void isIn(double,double)const=0;
	virtual void translate(double, double) = 0;
	virtual Figure* At(int) = 0;

	virtual ~Figure(){}; // !!!
};

