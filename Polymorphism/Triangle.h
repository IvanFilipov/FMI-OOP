#pragma once
#include "Figure.h"

class Triangle :public Figure{

private:

	double x1, y1;
	double x2, y2;
	double x3, y3;

public:

	Triangle();

	virtual void Read(std::ifstream &);
	virtual void Print()const;
	virtual void isIn(double, double)const;
	virtual void translate(double, double);
	virtual Figure* At(int);
};

