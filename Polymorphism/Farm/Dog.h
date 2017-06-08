#pragma once

#include "Animal.h"

class Dog : public Animal{

public:

	Dog(const char*);
	Dog(const Dog&);
	Dog& operator= (const Dog&);

	virtual void MakeSound();
	virtual Animal* clone();
};

