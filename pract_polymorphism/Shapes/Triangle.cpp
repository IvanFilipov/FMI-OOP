#include<iostream>

#include "Triangle.h"

void Triangle::readFromFile(std::ifstream& ifs) {

	ifs >> x1 >> y1
		>> x2 >> y2
		>> x3 >> y3;
}

void Triangle::print() const {

	std::cout << "triangle "
		<< x1 << ' '
		<< y1 << ' '
		<< x2 << ' '
		<< y2 << ' '
		<< x3 << ' '
		<< y3 << '\n';
}

void Triangle::translate(double x, double y) {

	x1 += x;
	y1 += y;

	x2 += x;
	y2 += y;

	x3 += x;
	y3 += y;
}

bool Triangle::isInside(double x, double y) const {

	//doing some serious math out there

	//for each two points from the triangle  we create a line 
	//then check if the third point and the searched one  
	//are both from a + or - side of the line


	//coefficients
	double A = 0 ,B = 0 , C = 0;
	
	B = -(x1 - x2);

	A = y1 - y2;

	C = -(A * x1 + B * y1);

	//line is Ax + By + C = 0 

	//we don't need C 

	//checking if signs are not equal

	// - * - = +  ... + * + = + , only - * + = -

	if ((A * x + B * y + C) * (A * x3 + B * x3 + C) < 0)
		return false;
	
	//repeat for other points

	B = -(x1 - x3);

	A = y1 - y3;

	C = -(A * x1 + B * y1);


	if ((A* x + B * y + C) * (A * x2 + B * x2 + C) < 0)
		return false;


	B = -(x2 - x3);

	A = y2 - y3;

	C = -(A * x2 + B * y2);

	if ((A * x + B * y + C) * (A * x1 + B * x1 + C) < 0)
		return false;

	print();
	return true;
}

const Figure* Triangle::getFigureAt(size_t pos) const {

	if (pos == 0)
		return this;
	else
		return nullptr;
}