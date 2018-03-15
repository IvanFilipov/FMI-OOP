#include<fstream>
#include<iostream>
#include<string.h>

const int MAXN = 1024;

struct Student {

	char* name;
	unsigned int fn;
};

//освобождава динамичната памет
void freeStudentMem(Student& s) {

	if (s.name != nullptr)
		delete[] s.name;

	s.name = nullptr;
}

//чете студент от стандартния вход
void readStudentFromStdin(Student& s) {

	static char buff[MAXN];

	char c;
	std::cin.get(c);

	if (c != '\n')
		std::cin.putback(c);

	std::cout << "enter name :\n";
	std::cin.getline(buff, MAXN);

	size_t inputLen = strlen(buff);

	s.name = new char[inputLen + 1];

	//strncpy will not copy the termination zero 
	//by default, so the len is + 1
	strncpy(s.name, buff, inputLen + 1);

	std::cout << "enter fn :\n";
	std::cin >> s.fn;

	memset(buff, 0, MAXN);
}

void writeStudentToStdout(const Student& s) {

	std::cout << s.name << ' ' << s.fn << '\n';
}


void writeStudentToFile(const Student& s, std::ofstream& ofs) {

	//записваме първо факултетния номер
	ofs.write((const char*)&s.fn, sizeof(unsigned int));

	size_t len = strlen(s.name);
	//след това размера на стринга
	ofs.write((const char*)&len, sizeof(size_t));

	//съдържанието на стринга
	ofs.write(s.name, len); //len * sizeof(char) -> len
}

//четем от файла в същия ред, в който сме записали
void readStudentFromFile(Student& s, std::ifstream& ifs) {

	ifs.read((char*)&s.fn, sizeof(unsigned int));

	size_t len = 0;

	ifs.read((char*)&len, sizeof(size_t));

	if (s.name != nullptr)
		delete[] s.name;

	s.name = new char[len + 1]; //mem check maybe

	ifs.read(s.name, len); //len * sizeof(char) -> len

	s.name[len] = '\0';
}


bool writeStudents(const char* path) {

	std::ofstream ofs(path, std::ios::binary | std::ios::trunc);

	if (!ofs.is_open()) //проверка дали е отворен успешно файлът
		return false;

	std::cout << "how many?\n";
	size_t n;
	std::cin >> n;

	Student s = { nullptr , 0 };

	for (size_t i = 0; i < n; i++) {

		readStudentFromStdin(s);

		writeStudentToFile(s, ofs);

		freeStudentMem(s);

		if (!ofs)
			return false;
	}

	ofs.close();
	return true;
}


//чете неизвестен предварително брой студенти записани в двойчен файл
void readStudents(const char* path) {

	std::ifstream ifs(path, std::ios::binary);

	if (!ifs.is_open()) {

		std::cout << "can't open " << path;
		return;
	}

	Student s = { nullptr , 0 }; //тук ще прочитаме студентите един по един

	while (!ifs.eof()) {

		readStudentFromFile(s, ifs);

		if (ifs)
			writeStudentToStdout(s);

		freeStudentMem(s);
	}

	ifs.close();
}


int main() {

	if (writeStudents("students.bin"))
		std::cout << "successfully written!\n";
	else
		std::cout << "error while writing\n";

	std::cout << "trying to read the information ...\n";

	readStudents("students.bin");

	return 0;
}