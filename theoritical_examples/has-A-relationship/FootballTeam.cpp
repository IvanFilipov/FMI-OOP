#include <algorithm>

#include "FootballTeam.h"


FootballTeam::FootballTeam() : team(nullptr), curSize(0), capacity(0) {

	/*...*/
}

//creates a dynamic array with wanted size,
//initialize all values to zero
FootballTeam::FootballTeam(size_t size) : curSize(size), capacity(2 * size) {

	team = new FootballPlayer[capacity];
}


FootballTeam::~FootballTeam() {

	clean();
}

void FootballTeam::clean() {

	delete[] team;

	team = nullptr;
	curSize = 0;
	capacity = 0;
}


void FootballTeam::copyFrom(const FootballTeam& other) {

	team = new FootballPlayer[other.capacity];

	for (size_t i = 0; i < other.curSize; i++)
		team[i] = other.team[i];

	curSize = other.curSize;
	capacity = other.capacity;
}


FootballTeam::FootballTeam(const FootballTeam &other) :
	team(nullptr), curSize(0), capacity(0) {

	copyFrom(other);
}


FootballTeam& FootballTeam::operator=(const FootballTeam& other) {

	if (this != &other) {

		clean();
		copyFrom(other);
	}

	return *this;
}

//allocates new memory for our buffer
//copies all old values
void FootballTeam::resize(size_t newCap) {

	FootballPlayer* temp = team;

	//allocating new memory
	team = new FootballPlayer[newCap];

	for (size_t i = 0; i < curSize; i++)
		team[i] = temp[i];
	
	capacity = newCap;

	delete[] temp;
}


void FootballTeam::pushBack(const FootballPlayer& elem) {

	if (curSize >= capacity) {

		size_t newCap = (capacity == 0) ? 2 : capacity * 2; //handles capacity 0
		resize(newCap);
	}

	team[curSize++] = elem;
}

void FootballTeam::popBack() {

	if (curSize)
		curSize--;
	else
		return; //we will discus "exceptions" letter throw the semester
				//throw std::length_error("already empty!");

	if (curSize * 2 <= capacity) { //downsizing needed

		size_t newCap = ((curSize == 0) ? 0 : capacity / 2);
		resize(newCap);
	}
}


void FootballTeam::setAt(size_t pos, const FootballPlayer& pl) {

	if (pos >= curSize)
		return;
	//throw std::out_of_range("out of range!");

	team[pos] = pl;
}

const FootballPlayer& FootballTeam::getAt(size_t pos) const {

	 //not really the best error handling
	//throw std::out_of_range("out of range!!!");
	return team[pos];
}

void FootballTeam::removeAt(size_t pos, bool isSorted) {

	if (pos >= curSize || curSize == 1) { //just removes the last elem

		popBack();
		return;
	}

	//faster version O(1), but can be unexpected
	//from the class' client
	if (!isSorted) {

		team[pos] = team[curSize - 1];
		popBack();
		return;
	}

	//else ..rolling back all elements
	for (size_t i = pos; i < curSize - 1; i++)
		std::swap(team[i], team[i + 1]);

	popBack();
}

size_t FootballTeam::getSize() const {

	return curSize;
}


size_t FootballTeam::getCapacity() const {

	return capacity;
}

double FootballTeam::getOverall() const {

	unsigned int sum = 0;

	for (size_t i = 0; i < curSize; i++)
		sum += team[i].getRating();

	return sum / curSize;
}