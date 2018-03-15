#ifndef __HELPERS_H__
#define __HELPERS_H__

#include "Constants.h"

//interface functions

//the function, which interacts with the user
void menu();

//adding a new record into our data base
void add();

//prints to the STDOUT info about the best student
void bestStudent();

//writes to file "Report.txt" information about each school 
//formatted as : хле_мю_свхкхые - апни свемхжх | япедем_сяоеу
void report();

//by a school name, increments each student from the data base 
//with the value ADJUST
void corrupt();

// helpers

//converts a string into a School's enum type variable
const char* school_toStr(School);

//reads a school name as a string
//returns a variable from the enum type
School readSchool();

//helper to check is a double number between 2.00 and 6.00
bool isValidMark(double);

#endif // !__HELPERS_H__

