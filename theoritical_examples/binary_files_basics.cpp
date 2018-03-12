#include<fstream>
#include<iostream>

struct Student {

	char name[24];
	unsigned int fn;
};

//дава дължината на вече отворен файл
//в режим за четене, връща get position-ът в началото на файла
size_t getFileLen(std::ifstream& ifs) { //можем да подаваме вече създаден поток на функции

	ifs.seekg(0, std::ios::end); //местим се в края на файла
	size_t size = ifs.tellg(); //взимаме текущата позиция
	ifs.seekg(0, std::ios::beg); //връщаме се в началото

	return size;
}

//записва няколко студента в двоичен файл
//зададен чрез пътия си, като премахва старото съдържание
//на файла
//връща true при успешно записване, false иначе
bool writeStudents(const char* path) {

	std::ofstream ofs(path, std::ios::binary | std::ios::trunc);

	if (!ofs.is_open()) //проверка дали е отворен успешно файлът
		return false;

	//няколко случайни ученици
	Student students[] = {

		{ "Pesho", 85633 },
		{ "Ivan", 45233 },
		{ "Gosho", 71433}

	};

	//записваме ги във файла един по един
	//size_t size = sizeof(students) / sizeof(Student);
	//for (size_t i = 0; i < size; i++)
		//ofs.write((const char*)&students[i], sizeof(Student));

	//нищо не ни пречи да ги запишем и всички наведнъж :
	ofs.write((const char*)students, sizeof(students)); //students е началото на масива
													//няма нужда от & за да вземем адреса

	if (!ofs.good()) // проверяваме дали след операцията потокът е в невалидено състояние
		return false;

	ofs.close(); 
	return true;
}


//чете неизвестен предварително брой студенти записани в двойчен файл
bool readStudents(const char* path) {

	std::ifstream ifs(path, std::ios::binary);

	if (!ifs.is_open())
		return false;

	size_t fileSize = getFileLen(ifs); // общия брой записани байтове

	if (fileSize == 0)
		return false;

	size_t objCount = fileSize / sizeof(Student); // общия брой записи

	Student* students; //тук ще прочетем студентите

	students = new Student[objCount];

	//прочитаме ги от файла в масива 
	ifs.read((char*)students, fileSize);

	if (!ifs) //ако четенето не е било успешно
		return false;

	for (size_t i = 0; i < objCount; i++)
		std::cout << students[i].name << ' '
				  << students[i].fn << std::endl;

	//освобождаваме ресурсите
	delete[] students;
	ifs.close();
	return true;
}


int main() {

	if (writeStudents("students.bin"))
		std::cout << "successfully written!\n";
	else
		std::cout << "error while writing\n";

	std::cout << "trying to read the information ...\n";

	if (!readStudents("students.bin"))	
		std::cout << "error while reading";

	return 0;
}