#include <iostream>
#include <fstream>

int main()
{
	std::ofstream myFile("Student.txt");

	if (!myFile.is_open()) {
		std::cout << "the file cannot be opened / created ! ";
		return -1;
	}

	char name[16];
	std::cout << "Enter name:\n";
	std::cin.getline(name, 16);


	myFile << name << '\n';

	if (myFile.good())
		std::cout << "successfully written\n";

	else {
		std::cout << " error while writing to file !";
		return -1;
	}

	int fn;
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