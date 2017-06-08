#pragma once

#include "Animal.h"

class Horse : public Animal{

public:

	Horse(const char*);
	Horse(const Horse&);
	Horse& operator= (const Horse&);


	//~Horse(); we don't have our destructor cuz we are gonna use
	// the base class' one
	virtual void MakeSound();
	virtual Animal* clone();

};

