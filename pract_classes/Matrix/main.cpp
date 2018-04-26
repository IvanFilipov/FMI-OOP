#include<iostream>

#include "Matrix.h"

int main() {

	try{

		Matrix BiggestEver(10,1000000000);
	} catch(std::exception& e) {
		
		std::cout << "exception caught : "
				  << e.what() << std::endl;
	}

	Matrix A(5, 5);

	A.randomize();

	A.print();

	Matrix B(5, 10);

	B.randomize();

	Matrix C = A.getMultipliedBy(B);

	C.print();


	//trying to touch something that don't even exist
	try {

		C.setAt(7, 7, 11);
	} catch (std::out_of_range& e) {
		
		std::cout   << "exception caught : "
					<< e.what() << std::endl;
	}

	C.print();

	return 0;
}