#include"Tank.h"
#include"string.h"

Tank::Tank() :name(nullptr), ShootPower(0), ShellWeight(0), pos(0) {

}

Tank::Tank(const char* n, size_t sp = 0, size_t sw = 0, size_t p = 0) : ShootPower(sp), ShellWeight(sw), pos(p) {

	name = new char[strlen(n) + 1];

	strcpy(name, n);

}

Tank::Tank(const Tank& other) {

	name = new char[strlen(other.name) + 1];

	strcpy(name, other.name);

	ShootPower = other.ShootPower;

	ShellWeight = other.ShellWeight;

	pos = other.pos;

}

Tank& Tank::operator=(const Tank& other) {

	if (this != &other) {
		delete[]name;

		CopyFrom(other);
	}

	return *this;

}

void Tank::CopyFrom(const Tank& other) {

	name = new char[strlen(other.name) + 1];

	strcpy(name, other.name);

	ShootPower = other.ShootPower;

	ShellWeight = other.ShellWeight;

	pos = other.pos;
}



