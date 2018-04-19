#include<iostream> //includes <exception>

void fun_throw() {

	throw 42;

	std::cout << "will we get here?!\n";
}

int division(int a, int b) {

	if (b == 0)
		throw std::logic_error("division by zero!");

	return a / b;
}

int main() {

	try {

		throw "throwing a string?!";
	} catch (...) {

		std::cout << "cought in \"catch all\" clause!\n";
	}



	try {

		fun_throw();
	} catch (long int e) {

		std::cout << "cought long int : "<< e << '\n';
	} catch (int e) {

		std::cout << "cought int : " << e << '\n';
	}


	try {

		std::cout << "division(10,0) =" << division(10, 0);
	} catch(std::exception& e) {

		std::cout << "std::exception : " 
			<< e.what() << '\n';
	} catch (std::logic_error& e) {

		std::cout << "std::logic_error : "
			<< e.what() << '\n';
	}

	try {

		while (true)
			new int[100000000ul];

	} catch (std::bad_alloc& e) {
		std::cout << "Allocation failed: " << e.what() << '\n';
	}

	return 0;
}