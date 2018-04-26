#pragma once
#include"Tank.h"

class Army {

private:

	Tank *tanks;
	size_t curSize;
	size_t capacity;

public:

	//THE BIG FOUR
	Army();
	Army(size_t);
	~Army();
	Army(const Army&);
	Army& operator=(const Army&);

	//help functions
private:

	void copyFrom(const Army&);
	void free();
	void resize(size_t NewSize);

	void printTheSituation(size_t, size_t , int, std::ostream& = std::cout) const;

	bool isFreePos(size_t) const;

	//interface
public:

	void pushBack(const Tank&);
	
	size_t getSize() const;
	size_t getCapacity() const;

	void attack(size_t, std::ostream& = std::cout) const;
};