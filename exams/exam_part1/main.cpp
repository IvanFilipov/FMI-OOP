#include<iostream>
#include "MegaString.h"

int main() {

	std::cout << "***************************************\n\n"
		<< "basic class tests : \n\n";


	MegaString s("ABC");

	std::cout << "test string :" << s 
			  << " at "<< &s << "\n\n";

	MegaString s1 = s;
	std::cout << "copy of tested string :" << s1 
		      << " at " << &s1 << "\n\n";

	MegaString s2;
	std::cout << "empty obj :" << s2
		<< " at " << &s2 << "\n\n";

	s2 = s1;
	std::cout << "s2 = s1 operator= :" << s2
		<< " at " << &s2 << "\n\n";


	MegaString s3("TEST");
	std::cout << "object with text TEST :" << s3
		<< " at " << &s3 << "\n\n";


	std::cout << "***************************************" << "\n\n"
		<< "overloaded operators tests : " << "\n\n";


	std::cout << "string s + s3 : " << s + s3 << "\n\n";
	std::cout << "string s3 * 3 : " << s3 * 3  << "\n\n";
	std::cout << "string 4 * s3 : " << 5 * s3 << "\n\n";
		
	if(s3 == s3)
		std::cout << "string s3 == s3 " << "\n\n";
	
	if (s1 != s3)
		std::cout << "string s1 != s3 " << "\n\n";

	MegaString uTest1("ABCDEFABJ");
	MegaString uTest2("BCDGHJ");

	std::cout << "UNION TEST ABCDEFABJ % BCDGHJ : " << uTest1 % uTest2 << "\n\n";

	MegaString dTest1("ABCDEF");
	MegaString dTest2("BCDGHJ");
	
	std::cout << "DIFFERENCE TEST ABCDEF / BCDGHJ : " << dTest1 / dTest2 << "\n\n";


	return 0;
}