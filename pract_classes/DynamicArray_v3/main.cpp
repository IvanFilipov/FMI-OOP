#include<iostream>

#include"DynamicArray.h"

typedef DynamicArray Array;

//an ordinary function that takes an instance of our class
//as parameter
void printArrayContent(const Array& arr) {

	size_t size = arr.getSize();

	for (size_t i = 0; i < size; i++) //printing array's content
		std::cout << ' ' << arr[i];

	std::cout << std::endl;
}


int main() {

	Array arr(10); //creates an object with allocated memory for at least
	//10 elements

	std::cout << "successfully created an instance : \n";
	arr.printInfo();

	for (int i = 0; i < 10; i++) //filling the array
		arr[i] = i * 5;

	arr.pushBack(42); //adding some new values
	arr.pushBack(666);

	printArrayContent(arr);

	try {

		std::cout << arr[150];
	} catch (const std::exception& e) {

		std::cerr << e.what() << std::endl;
	}

	try {

		while (42)//non -stop popping back
			arr.popBack();

	} catch (const std::logic_error& le) {

		std::cerr << le.what() << std::endl;
	}
	
	return 0;
}