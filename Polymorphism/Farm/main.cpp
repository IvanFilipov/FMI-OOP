#include "Farm.h"
#include "Horse.h"
#include "Dog.h"
#include "Duck.h"

int main() {

	Farm myFarm;

	myFarm.AddAnimal(new Dog("Sharo"));
	myFarm.AddAnimal(new Horse("Philip"));
	myFarm.AddAnimal(new Duck("Donald"));
	myFarm.AddAnimal(new Horse("Wind"));
	myFarm.AddAnimal(new Dog("Rexy"));
	myFarm.AddAnimal(new Duck("Uncle Scrooge"));


	std::cout << "myFarm sounds like :\n";
	myFarm.AllSound();

	Farm copyFarm = myFarm;

	std::cout << "\n a copy of myFarm sounds like :\n";
	copyFarm.AllSound();


	return 0;
}
