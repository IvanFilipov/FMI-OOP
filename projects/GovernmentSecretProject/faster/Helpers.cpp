#include <iostream>
#include <fstream>
#include <iomanip>

#include "Student.h"
#include "Helpers.h"

using std::cin;
using std::cout;
using std::ifstream;
using std::ofstream;


void menu(Student*& stArr, size_t& size) {

	int option;

	do {

		cout << "\n*********************************************************\n"
			<< "Please enter a a number for the corresponding command:\n"
			<< "1. Add student\n"
			<< "2. Best student information\n"
			<< "3. Schools report\n"
			<< "4. 'improving' a school results\n"
			<< "5. Save everything\n"
			<< "0. Save & Exit the program\n"
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

			writeStudentsToFileDB(stArr, size);
			cout << "Goodbye , thank you for using our application !\n";
			return;

		case 1:

			add(stArr, size);
			break;

		case 2:

			bestStudent(stArr, size);
			break;

		case 3:

			report(stArr, size);
			break;

		case 4:

			corrupt(stArr, size);
			break;

		case 5:
			writeStudentsToFileDB(stArr, size);
			break;

		default:
			cout << "Invalid command , please try again! \n";

		}

		std::cout << std::endl;

	} while (true);
}

void bestStudent(const Student* stArr, size_t size) {

	if (stArr == nullptr || size == 0) {

		cout << "there aren't any students!\n";
		return;
	}

	size_t bestStudentIndex = 0;

	for(size_t i = 0; i < size; i++)
		if (stArr[i].mark - stArr[bestStudentIndex].mark > EPS)
			bestStudentIndex = i; //update


	cout << "The best student in our database is :\n";
	writeStudentToStdout(stArr[bestStudentIndex]);
}

void add(Student*& stArr, size_t& size) {

	Student toAdd;

	if (!readStudentFromStdin(toAdd))
		return;
	
	if (stArr == nullptr) {

		stArr = new (std::nothrow) Student[++size];

		if (stArr == nullptr) {
			
			std::cout << "can't add : no memory !\n";
			size = 0;
			return;
		}

		stArr[0] = toAdd;
		return;
	}

	Student* newMem = new (std::nothrow) Student[size + 1];

	if (newMem == nullptr) {
		
		std::cout << "can't add : no memory !\n";
		return;
	}

	memcpy(newMem, stArr, sizeof(Student) * size);

	newMem[size] = toAdd;

	delete[] stArr;
	stArr = newMem;
	++size;

	std::cout << "Successfully added!\n";
}

void report(const Student* stArr, size_t size) {

	if (stArr == nullptr || size == 0) {

		std::cout << "no data for reporting...\n";
		return;
	}

	//a helper anonymous function
	//used to accumulate data for different schools
	struct {

		double marks; //sum of all marks
		size_t cnt; //number of students

	}schools[SCHOOLS_COUNT] = { 0 }; //an array for all schools

	//old school init
	/*for (size_t i = 0; i < SCHOOLS_COUNT; i++) {

		schools[i].cnt = 0;
		schools[i].marks = 0.0;
	}*/


	for (size_t i = 0; i < size; i++) {

		//accumulating the data, using that curStudet.school maps with schools indexes
		schools[stArr[i].school].marks += stArr[i].mark;
		schools[stArr[i].school].cnt++;
	}	

	//crating a new report, if older exists, then truncating it
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

void corrupt(Student* stArr, size_t size) {

	if (stArr == nullptr || size == 0) {

		std::cout << "no data for corrupting...\n";
		return;
	}

	cout << "Please enter the name of the school which grades you want to \'improve\':\n"
		<< "make sure it is one of : SMG, NTBG, IEG, NFSG : \n";

	School sch = readSchool();

	if (sch == INVALID) {
		cout << "error: invalid input!\n";
		return;
	}

	//manipulating the grades from the array
	for (size_t i = 0; i < size; i++) {

		if (stArr[i].school == sch)
			if (isValidMark(stArr[i].mark + ADJUST))
				stArr[i].mark += ADJUST;
			else
				stArr[i].mark = MAXGRADE; 
	}

	cout << "successfully done ! \n";
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