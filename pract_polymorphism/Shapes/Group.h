#pragma once

#include "FigureContainer.h"

class Group : public Figure {

	FigureContainer vec;

	double x, y;

public:

	virtual void print() const override;
	virtual void readFromFile(std::ifstream&) override;
	virtual bool isInside(double, double) const override;
	virtual void translate(double, double) override;
	virtual const Figure* getFigureAt(size_t) const override;
};

