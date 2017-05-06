#include"Matirx.h"
#include<iostream>

int main() {

	try{

		Matrix BiggestEver(10,1000000000);
	}
	catch(std::exception& e){
		
		std::cout << "exception caught : "
				  << e.what() << std::endl;
	}

	Matrix A(5, 5);

	A.Randomize(5,5);

	A.Print();

	Matrix B;

	B.Randomize(5, 10);

	Matrix C = A.getMultipliedBy(B);

	C.Print();


	//trying to touch something that don't even exist
	try {
		C.SetAt(7, 7, 11);
	}
	catch (std::out_of_range& e) {
		
		std::cout   << "exception caught : "
					<< e.what() << std::endl;
	}


	C.Print();

	return 0;
}