#include<iostream>
#include "FootballPlayer.h"

static const char* defaultName = "UNKNOWN";

FootballPlayer::FootballPlayer() : name(nullptr) {

	//default constructor of FootballShirt is already called here

	setDefaultName(); //using the private function

	//just debug info for better example understanding
	//std::cout << "constructor working!\n";
}

//calling constructor of FootballShirt also
FootballPlayer::FootballPlayer(unsigned int rate, const char* realName,
	unsigned int number, const char* name) : rating(rate), shirt(number, name) {

	//constructor with parameters
	//should initialize our data members with the
	//given as parameters

	if (realName == nullptr)
		setDefaultName(); //used not to copy the same code
	else {

		this->name = new char[strlen(realName) + 1];
		strcpy(this->name, realName);
	}

	//std::cout << "constructor working!\n";
}

//calling the copy constructor of shirt
FootballPlayer::FootballPlayer(const FootballPlayer& other) : shirt(other.shirt) {
	
	//in copy constructor we are creating a new
	//object with same data as one, which already exists
	copyFrom(other);
	
	//std::cout << "copy constructor working!\n";
}

FootballPlayer& FootballPlayer::operator=(const FootballPlayer& other){

	//in operator= we have two objects
	//which have already been created
	//and now we want the "this" object
	//to assign the "other" object's data

	if (this != &other) { //checking for self assignment

		shirt = other.shirt; //using the operator=
		//from FootballShirt

		clean();
		copyFrom(other);
		//std::cout << "working inside operator= !\n";
	}

	//we are returning "this", because
	//our clients expect to have the possibility
	//to make thing such as : a = b = c = d;
	return *this;
}


FootballPlayer::~FootballPlayer(){

	clean();
	//std::cout << "destructor working!\n";
}

void FootballPlayer::setDefaultName() {

	name = new char[strlen(defaultName) + 1];
	strcpy(name, defaultName);
}

void FootballPlayer::copyFrom(const FootballPlayer& other) {

	rating = other.rating;
	name = new char[strlen(other.name) + 1];
	strcpy(this->name, other.name);
}

void FootballPlayer::clean() {

	delete[] name;
}

const char * FootballPlayer::getShirtName() const {
	
	return shirt.getName();
}

const char * FootballPlayer::getRealName() const {

	return name;
}

unsigned int FootballPlayer::getRating() const {
	
	return rating;
}
