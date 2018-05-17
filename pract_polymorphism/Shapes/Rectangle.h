#pragma once

#include "Figure.h"

class Rectangle : public Figure {

	double x1;
	double y1;
	double x2;
	double y2;

public:
	
	virtual void print() const override;
	virtual void readFromFile(std::ifstream &) override;
	virtual bool isInside(double, double) const override;
	virtual void translate(double, double) override;
	virtual const Figure* getFigureAt(size_t) const override;
};

