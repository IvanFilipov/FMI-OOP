#include"Matirx.h"
#include<iostream>

int main() {

	Matrix A(5, 5);

	A.Randomize(5,5);

	A.Print();

	Matrix B;

	B.Randomize(5, 10);

	Matrix C = A.getMultipliedBy(B);

	C.Print();


	//trying to touch something that not even exist
	try {
		C.SetAt(7, 7, 11);
	}
	catch (std::out_of_range& e) {
		
		std::cout << e.what();
	}


	C.Print();

	return 0;
}