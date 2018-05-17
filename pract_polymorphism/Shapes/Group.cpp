#include <string>
#include <iostream>
#include <iomanip>

#include "Group.h"

void Group::readFromFile(std::ifstream& ifs) {

	char buff[128];

	//reading "in"
	ifs >> std::setw(128) >> buff;

	ifs >> x >> y;

	ifs >> buff;

	do {

		Figure* curFig = Figure::createFigure(buff);

		if (ifs && curFig) {

			vec.push_back(curFig);
			vec.back()->readFromFile(ifs);
			vec.back()->translate(x, y);
		}

		//reading "out"
		ifs >> buff;

	} while (strcmp(buff, "group") != 0);

	//reading "out"
	ifs >> buff;
}


void Group::print() const {
 
	 std::cout << "group " << x << ' ' << y << '\n';

	 for (size_t i = 0; i < vec.getSize(); i++)
		 vec.getAt(i)->print();
	
}

bool Group::isInside(double x, double y) const {
 
	bool inside = false;

	for (size_t i = 0; i < vec.getSize(); i++)
		if (vec.getAt(i)->isInside(x, y))
			inside = true;
	 
	return inside;
}

void Group::translate(double x, double y) {

	this->x += x;
	this->y += y;

	for (size_t i = 0; i < vec.getSize(); i++)
		vec.getAt(i)->translate(x, y);
}


const Figure* Group::getFigureAt(size_t pos) const {

	if (pos == 0)
		return this;


	if (pos - 1 < vec.getSize())
		return vec.getAt(pos-1);
	
	return nullptr;
}