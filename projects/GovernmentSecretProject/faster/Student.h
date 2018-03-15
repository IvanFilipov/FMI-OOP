#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <fstream>

#include "Constants.h"

//a structure representing information about a student
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
void writeStudentsToFileDB(const Student* s, size_t);

//reading a student array from a binary file
//allocating the memory needed
//returning the size of read records
size_t readStudentsFromFileDB(Student*& s);

#endif // !__STUDENT_H__