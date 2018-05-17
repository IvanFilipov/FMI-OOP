#pragma once

#include<fstream>

//interface class, only abstract methods
class Figure {

public:

	//the actual interface, only pure virtual methods
	virtual void print() const = 0;
	virtual void readFromFile(std::ifstream&) = 0;
	virtual bool isInside(double, double) const = 0;
	virtual void translate(double, double) = 0;
	virtual const Figure* getFigureAt(size_t) const = 0;

public:
	//factory methods ( used for creating objects )
	//they are static, so no instance is needed to
	//call them
	static Figure* createFigure(std::ifstream &);
	static Figure* createFigure(const char *);

	virtual ~Figure(){}; // !!!
};

