#pragma once
#include "Figure.h"

class Circle : public Figure{

private:

	double x;
	double y;

	double Rad;


public:


	Circle();
	
	virtual void Read(std::ifstream &);
	virtual void Print()const;
	virtual void isIn(double,double)const;
	virtual void translate(double, double);
	virtual Figure* At(int);
};

