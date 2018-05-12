#include "Student.h"
#include<stdexcept>

//those implementations are up to you...

Student::Student(const char* name, unsigned int fn) : fn(fn), name(nullptr) {

	setName(name);
}

Student::Student(const Student& other) : name(nullptr) {

	setName(other.name);
	fn = other.fn;
}

Student& Student::operator=(const Student & other) {

	if (this != &other) {

		setName(other.name);
		fn = other.fn;
	}

	return *this;
}

Student::~Student() {

	delete[] name;
}

void Student::setName(const char * n) {
	
	if (n == nullptr)
		throw std::invalid_argument("nullptr passed");

	delete[] name;

	size_t s = strlen(n) + 1;
	name = new char[s];
	strcpy_s(name, s, n);
}
