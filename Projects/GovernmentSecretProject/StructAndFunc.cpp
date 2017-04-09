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
		
		
		//взимаме следващия символ от потока 
		//ако не е нов ред го връщаме обратно,
		//така "почистваме" за да може cin.getline да работи нормално
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


        //четем един по един учениците от хранилището 
        //и ако се налага обноваяваме най - добрият
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

         //забележете кои флагове са вдигнати ,
         //искаме да добавим новия запис , без да нарушаваме предните
         //затова отваряме файла за писане в края
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

        //помощна структура 
        //за да можем да пазим информация за всяко от четирите училища
        //няма проблем структурата да бъде безименна
	struct SchoolInfo{

		double marks; //поле за сумата от всички оценки
		int cnt; //поле за броя на всички ученици

	}schools[4]; //масив представляващ 4рите училища

//инициализираме масива
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
//ако текущото четене е било успешно взимаме предвид новата информация
		if (File) {
			
			//curStudent.school - дава от 0 до 3 - индексите които използваме в масива
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

//големината на целия файл в байтове
	int len = 0;

	File.seekg(0, std::ios::end);
	len = File.tellg();
	File.seekg(0, std::ios::beg);

//броя на записите за ученици = вс байтове / големината на един ученик
	int StCnt = len / sizeof(Student);

//заделяме памет за всички ученици
	Student *AllStudents = new Student[StCnt];

//прочитаме ги
	File.read((char*)AllStudents, sizeof(Student)*StCnt);

	if (!File) {
		cout << "error : while reading the database! \n";
		 delete [] AllStudents;
		return;
	}

	File.close();

//манипулираме оценките в масива
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
	
//записваме обратно новите данни за учениците
	ToWrite.write((char*)AllStudents, sizeof(Student)*StCnt);

	if (ToWrite)
		cout << "successfully done ! \n";
	else
		cout << "error : while writing the new data! \n";


	ToWrite.close();
	delete[] AllStudents;
	
}



