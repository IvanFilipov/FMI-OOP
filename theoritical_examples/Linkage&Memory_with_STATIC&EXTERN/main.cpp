#include<iostream>
#include "some_hdr.h"

//all the globals are brought here
//by the include directive

int main() {

	std::cout << "MAX constant in main :"
		 << MAX << std::endl; //constant

	std::cout << "global extern variable in main :"
		<< e_globalVar << std::endl; // we can use this var
							//it is defined in some_src.cpp

	//we can change it here
	e_globalVar = 15;

	std::cout << "global extern variable after change in main :"
	 << e_globalVar << std::endl;

	//and then print its value in some_src.cpp
	std::cout << "global extern variable in some_src.cpp :";
	printExternalVarValue();


    //but with the static variable...
	std::cout << "global static variable in main :"
	 << s_Var << std::endl; // we can use this var
								     //it is defined in the header file

										  
	s_Var ++;  //we can change it here
	std::cout << "global static variable after change in main :"
	 << s_Var << std::endl;

	//and then print its value in some_src.cpp
	std::cout << "global static variable in some_src.cpp :";
	printStaticVarValue(); //oops different value ?!


	std::cout << "calling counting function with static counter 10 times: ";
	for (int i = 10; i > 0; i--)
		count();

	//staticFunction();
	//ooops... defined in some_src.cpp, but not in main.cpp

	return 0;
}