#include<iostream>
#include<fstream>

#include"Rational.h"

int main() {

	Rational r;
	std::cout << "r = " << r << std::endl;

	std::cout << "new values : ";
	std::cin >> r;
	std::cout << "r = " << r << std::endl;
	std::cout << "simplified r = " << r.simplified() << std::endl;

	Rational r1(4,8);
	std::cout << "r1 = " << r1 << std::endl ;

	std::cout << "++r1 = " << ++r1 << std::endl;
	std::cout << "r1++ = " << r1++ << std::endl;
	std::cout << "r1 = " << r1 << std::endl;

	std::cout << "--r1 = " << --r1 << std::endl;
	std::cout << "r1-- = " << r1-- << std::endl;
	std::cout << "r1 = " << r1 << std::endl;

	Rational r2(3, 7);
	std::cout << "r2 = " << r2 << std::endl;

	r1 += r2;
	std::cout << "r1 += r2 " << r1 << std::endl;

	r1 -= r2;
	std::cout << "r1 -= r2 " << r1 << std::endl;

	r1 *= r2;
	std::cout << "r1 *= r2 " << r1 << std::endl;

	r1 /= r2;
	std::cout << "r1 /= r2 " << r1 << std::endl;

	Rational res;
	res = r1 + r2;
	std::cout << "r1 + r2 = " << res << std::endl;

	res = r1 - r2;
	std::cout << "r1 - r2 = " << res << std::endl;

	res = r1 * r2;
	std::cout << "r1 * r2 = " << res << std::endl;

	res = r1 / r2;
	std::cout << "r1 / r2 = " << res << std::endl;

	//possible, because implicit constructors are called
	res = r1 + 5;
	std::cout << "r1 + 5 = " << res << std::endl;

	res = 5 + r1;
	std::cout << "5 + r1 = " << res << std::endl;


	//double d = 0.5 * r; // operator double(),  
	//but not a good practice , could be unexpected

	Rational r3(4,2);
	long long p = 2;
	if (r1 != p) // r1 == 2
		std::cout << "wow\n";

	Rational r4(12, 5);

	if (r4 > r3)
		std::cout << r4 << " > " << r3 << std::endl;

	if(r4 != r3)
		std::cout << r4 << " != " << r3 << std::endl;


	return 0;
}