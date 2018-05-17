#pragma once
#include "Figure.h"

class Circle : public Figure {

private:

	double x;
	double y;
	double rad;

public:
	//default constructor OK
	//the destructor is automatically virtual

	virtual void print() const override;
	virtual void readFromFile(std::ifstream &) override;
	virtual bool isInside(double, double) const override;
	virtual void translate(double, double) override;
	virtual const Figure* getFigureAt(size_t) const override;
};

