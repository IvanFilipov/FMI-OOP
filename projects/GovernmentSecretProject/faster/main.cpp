#include "./Helpers.h"
#include "./Student.h"

int main() {

	//loading students

	Student* stArr = nullptr;
	
	size_t size = readStudentsFromFileDB(stArr);

	menu(stArr, size);

	delete[] stArr;

	return 0;
}