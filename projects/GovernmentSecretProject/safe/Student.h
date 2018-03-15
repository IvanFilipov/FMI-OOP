#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <fstream>

#include "Constants.h"

//структура представяща един ученик
struct Student {

	char name[MAXL];
	School school;
	double mark;
	
};

//reading a student from the standard input
//and makes basic validation
bool readStudentFromStdin(Student& s);

//outputs info for a student to the standard output
void writeStudentToStdout(const Student& s);

//outputs info for a student to a binary file
void writeStudentToFile(const Student& s, std::ofstream&);

//reading a student from a binary file
void readStudentFromFile(Student& s, std::ifstream&);

#endif // !__STUDENT_H__