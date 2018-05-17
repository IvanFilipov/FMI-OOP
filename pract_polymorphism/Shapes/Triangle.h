#pragma once

#include "Figure.h"

class Triangle : public Figure {

private:

	double x1, y1;
	double x2, y2;
	double x3, y3;

public:

	virtual void print() const override;
	virtual void readFromFile(std::ifstream &) override;
	virtual bool isInside(double, double) const override;
	virtual void translate(double, double) override;
	virtual const Figure* getFigureAt(size_t) const override;
};

