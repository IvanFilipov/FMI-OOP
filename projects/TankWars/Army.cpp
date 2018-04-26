#include<iostream>

#include"Army.h"
#include"Constants.h"

Army::Army() :tanks(nullptr), curSize(0), capacity(0) {

	/*...*/
}

Army::Army(size_t size) : capacity(size), curSize(size) {

	tanks = new Tank[size];
}


Army::~Army() {

	free();
}

void Army::free() {

	delete[] tanks;

	tanks = nullptr;
	curSize = 0;
	capacity = 0;
}


void Army::copyFrom(const Army& other) {

	tanks = new Tank[other.curSize];

	//memcpy(tanks, other.tanks, sizeof(T)*other.CurSize);

	for (int i = 0; i < other.curSize; i++) {

		tanks[i] = other.tanks[i];
	}

	curSize = other.curSize;
	capacity = other.capacity;

}


Army::Army(const Army &other) :tanks(nullptr), curSize(0), capacity(0) {

	copyFrom(other);
}

Army& Army::operator=(const Army& other) {

	if (this != &other) {

		free();
		copyFrom(other);
	}

	return *this;
}

void Army::resize(size_t newCap) {

	Tank *temp = tanks;

	tanks = new Tank[newCap];

	for (int i = 0; i < curSize; i++) {

		tanks[i] = temp[i];
	}

	capacity = newCap;

	delete[] temp;
}


//we can't add a tank on a position where we already have a tank
void Army::pushBack(const Tank& elem) {

	if (!isFreePos(elem.getPos()))
		return;

	if (curSize >= capacity) {

		size_t newCap = (capacity == 0) ? 2 : capacity * 2;
		resize(newCap);
	}

	tanks[curSize++] = elem;
}



size_t Army::getSize() const {

	return curSize;
}


size_t Army::getCapacity() const {

	return capacity;
}


void Army::attack(size_t flagPos, std::ostream& os) const {

	if (curSize == 0)
		os << "there aren't any units available!\n";

	for (int i = 0; i < curSize; i++) {

		int diff = tanks[i].fire(flagPos, os);

		printTheSituation(tanks[i].getPos(), flagPos, diff, os);

		os << "\n the shot has been taken by tank number " << i << " with \n";
		tanks[i].printInfo(os);

		/*
		if (diff == 0) {

			os << "we have got a HIT !\n";
			return;
		}
		*/

	}
}

void Army::printTheSituation(size_t TankPos, size_t FlagPos,
	int diff, std::ostream& os) const {

	bool hit = false;

	if (diff == 0)
		hit = true;

	for (int i = 0; i < CONSOLE_HORIZONTAL; i++) {

		if (i == TankPos) {
			Tank::printUnit(os);
			continue;
		}

		if (i == FlagPos && hit) {
			os << HITSYM;
			continue;
		}

		if (i == FlagPos && !hit) {
			os << FLAGSYM;
			continue;
		}

		if (i == FlagPos + diff && !hit) {
			os << SHOTSYM;
			continue;
		}

		//else ..

		os << GROUNDSYM;
	}
}

bool Army::isFreePos(size_t pos)const {

	for (int i = 0; i < curSize; i++)
		if (tanks[i].getPos() == pos)
			return false;

	return true;
}



