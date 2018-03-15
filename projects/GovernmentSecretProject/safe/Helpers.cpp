#include <iostream>
#include <fstream>
#include <iomanip>

#include "Student.h"
#include "Helpers.h"

using std::cin;
using std::cout;
using std::ifstream;
using std::ofstream;


void menu() {

	int option;

	do {

		cout << "\n*********************************************************\n"
			<< "Please enter a a number for the corresponding command:\n"
			<< "1. Add student\n"
			<< "2. Best student information\n"
			<< "3. Schools report\n"
			<< "4. 'improving' a school results\n"
			<< "0. Exit the program\n"
			<< "\n*********************************************************\n:";

		cin >> option;

		if (!cin) {

			cin.clear();
			cin.sync();
			option = -1;
		}

		//clearing '\n' symbol 	
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		std::cout << std::endl; //prints new line and flushes
		switch (option) {

		case 0:

			cout << "Goodbye , thank you for using our application !\n";
			return;

		case 1:

			add();
			break;

		case 2:

			bestStudent();
			break;

		case 3:

			report();
			break;

		case 4:

			corrupt();
			break;

		default:
			cout << "Invalid command , please try again! \n";

		}

		std::cout << std::endl;

	} while (true);
}

void bestStudent() {

	Student theBestStudent = { "", INVALID, MINGRADE };

	Student curStudent;

	ifstream fileDB(FILE_NAME, std::ios::binary);

	if (!fileDB.is_open()) {

		cout << "error : there aren't any students in our database!\n";
		return;
	}

	//reading all the students one by one
	//and updating info for the best one
	//if needed
	while (fileDB.good()) { //not EOF and errors

		readStudentFromFile(curStudent, fileDB);

		if (fileDB && curStudent.mark - theBestStudent.mark > EPS)
			theBestStudent = curStudent; //update
	}

	cout << "The best student in our database is :\n";
	writeStudentToStdout(theBestStudent);
		
	fileDB.close();
}

void add() {

	Student toAdd;

	if (!readStudentFromStdin(toAdd))
		return;

	//notice the flags -> append and binary format
	ofstream fileDB(FILE_NAME, std::ios::binary | std::ios::app);

	writeStudentToFile(toAdd, fileDB);

	if (fileDB) //not !fileDB.fail()
		cout << "Successfully added !";
	else
		cout << "error : while writing to the database";

	fileDB.close();
}

void report() {

	Student curStudent;

	//a helper anonymous structure
	//used to accumulate data for different schools
	struct  {

		double marks; //sum of all marks
		size_t cnt; //number of students

	}schools[SCHOOLS_COUNT] = { 0 }; //an array for all schools

	//old school init
	/*for (size_t i = 0; i < SCHOOLS_COUNT; i++) {

		schools[i].cnt = 0;
		schools[i].marks = 0.0;
	}*/

	ifstream fileDB(FILE_NAME, std::ios::binary);

	if (!fileDB.is_open()) {

		cout << "error : can\'t open the database !\n";
		return;
	}

	while (!fileDB.eof()) { //until reaching end of file

		readStudentFromFile(curStudent, fileDB);

		if (fileDB) {

			//accumulating the data, using that curStudet.school maps with schools indexes
			schools[curStudent.school].marks += curStudent.mark;
			schools[curStudent.school].cnt++;
		}
	}
	
	fileDB.close();

	//creating a new report, if older exists, then truncating it
	ofstream rep("report.txt", std::ios::trunc);

	if (!rep.is_open()) {

		std::cout << "something has went wrong with report.txt!\n";
		return;
	}

	for (size_t i = 0; i < SCHOOLS_COUNT; i++)
		if(schools[i].cnt > 0)
			rep << school_toStr(School(i)) << ' '
				<< schools[i].cnt << " | "
				<< std::setprecision(3)
				<< schools[i].marks / schools[i].cnt << '\n';
	
	if (rep)
		std::cout << "Successfully crated report.txt!\n";
	else
		std::cout << "Report can be damaged or incomplete!\n";

	rep.close();
}

void corrupt() {

	cout << "Please enter the name of the school which grades you want to \'improve\':\n"
		<< "make sure it is one of : SMG, NTBG, IEG, NFSG : \n";

	School sch = readSchool();

	if (sch == INVALID) {

		cout << "error: invalid input!\n";
		return;
	}

	//opening for both reading and writing
	std::fstream fileDB(FILE_NAME, std::ios::binary | std::ios::in | std::ios::out);

	if (!fileDB.is_open()) {

		cout << "error : can't open the database !\n";
		return;
	}

	//the length of the file in bytes
	size_t len = 0;

	fileDB.seekg(0, std::ios::end);
	len = fileDB.tellg();
	fileDB.seekg(0, std::ios::beg);

	size_t stCnt = len / sizeof(Student);

	//allocating memory for all students
	Student *allStudents = new (std::nothrow) Student[stCnt];

	if(allStudents == nullptr){

		cout << "error : not enough memory! \n";
		return;
	}
	//reading them
	fileDB.read((char*)allStudents, sizeof(Student) * stCnt);

	if (!fileDB) {

		cout << "error : while reading the database! \n";
		delete[] allStudents;
		return;
	}

	//manipulating the grades from the array
	for (size_t i = 0; i < stCnt; i++) {

		if (allStudents[i].school == sch)
			if (isValidMark(allStudents[i].mark + ADJUST))
				allStudents[i].mark += ADJUST;
			else
				allStudents[i].mark = MAXGRADE; 
	}

	//putting implicitly the get position at beginning
	fileDB.seekp(0, std::ios::beg);
	
	//writing the updated info
	fileDB.write((const char*)allStudents, sizeof(Student) * stCnt);

	if (fileDB)
		cout << "successfully done ! \n";
	else
		cout << "error : while writing the new data! \n";

	fileDB.close();
	delete[] allStudents;
}

bool isValidMark(double mark) {

	if (mark - MAXGRADE > EPS)
		return false;

	if (MINGRADE - mark > EPS)
		return false;

	return true;
}

const char* school_toStr(School s) {

	switch (s) {

	case SMG:   return "SMG";
	case NTBG:  return "NTBG";
	case IEG:   return "IEG";
	case NFSG:  return "NFSG";
	default:    return "ERROR";

	}

}

School readSchool() {

	char schoolName[SSIZE + 1];

	cin.getline(schoolName, SSIZE + 1);

	if (!std::cin) { 

		std::cin.clear();//setting down all fail bits
		//std::cin.sync(); //flushing all characters left
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	if (strcmp(schoolName, "SMG") == 0)
		return SMG;

	if (strcmp(schoolName, "NTBG") == 0)
		return NTBG;

	if (strcmp(schoolName, "IEG") == 0)
		return IEG;

	if (strcmp(schoolName, "NFSG") == 0)
		return NFSG;

	return INVALID;
}