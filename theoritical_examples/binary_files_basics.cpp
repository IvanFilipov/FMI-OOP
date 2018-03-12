#include<fstream>
#include<iostream>

struct Student {

	char name[24];
	unsigned int fn;
};

//���� ��������� �� ���� ������� ����
//� ����� �� ������, ����� get position-�� � �������� �� �����
size_t getFileLen(std::ifstream& ifs) {

	ifs.seekg(0, std::ios::end); //������ �� � ���� �� �����
	size_t size = ifs.tellg(); //������� �������� �������
	ifs.seekg(0, std::ios::beg); //������� �� � ��������

	return size;
}

//������� ������� �������� � ������� ����
//������� ���� ����� ��, ���� �������� ������� ����������
//�� �����
//����� true ��� ������� ���������, false �����
bool writeStudents(const char* path) {

	std::ofstream ofs(path, std::ios::binary | std::ios::trunc);

	if (!ofs.is_open()) //�������� ���� � ������� ������� ������
		return false;

	//������� �������� �������
	Student students[] = {

		{ "Pesho", 85633 },
		{ "Ivan", 45233 },
		{ "Gosho", 71433}

	};

	//��������� �� ��� ����� ���� �� ����
	//size_t size = sizeof(students) / sizeof(Student);
	//for (size_t i = 0; i < size; i++)
		//ofs.write((const char*)&students[i], sizeof(Student));

	//���� �� �� ����� �� �� ������� � ������ �������� :
	ofs.write((const char*)students, sizeof(students)); //students � �������� �� ������
													//���� ����� �� & �� �� ������ ������

	if (!ofs.good()) // ����������� ���� ���� ���������� ������� � � ���������� ���������
		return false;

	ofs.close(); 
	return true;
}


//���� ���������� ������������� ���� �������� �������� � ������� ����
bool readStudents(const char* path) {

	std::ifstream ifs(path, std::ios::binary);

	if (!ifs.is_open())
		return false;

	size_t fileSize = getFileLen(ifs); // ����� ���� �������� �������

	if (fileSize == 0)
		return false;

	size_t objCount = fileSize / sizeof(Student); // ����� ���� ������

	Student* students; //��� �� �������� ����������

	students = new Student[objCount];

	//��������� �� �� ����� � ������ 
	ifs.read((char*)students, fileSize);

	if (!ifs) //��� �������� �� � ���� �������
		return false;

	for (size_t i = 0; i < objCount; i++)
		std::cout << students[i].name << ' '
				  << students[i].fn << std::endl;

	//������������� ���������
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