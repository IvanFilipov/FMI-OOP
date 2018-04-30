#pragma once
#include "Animal.h"

class Duck : public Animal {

public:

	Duck(const char*);

public:

	virtual void makeSound();
	virtual Animal* clone();
};

