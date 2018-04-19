#include<iostream>

#include"DynamicArray.h"

typedef DynamicArray Array;

//an ordinary function that takes an instance of our class
//as parameter
void printArrayContent(const Array& arr) {

	size_t size = arr.getSize();

	for (size_t i = 0; i < size; i++) //printing array's content
		std::cout << ' ' << arr.getAt(i);

	std::cout << std::endl;
}


int main() {

	Array arr(10); //creates an object with allocated memory for at least
	//10 elements

	std::cout << "successfully created an instance : \n";
	arr.printInfo();

	for (int i = 0; i < 10; i++) //filling the array
		arr.setAt(i, i * 5);

	arr.pushBack(42); //adding some new values
	arr.pushBack(666);

	try {

		arr.getAt(150);
	}
	catch (std::exception& e) {

		std::cerr << e.what() << std::endl;
	}

	try {
		while (42) { //non -stop popping back
			arr.popBack();
		}
	}
	catch (std::logic_error& le) {

		std::cerr << le.what() << std::endl;
	}
	
	return 0;
}