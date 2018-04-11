#include"Tank.h"
#include"string.h"


Tank::Tank() :name(nullptr), shotPower(0), hitPoints(0) {
	//...
}

Tank::Tank(const char* n, size_t sp, size_t hp) : shotPower(sp), hitPoints(hp) {

	name = new char[strlen(n) + 1];
	strcpy(name, n);
}

Tank::Tank(const Tank& other) {

	copyFrom(other);
}

Tank& Tank::operator=(const Tank& other) {

	if (this != &other) {

		delete[]name;
		copyFrom(other);
	}

	return *this;
}

Tank::~Tank() {

	delete[]name;
}

void Tank::copyFrom(const Tank& other) {

	name = new char[strlen(other.name) + 1];

	strcpy(name, other.name);

	shotPower = other.shotPower;
	hitPoints = other.hitPoints;
}


size_t Tank::getShotPwr() const {

	return shotPower;
}

size_t Tank::getHitPoints() const {

	return hitPoints;
}

void Tank::setHitPoints(size_t nHitP) {

	hitPoints = nHitP;
}

void Tank::serialize(std::ofstream& ofs) const {

	ofs.write((const char*)&shotPower, sizeof(shotPower));
	ofs.write((const char*)&hitPoints, sizeof(hitPoints));

	size_t nameLen = strlen(name);
	ofs.write((const char*)&nameLen, sizeof(int));
	ofs.write(name, nameLen * sizeof(char));
}

void Tank::deserialize(std::ifstream& ifs) {

	//cleaning our object
	delete[]name;
	
	ifs.read((char*)&shotPower, sizeof(shotPower));
	ifs.read((char*)&hitPoints, sizeof(hitPoints));

	size_t nameLen = 0;
	ifs.read((char*)&nameLen, sizeof(int));

	name = new char[nameLen + 1];
	ifs.read(name, nameLen * sizeof(char));

	name[nameLen] = '\0';
}
