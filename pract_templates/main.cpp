#include "Nvector.hpp"
#include "Rational.h"

//specialization of the method
//because sqrt can't have Rational as parameter
template<>
double Nvector<Rational>::operator~() const {

	return sqrt(operator%(*this).asDouble());
}

template<typename T>
void run_tests() {

	//some tests ..
	Nvector<T> A(3);

	std::cout << "enter three cells of vector A\n";
	std::cin >> A[0] >> A[1] >> A[2];

	std::cout << "A : ";
	A.print();

	Nvector<T> B(A);
	std::cout << "B :";
	B.print();

	B += A;
	std::cout << "B += A // B:";
	B.print();

	A = A + B;
	std::cout << "A = A + B // A:";
	A.print();


	Nvector<T> C = A - B;
	std::cout << "C = A - B // B:";
	C.print();

	std::cout << "C -= A // C:";
	C -= A;
	C.print();

	C *= -1;
	std::cout << "C *= -1 // C:";
	C.print();

	C = A * 3;
	std::cout << "C = A * 3 // C:";
	C.print();

	T scalarProd = A % C;

	std::cout << "scalar product A % C " << scalarProd << '\n';

	//special operators tests

	Nvector<T> vec(4); //1, 2, 3, 4 

	for (int i = 0; i < 4; i++)
		vec[i] = i + 1;

	std::cout << "Vector vec : \n";
	vec.print();
	std::cout << "vec's length : \n" << ~vec << '\n';

	Nvector<T> parVec(4); // a parallel vector to vec
	parVec[0] = 2;
	parVec[1] = 4;
	parVec[2] = 6;
	parVec[3] = 8;

	if (vec || parVec)
		std::cout << "vec and parVec are parallel!\n";
	else
		std::cout << "vec and parVec are not parallel!\n";


	Nvector<T> perpVec(4); // a perpendicular vector to vec
	perpVec[0] = -2;
	perpVec[1] = 1;
	perpVec[2] = -4;
	perpVec[3] = 3;

	if (vec |= perpVec)
		std::cout << "vec and parVec are perpendicular!\n";
	else
		std::cout << "vec and parVec are not perpendicular!\n";
}

int main() {

	std::cout << "-----running tests with INTs-------\n";
	run_tests<int>();
	
	std::cout << "\n\n\n-----running tests with DOUBLEs-------\n";
	run_tests<double>();

	std::cout << "\n\n\n-----running tests with CHARs-------\n";
	run_tests<char>();

	std::cout << "\n\n\n-----running tests with RATIONALs-------\n";
	run_tests<Rational>();

	return 0;
}

