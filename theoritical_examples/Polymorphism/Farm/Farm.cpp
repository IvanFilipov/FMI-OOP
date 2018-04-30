#include "Farm.h"



Farm::Farm() : allAnimals(nullptr) , size(0) {

}

Farm::Farm(const Farm& other){

	allAnimals = new Animal* [other.size]; // allocating memory for all base pointers

	for (int i = 0; i < other.size; i++) {

		allAnimals[i] = other.allAnimals[i]->clone(); // each pointer will point to a
									//clone of the other object 
									//all pointer are Animal* , but the real
									//allocated objects are Horse, Dog or Duck
	}

	size = other.size;
}

Farm& Farm::operator=(const Farm & other) {
	
	if (this != &other) {

		clear();

		allAnimals = new Animal* [other.size]; // allocating memory for all base pointers

		for (int i = 0; i < other.size; i++)
			allAnimals[i] = other.allAnimals[i]->clone();

		size = other.size;
	}

	return *this;
}


Farm::~Farm() {

	clear();
}

void Farm::clear() {

	//calling the virtual destructor of each object
	for (int i = 0; i < size; i++)
		delete allAnimals[i];

	delete[] allAnimals; //deleting all pointers
	allAnimals = nullptr;
	size = 0;
}

void Farm::addAnimal(Animal* newAnimal) {

	if (newAnimal == nullptr)
		throw std::invalid_argument("null pointer passed");


	//memory for + one base pointer
	Animal** newAnimals = new Animal* [size + 1];

	//using the old pointers
	for (int i = 0; i < size; i++)
		newAnimals[i] = allAnimals[i];

	newAnimals[size] = newAnimal;

	size++;

	//cleaning only the array of pointers 
	//not the pointers themselves
	delete [] allAnimals;
	
	allAnimals = newAnimals;
}

void Farm::allSounds() {

	for (int i = 0; i < size; i++)
		allAnimals[i]->makeSound(); // using the polymorphism
									//all animals will make their unique type of sound
}
