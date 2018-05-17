#include<iostream>
#include<algorithm>

#include "Rectangle.h"


void Rectangle::readFromFile(std::ifstream &ifs) {

	ifs >> x1 >> y1 
		>> x2 >> y2;
}


void Rectangle::print() const {

	std::cout << "rect "
		<< x1 << ' '
		<< y1 << ' '
		<< x2 << ' '
		<< y2 <<'\n';
}


void Rectangle::translate(double x, double y) {

	x1 += x;
	y1 += y;

	x2 += x;
	y2 += y;
}

bool Rectangle::isInside(double x, double y) const {

	//doing some serious math out there
	
	if ((x >= std::min(x1, x2)) && x <= std::max(x1, x2) &&
		(y >= std::min(y1, y2)) && y <= std::max(y1, y2)) {

		print();
		return true;
	}

	return false;
}


const Figure* Rectangle::getFigureAt(size_t pos) const{

	if (pos == 0)
		return this;
	else
		return nullptr;
}