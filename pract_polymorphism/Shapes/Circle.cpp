#include<iostream>

#include "Circle.h"

void Circle::readFromFile(std::ifstream& ifs) { 

	ifs >> x >> y >> rad;
}


void Circle::print() const {

	std::cout << "circle "
		<< x << " "
		<< y << " "
		<< rad << "\n";
}

void Circle::translate(double x, double y) {

	this->x += x;

	this->y += y;
}

bool Circle::isInside(double x,double y) const {

	//doing some serious math out there

	double dist = sqrt((this->x - x) * (this->x - x)
					+ (this->y - y) * (this->y - y));

	if ((rad - dist) > 0.00001 || rad == dist) {

		this->print();
		return true;
	}

	return false;
}

const Figure* Circle::getFigureAt(size_t pos) const {

	if (pos == 0)
		return this;
	else
		return nullptr;
}