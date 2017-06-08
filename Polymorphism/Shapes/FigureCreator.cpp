#include "stdafx.h"
#include<string>
#include "FigureCreator.h"
#include "Group.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"


Figure* FigureCreator::Create(std::ifstream& ifs){

	std::string buff;

	ifs >> buff;

	if (strcmp(buff.c_str(), "group") == 0){

		return new Group;
	}

	if (strcmp(buff.c_str(), "rect") == 0){

		return new Rectangle;
	}

	if (strcmp(buff.c_str(), "triangle") == 0){

		return new Triangle;
	}

	if (strcmp(buff.c_str(), "circle") == 0) {

		return new Circle;
	}

	return nullptr;


}


Figure* FigureCreator::Create(const char* str){

	
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