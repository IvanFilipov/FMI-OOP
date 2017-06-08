#pragma once
#include "Figure.h"
class Rectangle :
	public Figure
{
	double x1;
	double y1;
	double x2;
	double y2;

public:
	Rectangle();


	virtual void Read(std::ifstream &);
	virtual void Print()const;
	virtual void isIn(double, double)const;
	virtual void translate(double, double);
	virtual Figure* At(int);
};

