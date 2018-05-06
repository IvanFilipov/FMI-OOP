#include <iostream>
#include "Soldier.h"


Soldier::Soldier():name(NULL),age(0),salary(0),combatSkills(0) {

}

Soldier::Soldier(const char * soldierName, unsigned short soldierAge,
				unsigned short soldierSalart, unsigned short soldierCombatSkills) {

	name = new char[strlen(soldierName) + 1];
	strcpy(name, soldierName);
	
	age = soldierAge;
	salary = soldierSalart;
	combatSkills = soldierCombatSkills;
}

Soldier::~Soldier() {

	clean();
}

Soldier::Soldier(const Soldier & warrior) {

	copy(warrior);
}

Soldier& Soldier::operator=(const Soldier & warrior) {
	if (this != &warrior) {

		clean();
		copy(warrior);
	}

	return *this;
}

unsigned short Soldier::getSalary() const {

	return salary;
}

unsigned short Soldier::getCombatSkills() const {

	return combatSkills;
}

const char* Soldier::getName() const {

	return name;
}

void Soldier::copy(const Soldier& warrior) {

	name = new char[strlen(warrior.name) + 1];

	strcpy(name, warrior.name);

	age = warrior.age;
	salary = warrior.salary;
	combatSkills = warrior.combatSkills;
}

void Soldier::clean() {

	delete[] name;
	name = nullptr;
}
