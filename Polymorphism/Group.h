#pragma once
#include "Figure.h"
#include <vector>

class Group : public Figure
{

	std::vector<Figure*> vec;

	double x, y;

public:

	Group();

	virtual void Read(std::ifstream &);
	virtual void Print()const;
	virtual void isIn(double, double)const;
	//empty one
	virtual void translate(double, double) {};
	virtual Figure* At(int);
	
};

