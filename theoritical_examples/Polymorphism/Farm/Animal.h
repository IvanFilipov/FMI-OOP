#pragma once

#include<iostream>

class Animal {

protected:

	char* name;

public:

	Animal(const char*);
	Animal(const Animal&);
	Animal& operator=(const Animal&);
	virtual ~Animal();


public:

	virtual void makeSound() = 0; // pure virtual we can't have objects form this class
								  //only pointers and references

	virtual Animal* clone() = 0; // we will use this method in our inheritance
								 // it will help us to create copies of our dynamic objects 
};

