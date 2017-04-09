#include"DynamicArray.h"
#include<iostream>

typedef DynamicArray Array;


int main() {

	Array arr(10);

	for (int i = 0; i < 10; i++)
		arr.SetAt(i, i * 5);


	arr.PushBack(15);
	arr.PushBack(21);


	for (int i = 0; i < arr.GetSize(); i++)
		std::cout <<' '<< arr.GetAt(i);

	std::cout << arr.GetSize();
	arr.PopBack();
	std::cout << arr.GetSize();

	std::cout << std::endl;

	return 0;
}