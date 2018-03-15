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

void writeStudentToStdout(const Student & s) {

	std::cout << s.name << '\n'
		<< " from " << school_toStr(s.school)
		<< " with " << std::setprecision(3) << s.mark;
}

void writeStudentsToFileDB(const Student* stArr, size_t size){

	if (stArr == nullptr || size == 0) {

		std::cout << "nothing to save...\n";
		return;
	}

	std::ofstream fileDB(FILE_NAME, std::ios::binary);

	if (!fileDB.is_open()) {

		std::cout << "error : can't open the database for writing !\n";
		return;
	}

	//writing the updated info
	fileDB.write((char*)stArr, sizeof(Student)*size);

	if (fileDB.good())
		std::cout << "successfully done ! \n";
	else
		std::cout << "error : while writing the new data! \n";

	fileDB.close();
}

size_t readStudentsFromFileDB(Student*& students){

	if (students != nullptr)
		delete[] students;

	std::ifstream fileDB(FILE_NAME, std::ios::binary);

	if (!fileDB.is_open()) {

		std::cout << "error : can't open the database !\n";
		students = nullptr;
		return 0;
	}

	//the length of the file in bytes
	size_t len = 0;

	fileDB.seekg(0, std::ios::end);
	len = fileDB.tellg();
	fileDB.seekg(0, std::ios::beg);

	size_t stCnt = len / sizeof(Student);

	if (stCnt == 0) {

		std::cout << "Empty data base!\n";
		return 0;
	}

	//allocating memory for all students
	students = new (std::nothrow) Student[stCnt];

	if (students == nullptr) {

		std::cout << "Cannot allocate memory!\n";
		return 0;
	}

	//reading them
	fileDB.read((char*)students, sizeof(Student)*stCnt);

	if (!fileDB.good()) {

		std::cout << "error : while reading the database! \n";
		delete[] students;
		students = nullptr;
		return 0;
	}

	std::cout << "successfully loaded the data base!\n";

	fileDB.close();
	return stCnt;
}
