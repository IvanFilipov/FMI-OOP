#include <iomanip>

#include "Farm.h"
#include "Horse.h"
#include "Dog.h"
#include "Duck.h"

const size_t MAX_TYPE_LEN = 8;
const size_t MAX_NAME_LEN = 1024;

//example of the so called "virtual" constructor
Animal* createAnimal(const char* str, const char* name) {
	
	if (str == nullptr)
		return nullptr;

	if (strcmp(str, "dog") == 0)
		return new Dog(name);

	if (strcmp(str, "horse") == 0)
		return new Horse(name);

	if (strcmp(str, "duck") == 0)
		return new Duck(name);

	return nullptr;
}

//some test of the farm class...
int main() {

	Farm myFarm;

	myFarm.addAnimal(new Dog("Sharo"));
	myFarm.addAnimal(new Horse("Philip"));
	myFarm.addAnimal(new Duck("Donald"));
	myFarm.addAnimal(new Horse("Wind"));
	myFarm.addAnimal(new Dog("Rexy"));
	myFarm.addAnimal(new Duck("Uncle Scrooge"));

	std::cout << "myFarm sounds like :\n";
	myFarm.allSounds();

	Farm copyFarm = myFarm;

	std::cout << "\na copy of myFarm sounds like :\n";
	copyFarm.allSounds();

	//now example for using the virtual constructor

	std::cout << "\n\ncreating new farm...\n"
		<< "How many animals do you want?\n";

	char type[MAX_TYPE_LEN];
	char name[MAX_NAME_LEN];
	size_t animalsCnt;
	std::cin >> animalsCnt;

	if (!std::cin) { //handles not number input

		std::cerr << "invalid input!\n";
		return -1;
	}

	Farm userInputFarm;

	std::cout << "\nok, supported types are \"dog\", \"horse\", \"duck\"\n\n";
	for (size_t i = 0; i < animalsCnt; i++) {

		std::cout << "Enter <type> <name> of animal number "
			<< i << std::endl;

		std::cin >> std::setw(MAX_TYPE_LEN) >> type; //first symbols are for the type
		std::cin.getline(name, MAX_NAME_LEN); //rest of the line is for the name

		try {

			userInputFarm.addAnimal(createAnimal(type, name));
			std::cout << "animal successfully added!\n";
		} catch (std::invalid_argument&) {

			std::cerr << "invalid input, animal not added!\n";
		}
	}

	std::cout << "\nyour new farm sounds like :\n";
	userInputFarm.allSounds();

	return 0;
} //destructors of the farms are called and all dynamic memory is freed
