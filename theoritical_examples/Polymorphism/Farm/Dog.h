#pragma once

#include "Animal.h"

class Dog : public Animal {

public:
	
	//do we need G3 here?
	Dog(const char*);
	//Dog(const Dog&);
	//Dog& operator= (const Dog&);

	//the compile generated destructor will look exactly
	//as this one
	//virtual ~Dog() {}; 
public:

	virtual void makeSound();
	virtual Animal* clone();
};

