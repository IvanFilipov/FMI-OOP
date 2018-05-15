#include <iostream>
#include <fstream>

const int MAXN = 32;

int main()
{
	std::ofstream myFile("info.txt");

	if (!myFile.is_open()) {
		std::cout << "the file cannot be opened / created ! ";
		return -1;
	}

	char name[MAXN];
	std::cout << "Enter name:\n";
	std::cin.getline(name, MAXN);
	
	//putting the formated data into the file 
	myFile << name << '\n';

	if (myFile.good())
		std::cout << "successfully written\n";
	else {

		std::cout << " error while writing to file !";
		return -1;
	}

	unsigned int fn;
	std::cout << "Enter fn:\n";
	std::cin >> fn;

	myFile << fn;

	if (myFile.good())
		std::cout << "successfully written\n";
	else {
		std::cout << " error while writing to file !";
		return -1;
	}

	std::cout << "file is created\n";

	myFile.close();

	return 0;
}