#include "FootballShirt.h"
#include <iostream>

static const char* defaultName = "UNKNOWN";

FootballShirt::FootballShirt() : name(nullptr), number(0) {

	setDefaultName(); 
}

FootballShirt::FootballShirt(unsigned int number, const char* name) : number(number) {

	if (name == nullptr)
		setDefaultName(); //used not to copy the same code
	else {

		this->name = new char[strlen(name) + 1];

		strcpy(this->name, name);
	}
}

FootballShirt::FootballShirt(const FootballShirt& other) {

	copyFrom(other);
}

FootballShirt& FootballShirt::operator=(const FootballShirt& other) {

	if (this != &other) {

		clean();
		copyFrom(other);
	}

	return *this;
}


FootballShirt::~FootballShirt() {

	clean();
}

void FootballShirt::setDefaultName() {

	name = new char[strlen(defaultName) + 1];
	strcpy(name, defaultName);
}

void FootballShirt::copyFrom(const FootballShirt& other) {

	number = other.number;

	name = new char[strlen(other.name) + 1];
	strcpy(name, other.name);
}

void FootballShirt::clean() {

	delete[] name;
}

const char* FootballShirt::getName() const {

	return name;
}
