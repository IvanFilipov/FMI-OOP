#include"Army.h"
#include<iostream>

Army::Army() :tanks(nullptr), curSize(0), capacity(0) {

	/*...*/
}

Army::Army(size_t size) : capacity(size), curSize(size) {

	tanks = new Tank[size];
}


Army::~Army() {

	clean();
}

void Army::clean() {

	delete[] tanks;

	tanks = nullptr;
	curSize = 0;
	capacity = 0;
}


void Army::copyFrom(const Army& other) {

	tanks = new Tank[other.curSize];

	for (size_t i = 0; i < other.curSize; i++) {

		tanks[i] = other.tanks[i];
	}

	curSize = other.curSize;
	capacity = other.capacity;
}


Army::Army(const Army &other) : tanks(nullptr), curSize(0), capacity(0) {

	copyFrom(other);
}

Army& Army::operator=(const Army& other) {

	if (this != &other) {

		clean();
		copyFrom(other);
	}

	return *this;
}

void Army::resize(size_t newCap) {

	Tank *temp = tanks;

	tanks = new Tank[newCap];

	for (size_t i = 0; i < curSize; i++) {

		tanks[i] = temp[i];
	}

	capacity = newCap;

	delete[] temp;
}


void Army::addTank(const Tank& elem) {

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

bool Army::canDestroy(unsigned int targetHitPnts) {

	for (size_t i = 0; i < curSize; i++) {

		if (tanks[i].getShotPwr() > targetHitPnts)
			return true;

		targetHitPnts -= tanks[i].getShotPwr();
	}

	return false;
}

unsigned int Army::destroyWithMinShots(unsigned int targetHitPnts) {

	//pointers to tanks 
	Tank** sortedTanks = new Tank*[curSize];

	//already used tank
	bool* TakenPos = new bool[curSize];

	for (size_t i = 0; i < curSize; i++)
		TakenPos[i] = false;

	size_t sortedPos = 0;
	size_t curBestIndex = 0;
	unsigned int curMaxPwr = 0;

	for (size_t i = 0; i < curSize; i++) {

		curMaxPwr = 0;

		for (size_t j = 0; j < curSize; j++) {

			if ((tanks[j].getShotPwr() > curMaxPwr) && !TakenPos[j]) {

				curMaxPwr = tanks[j].getShotPwr();
				curBestIndex = j;
			}
		}

		TakenPos[curBestIndex] = true;
		sortedTanks[sortedPos++] = &tanks[curBestIndex];
		curBestIndex = 0;
	}

	/* DEBUG INFO
	std::cout << std::endl;
	for (int i = 0; i < CurSize; i++)
		std::cout << sortedTanks[i]->GetShotPwr() << " ";
	std::cout << std::endl;
	*/

	unsigned int shotsTaken = 0;

	do {
		//protects us from underflow of unsigned int type
		if (targetHitPnts < sortedTanks[shotsTaken]->getShotPwr()) {

			shotsTaken++;
			break;
		}

		targetHitPnts -= sortedTanks[shotsTaken]->getShotPwr();
		shotsTaken++;

	} while (targetHitPnts > 0);

	delete[]sortedTanks;
	delete[]TakenPos;

	return shotsTaken;
}

void Army::attackAt(const Tank& t) {

	if (!canDestroy(t.getHitPoints())) {

		std::cout << "the target cannot be destroyed , sir ! ";
		return;
	}

	std::cout << "Processing with the attack ...\n";

	std::cout << "Destroying the target with " << t.getHitPoints()
		<< "hit points required only "
		<< destroyWithMinShots(t.getHitPoints())
		<< " from our tanks to shot,sir !\n";
}

bool Army::serialize(const char* fName) {

	std::ofstream file(fName, std::ios::binary | std::ios::trunc);

	if (!file.is_open()) {

		std::cout << "can't open file\n";
		return false;
	}

	file.write((const char*)&curSize, sizeof(size_t));
	file.write((const char*)&capacity, sizeof(size_t));

	if (!file.good()) {

		std::cout << "error writing\n";
		return false;
	}

	for (size_t i = 0; i < curSize; i++) {

		tanks[i].serialize(file);

		if (!file.good()) {

			std::cout << "error writing\n";
			return false;
		}
	}

	return file.good();
}

bool Army::deserialize(const char *fName) {

	clean();

	std::ifstream file(fName, std::ios::binary);

	if (!file.is_open()) {

		std::cout << "can't open file\n";
		return false;
	}

	file.read((char*)&curSize, sizeof(size_t));
	file.read((char*)&capacity, sizeof(size_t));

	if (!file.good()) {

		std::cout << "error reading\n";
		return false;
	}

	tanks = new Tank[capacity];

	for (size_t i = 0; i < curSize; i++) {

		tanks[i].deserialize(file);

		if (!file.good()) {

			std::cout << "error reading\n";
			clean();
			return;
		}
	}

	if (file.good())
		std::cout << "deserializing successful!\n";

	return file.good();
}




