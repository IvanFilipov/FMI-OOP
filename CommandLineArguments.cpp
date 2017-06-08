#include<iostream>


//output all the arguments , which have been passed through the command line
// form your cmd , shell , PowerShell and etc.
int main(int argc , char * argv []) {

	if (argc == 1) {

		std::cout << "no arguments have been passed only the program exe path\n";
		std::cout << argv[0];

	}

	for (int i = 1; i < argc ; i++) {

		std::cout << "argument " << i << " is : ";
		std::cout << argv[i] << std::endl;

	}

	return 0;
}