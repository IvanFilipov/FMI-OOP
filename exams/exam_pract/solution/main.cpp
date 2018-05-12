#include <iostream>

#include "Student.h"

int main() {

	Student roberto("Roberto", 85234);

	std::cout << roberto.getFn() << std::endl;
	std::cout << roberto.getName() << std::endl;;

	{
		Student temp = roberto;
	} //temp got destroyed, but roberto should live ...

	std::cout << roberto.getName() << std::endl;

	roberto.setName("Pesho");

	std::cout << roberto.getName() << std::endl;

	//ten pointers
	Student** arr = new Student* [10];

	char name[] = "test_0"; //hack for generating names

	for (int i = 0; i < 10; i++) {

		//each pointer to new Student
		arr[i] = new Student(name, i * i);
		++name[5]; //0->1->2 ...
	}

	for (int i = 0; i < 10; i++)
		std::cout << arr[i]->getName() << std::endl;
	

	//free mem
	for (int i = 0; i < 10; i++)
		delete arr[i];

	delete arr;

	return 0;
}