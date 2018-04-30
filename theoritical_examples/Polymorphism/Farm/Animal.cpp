#include "Animal.h"

Animal::Animal(const char * n) {

	if (n == nullptr) {

		//always use same forms of new and delete
		//in our case new[] ... delete[]
		name = new char[1]; 
		*name = '\0';
	} else {

		name = new char[strlen(n) + 1];
		strcpy(name, n);
	}

}

Animal::Animal(const Animal& other) {

	name = new char[strlen(other.name) + 1];
	strcpy(name, other.name);
}

Animal& Animal::operator=(const Animal& other) {
	
	if (this != &other) {

		delete[] name;
		name = new char[strlen(other.name) + 1];
		strcpy(name, other.name);
	}

	return *this;
}

Animal::~Animal() {

	delete[] name;
}
