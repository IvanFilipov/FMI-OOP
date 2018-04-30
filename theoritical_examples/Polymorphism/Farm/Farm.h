#pragma once

#include "Animal.h"

//this class is a polymorphic container
//it has an array of pointer to the base class

class Farm {

private:

	Animal** allAnimals;
	size_t size;

public:

	Farm();
	Farm(const Farm&);
	Farm& operator=(const Farm&);
	~Farm();

	//or we can just disallow operator= and copy ctor
	//if we want our farm to be uncopyable
	//Farm(const Farm&) = delete;
	//Farm& operator=(const Farm&) = delete;

private:

	void clear();

public:

	void addAnimal(Animal*);
	void allSounds();
};

