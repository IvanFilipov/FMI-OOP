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

	std::cout << "\narray's content after some set and push operations :\n";
	printArrayContent(arr);
	
	//pop_back test
	//std::cout << arr.getSize();
	arr.popBack();
	//std::cout << arr.getSize();

	std::cout << "\narray's content after pop back operation :\n";
	printArrayContent(arr);

	//removeAt test for unsorted array
	arr.removeAt(3, false);

	std::cout << "array's content after remove at index 3 :\n";
	printArrayContent(arr);
	
	//a sorted array
	Array sortedArr(10);

	for (size_t i = 0; i < 10; i++)
		sortedArr.setAt(i, i * i);

	std::cout << "\n\na sorted array :\n";
	printArrayContent(sortedArr);
	std::cout << "after removing at index 5 : \n";
	sortedArr.removeAt(5, true);
	printArrayContent(sortedArr);

	return 0;
}