#pragma once

#include "Animal.h"

class Horse : public Animal {

public:

	Horse(const char*);
	
public:

	virtual void makeSound();
	virtual Animal* clone();
};

