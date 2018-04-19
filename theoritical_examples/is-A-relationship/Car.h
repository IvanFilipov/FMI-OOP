#pragma once

#include<iostream>

class Car {

private:

	char* brand;
	char* model;

protected:
	unsigned int price;

public:

	Car();
	Car(const char* , const char*, int = 0);
	Car(const Car& other);
	Car& operator=(const Car& );
	~Car();

protected:

	//only I, my children and their children will
	//have access to these methods
	void copyFrom(const Car&);
	void clear();

public:

	const char* getModel() const;
	void setModel(const char* value);

	void print(std::ostream& = std::cout) const;
};
