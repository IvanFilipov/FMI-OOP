#include"Nvector.h"
#include <iostream>


int main()
{

	//some tests ..


	Nvector A(3);

	std::cin >> A[0] >> A[1] >> A[2];

	std::cout << "A : ";
	A.Print();


	Nvector B(A);
	std::cout << "B :";
	B.Print();

	B += A;
	std::cout << "B += A // B:";
	B.Print();

	A = A + B;
	std::cout << "A = A + B // A:";
	A.Print();


	Nvector C = A - B;
	std::cout << "C = A - B // B:";
	C.Print();

	std::cout << "C -= A // C:";
	C -= A;
	C.Print();
		
	C *= -1;
	std::cout << "C *= -1 // C:";
	C.Print();

	C = A * 3;
	std::cout << "C = A * 3 // C:";
	C.Print();

	int scalarProd = A%C;

	std::cout << "scalar product A%C " << scalarProd << '\n';


	
	Nvector G(10);

	std::cin >> G[15];
	
	G.Print();

	return 0;
}

