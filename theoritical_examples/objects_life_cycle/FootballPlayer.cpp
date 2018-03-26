#include<iostream>
#include "FootballPlayer.h"

const char* defaultName = "UNKNOWN";

FootballPlayer::FootballPlayer():name(nullptr), number(0) {

	//the default constructor should initialize
	//our data members with default values

	setDefaultName(); //using the private function

	//just debug info for better example understanding
	std::cout << "constructor working!\n";
}

FootballPlayer::FootballPlayer(unsigned int number, const char* name) : number(number) {

	//constructor with parameters
	//should initialize our data members with the
	//given as parameters

	if (name == nullptr)
		setDefaultName(); //used not to copy the same code
	else {

		this->name = new char[strlen(name) + 1];

		strcpy(this->name, name);
	}

	std::cout << "constructor working!\n";
}

FootballPlayer::FootballPlayer(const FootballPlayer& other){
	

	//in copy constructor we are creating a new
	//object with same data as one, which already exists
	copyFrom(other);
	
	std::cout << "copy constructor working!\n";

}

FootballPlayer& FootballPlayer::operator=(const FootballPlayer& other){

	//in operator= we have two objects
	//which have already been created
	//and now we want the "this" object
	//to assign the "other" object's data

	if (this != &other) { //checking for self assignment

		clean();
		copyFrom(other);

		std::cout << "working inside operator= !\n";
	}

	//we are returning "this", because
	//our clients expect to have the possibility
	//to make thing such as : a = b = c = d;
	return *this;
}


FootballPlayer::~FootballPlayer(){

	//in destructor we have to free all the dynamic
	//allocated memory
	clean();
	std::cout << "destructor working!\n";
}

void FootballPlayer::setDefaultName() {

	//no need of this->name
	//it is assumed
	name = new char[strlen(defaultName) + 1];
	strcpy(name, defaultName);
}

void FootballPlayer::copyFrom(const FootballPlayer& other) {

	this->number = other.number;

	this->name = new char[strlen(other.name) + 1];
	strcpy(this->name, other.name);
}

void FootballPlayer::clean() {

	delete[] name;
}