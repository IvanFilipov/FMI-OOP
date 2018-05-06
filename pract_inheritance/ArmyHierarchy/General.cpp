#include <iostream>
#include "General.h"

static const int reduceWith = 8;
static const unsigned short initialCapacity = 1;

General::General() 
	: description(NULL), army(NULL), size(0), capacity(0) {

}

General::General(const Soldier & warrior, const char * armyDescription)
	: Soldier(warrior), size(0), capacity(initialCapacity),
	description(NULL), army(NULL) {
	

	try {

		description = new char[strlen(armyDescription) + 1];
		strcpy(description, armyDescription);
		army = new Commander[capacity];
	} catch (std::bad_alloc&) {

		//or the General::clean method just could call Soldier::clean  
		Soldier::clean();
		General::clean();

		std::cerr << "Not enough memory to create new army! \n";
		throw;
	}
}

General::General(const char * name, unsigned short age, unsigned short salary, 
	                 unsigned short combatSkills, const char * armyDescription)
	: Soldier(name,age,salary,combatSkills), size(0), capacity(initialCapacity)
	, description(NULL), army(NULL) {
	
	try {

		description = new char[strlen(armyDescription) + 1];
		strcpy(description, armyDescription);
		army = new Commander[capacity];
	} catch (std::bad_alloc&) {

		Soldier::clean();
		General::clean();

		std::cerr << "Not enough memory to create new army! \n";
		throw;
	}
}

General::~General() {

	clean();
}

General::General(const General & warrior)
	: Soldier(warrior), description(nullptr), army(nullptr) {

	try {

		copy(warrior);
	} catch (std::bad_alloc&) {

		Soldier::clean();
		General::clean();
		throw;
	}
}

General& General::operator=(const General& warrior){

	if (this != &warrior) {

		Soldier::operator=(warrior);
		clean();
		copy(warrior);
	}

	return *this;
}

bool General::addComm(const Commander& warrior) {

	if ((*this).getCombatSkills() <= warrior.getCombatSkills())
		return false;

	if (size >= capacity)
		if (!resize()) 
			return false;
	
	army[size++] = warrior;
	return true;
}

unsigned int General::getArmySalary() const {

	unsigned int armySalary = (*this).getSalary();
	
	for (size_t i = 0; i < size; i++)
		armySalary += army[i].getSquadSalary();
	
	return armySalary;
}


unsigned int General::getArmyCombatSkills() const {

	unsigned int armyCombatSkills = (*this).getCombatSkills();

	for (size_t i = 0; i < size; i++)
		armyCombatSkills += army[i].getSquadCombatSkills();

	return armyCombatSkills;
}

unsigned int General::getArmyAverageCombatSkills() const {

	unsigned int combatSkills = getArmyCombatSkills();
	unsigned int armySize = getArmySize();

	return combatSkills / armySize;
}

const char* General::getArmyDesc() const {

	return description;
}

const char* General::getName() const {

	return name;
}

unsigned int General::getArmySize() const {

	unsigned int armySize = 1 ; // the commander

	for (size_t i = 0; i < size; i++)
		armySize += army[i].getSquadSize();

	return armySize;
}

void General::copy(const General& warrior) {

	description = new (std::nothrow) char[strlen(warrior.description) + 1];
	
	if (!description) {

		std::cerr << "Not enough memory to create new commander! \n";
		throw std::bad_alloc();
	}

	strcpy(description, warrior.description);

	capacity = warrior.capacity;
	size = warrior.size;
	army = new(std::nothrow)Commander[capacity];

	if (!army) {

		std::cerr << "Not enough memory to create new army! \n";
		throw std::bad_alloc();
	}

	for (size_t i = 0; i < size; i++)
		army[i] = warrior.army[i];
}


bool General::resize() {

	int biggerCapacity = capacity * 2;
	Commander* biggerArmy = nullptr;

	do {

		try {

			biggerArmy = new Commander[biggerCapacity];
		} catch (std::bad_alloc & e) {

			biggerCapacity -= reduceWith;
		}

	} while ((biggerCapacity > capacity) && !biggerArmy);

	if (!biggerArmy) {

		std::cerr << "Not enough memory to resize the army! \n";
		return false;
	}

	for (size_t i = 0; i < size; i++)
		biggerArmy[i] = army[i];


	delete[] army;
	army = biggerArmy;
	capacity = biggerCapacity;
	return true;
}

void General::clean() {
	
	delete[] description;
	description = nullptr;
	delete[] army;
	army = nullptr;
}