#include <iostream>
#include "Commander.h"


static const int reduceWith = 8;
static const unsigned short initialCapacity = 1;

Commander::Commander():description(NULL), squad(NULL), size(0) , capacity(0) {

}

Commander::Commander(const char * name, unsigned short age, unsigned short salary,
				   unsigned short combatSkills, const char * squadDescription)
	: Soldier(name, age, salary, combatSkills), capacity(initialCapacity)
	, size(0) , description(NULL), squad(NULL) {

	try {

		description = new char[strlen(squadDescription) + 1];
		strcpy(description, squadDescription);
	
		squad = new Soldier[capacity]; 
	} catch (std::bad_alloc & e) {

		Soldier::clean();
		Commander::clean();

		std::cerr << "Not enough memory to create new squad! \n";
		throw;
	}
}

Commander::Commander(const Soldier & person, const char * squadDescription)
	: Soldier(person), capacity(initialCapacity)
	, size(0), description(NULL), squad(NULL) {

	try	{

		description = new char[strlen(squadDescription) + 1];
		strcpy(description, squadDescription);

		squad = new Soldier[capacity];
	} catch (std::bad_alloc & e) {

		Soldier::clean();
		Commander::clean();

		std::cerr << "Not enough memory to create new squad! \n";
		throw;
	}
}

Commander::~Commander() {

	clean();
}

Commander::Commander(const Commander & warrior) :
	Soldier(warrior) ,description(NULL), squad(NULL) {

	try {

		copy(warrior);
	} catch (std::bad_alloc&) {

		Soldier::clean();
		Commander::clean();
		throw;
	}
}

Commander& Commander::operator=(const Commander& warrior) {

	if (this != &warrior) {

		Soldier::operator=(warrior);
		clean();
		copy(warrior);
	}

	return *this;
}

bool Commander::addSoldier(const Soldier & warrior) {

	if ((*this).getCombatSkills() <= warrior.getCombatSkills())
		return true;

	if (size >= capacity)
		if (!resize())
			return false;

	squad[size++] = warrior;
	return true;
}

unsigned int Commander::getSquadSalary() const {

	unsigned int squadSalary = (*this).getSalary(); // starting from sergeant's salary

	for (size_t i = 0; i < size; i++)
		squadSalary += squad[i].getSalary();

	return squadSalary;
}

unsigned int Commander::getSquadSize() const {

	return size + 1; // +1 for the sergeant
}

unsigned int Commander::getSquadCombatSkills() const {

	unsigned int squadCombatSkills = (*this).getCombatSkills();

	for (size_t i = 0; i < size; i++)
		squadCombatSkills += squad[i].getCombatSkills();

	return squadCombatSkills;
}

void Commander::copy(const Commander & warrior) {

	description = new (std::nothrow) char[strlen(warrior.description) + 1];

	if (!description) {

		std::cerr << "Not enough memory to create new sergeant! \n";
		throw std::bad_alloc();
	}

	strcpy(description, warrior.description);

	capacity = warrior.capacity;
	size = warrior.size;	
	squad = new(std::nothrow)Soldier[capacity];

	if(!squad) {

		clean();
		std::cerr << "Not enough memory to create new squad! \n";
		throw std::bad_alloc();
	}

	for (size_t i = 0; i < size; i++)
		squad[i] = warrior.squad[i]; //using operator= for Soliders
}

void Commander::clean() {

	delete[] description;
	description = nullptr;
	delete[] squad;
	squad = nullptr;
}

bool Commander::resize() {

	int biggerCapacity = capacity * 2;
	Soldier* biggerSquad = nullptr;

	do {

		try {

			biggerSquad = new Soldier[biggerCapacity];
		} catch (std::bad_alloc & e) {

			biggerCapacity -= reduceWith;
		}

	} while ((biggerCapacity > capacity) && !biggerSquad);

	if (!biggerSquad) {

		std::cerr << "Not enough memory to resize the squad! \n";
		return false;
	}

	for (size_t i = 0; i < size; i++)
		biggerSquad[i] = squad[i];

	delete[] squad;
	squad = biggerSquad;
	capacity = biggerCapacity;
	return true;
}