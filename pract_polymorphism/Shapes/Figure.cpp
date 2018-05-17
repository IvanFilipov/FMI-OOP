#include <iomanip>

#include "Group.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"


Figure* Figure::createFigure(std::ifstream& ifs) {

	char buff[128];

	ifs >> std::setw(128) >> buff;

	if (strcmp(buff, "group") == 0) {

		return new Group;
	}

	if (strcmp(buff, "rect") == 0) {

		return new Rectangle;
	}

	if (strcmp(buff, "triangle") == 0) {

		return new Triangle;
	}

	if (strcmp(buff, "circle") == 0) {

		return new Circle;
	}

	return nullptr;
}


Figure* Figure::createFigure(const char* str){

	
	if (strcmp(str, "group") == 0){

		return new Group;
	}

	if (strcmp(str, "rect") == 0){

		return new Rectangle;
	}

	if (strcmp(str, "triangle") == 0){

		return new Triangle;
	}

	if (strcmp(str, "circle") == 0){

		return new Circle;
	}

	return nullptr;
}