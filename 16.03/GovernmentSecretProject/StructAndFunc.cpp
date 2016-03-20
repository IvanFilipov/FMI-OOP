#include"StructAndFunc.h"
#include<iostream>
#include<fstream>
#include<iomanip>

using std::cin;
using std::cout;
using std::ifstream;
using std::ofstream;


void Menu() {

	int option;

	do {
		cout << "\n\n*********************************************************\n"
			<< "Please enter a a number for the corresponding command:\n"
			<< "1.Add student\n"
			<< "2.Best student information\n"
			<< "3.Schools report\n"
			<< "4'improving' a school results\n"
			<< "0.Exit the program \n"
			<< "\n:";

		cin >> option;
		
		char c;
		cin.get(c);
		if (!(c == '\n'))
			cin.putback(c);

		cin.sync();
		cin.clear();

		switch (option) {

		case 0: cout << "Goodbye , thank you for using our application !\n"; return;

		case 1: Add(); break;

		case 2:BestStudent(); break;

		case 3:Report(); break;

		case 4:Corrupt(); break;

		default: cout << "Invalid command , please try again! \n";

		}
	} while (true);


}


const char* School_toStr(School s){

	switch (s){

	case SMG:   return "SMG";
	case NTBG:  return "NTBG";
	case IEG:   return "IEG";
	case NFSG:  return "NFSG";
	default:    return "ERROR";

	}

}

int ReadSchool() {

	char SchoolName[SSIZE + 1];

	cin.getline(SchoolName, SSIZE + 1);

	if (strcmp(SchoolName, "SMG") == 0)
		return 0;


	if (strcmp(SchoolName, "NTBG") == 0)
		return 1;

	if (strcmp(SchoolName, "IEG") == 0)
		return 2;

	if (strcmp(SchoolName, "NFSG") == 0)
		return 3;


	return -1;

}

void BestStudent() {

	Student TheBest = { "",SMG,1.99 };

	Student CurBest;

	ifstream File(FILE_NAME, std::ios::binary);

	if (!File.is_open()) {

		cout << "error : there aren't any students in our database!\n";
		return;
	}


	while (File) {

		File.read((char*)&CurBest, sizeof(Student));

		if (File && CurBest.mark - TheBest.mark > EPS)
			TheBest = CurBest;
	}

	cout << "The best student in our database is :"
		<< TheBest.name << '\n'
		<< " from " << School_toStr(TheBest.school)
		<< " with " << std::setprecision(3) << TheBest.mark;

	File.close();

}



void Add() {


	Student ToAdd;

	cin.sync();

	cout << "Please enter the name of the new student :\n";

	cin.getline(ToAdd.name, MAXL);

	cin.sync();
	cin.clear();

	cout << "Please enter a school for the new student form "
		<< " SMG , NTBG , IEG , NFSG : \n";

	int SchoolIndex = ReadSchool();

	if (SchoolIndex != -1)
		ToAdd.school = (School)SchoolIndex;
	else {
		cout << "error : invalid input";
		return;
	}

	cout << "Please enter the mark of the new student : \n";

	cin.sync();
	cin.clear();

	cin >> ToAdd.mark;


	ofstream File(FILE_NAME, std::ios::binary|std::ios::app);

	File.write((char*)&ToAdd, sizeof(Student));

	if (File)
		cout << "Successfully added !";
	else
		cout << "error : while writing to the database";


	File.close();

}


void Report() {

	Student curStudent;

	struct SchoolInfo{

		double marks;
		int cnt;

	}schools[4];


	for (int i = 0; i < 4; i++) {

		schools[i].cnt = 0;
		schools[i].marks = 0.0;

	}

	ifstream File(FILE_NAME, std::ios::binary | std::ios::in);

	if (!File.is_open()) {
		cout << "error : çan't open the database !\n";
		return;
	}

	while (File){

		File.read((char*)(&curStudent), sizeof(Student));

		if (File) {
			schools[curStudent.school].marks += curStudent.mark;
			schools[curStudent.school].cnt++;
		}
	}

	File.close();

	ofstream Report("Report.txt");

	for (int i = 0; i < 4; i++)
		Report << School_toStr(School(i)) << ' '
		<< std::setprecision(2)
		<< schools[i].marks / schools[i].cnt << '\n';

	Report.close();

}

void Corrupt() {

	cout << "Please enter the name of the school which grades you want to 'improve':\n"
		<< "make sure it is one of : SMG, NTBG, IEG, NFSG : \n";

	int SchoolIndex = ReadSchool();

	if (SchoolIndex == -1) {
		cout << "error: invalid input!\n";
		return;
	}

	ifstream File(FILE_NAME, std::ios::binary | std::ios::in);

	if (!File.is_open()) {
		cout << "error : çan't open the database !\n";
		return;
	}

	int len = 0;

	File.seekg(0, std::ios::end);
	len = File.tellg();
	File.seekg(0, std::ios::beg);

	int StCnt = len / sizeof(Student);

	Student *AllStudents = new Student[StCnt];

	File.read((char*)AllStudents, sizeof(Student)*StCnt);

	if (!File) {
		cout << "error : while reading the database! \n";
		 delete [] AllStudents;
		return;
	}

	File.close();

	for (int i = 0; i < StCnt; i++) {

		if (AllStudents[i].school == SchoolIndex)
			if (AllStudents[i].mark + ADJUST < MAXGRADE)
				AllStudents[i].mark += ADJUST;
			else
				AllStudents[i].mark = MAXGRADE;


	}


	ofstream ToWrite(FILE_NAME, std::ios::binary);

	if (!ToWrite.is_open()) {

		cout << "error : while writing the new data! \n";
		delete[] AllStudents;
		return;

	}

	ToWrite.write((char*)AllStudents, sizeof(Student)*StCnt);

	if (ToWrite)
		cout << "successfully done ! \n";
	else
		cout << "error : while writing the new data! \n";


	ToWrite.close();
	delete[] AllStudents;
	
}



