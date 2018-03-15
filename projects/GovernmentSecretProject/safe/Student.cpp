#include <iostream>
#include <iomanip>

#include "Student.h"
#include "Helpers.h"

bool readStudentFromStdin(Student& s){

	std::cout << "Please enter the name of the new student :\n";

	std::cin.getline(s.name, MAXL);

	if (std::cin.fail()) { //same as !cin, but not as !cin.good

		//std::cin.sync(); //flushing all characters left
		std::cin.clear();//setting down all fail bits
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	std::cout << "Please enter a school for the new student form "
		<< " SMG, NTBG, IEG, NFSG : \n";

	s.school = readSchool();

	std::cout << "Please enter the mark of the new student : \n";

	std::cin >> s.mark;

	//validation :
	if (s.school == INVALID || !isValidMark(s.mark) ) {

		std::cout << "error : invalid input";
		return false;
	}

	return true;
}

void writeStudentToStdout(const Student& s) {

	std::cout << s.name << '\n'
		<< " from " << school_toStr(s.school)
		<< " with " << std::setprecision(3) << s.mark;
}

void writeStudentToFile(const Student& s, std::ofstream& ofs){

	ofs.write((const char*)&s, sizeof(Student));
}

void readStudentFromFile(Student& s, std::ifstream & ifs){

	ifs.read((char*)&s, sizeof(Student));
}
