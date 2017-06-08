#pragma once

#include "Figure.h"

class FigureCreator {

public:
	
	static Figure* Create(std::ifstream &);
	static Figure* Create(const char *);

};

