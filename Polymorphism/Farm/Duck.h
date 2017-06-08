#pragma once
#include "Animal.h"

class Duck : public Animal{

public:

	Duck(const char*);
	Duck(const Duck&);
	Duck& operator= (const Duck&);

	virtual void MakeSound();
	virtual Animal* clone();

};

