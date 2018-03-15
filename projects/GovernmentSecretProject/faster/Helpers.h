#ifndef __HELPERS_H__
#define __HELPERS_H__

#include "Constants.h"
#include "Student.h"

//interface functions

//the function, which interacts with the user
//working with the in-memory model 
void menu(Student*&, size_t&);

//adding a new record into our array
//allocating new memory each time..
//not the smartest decision, we will learn better
//way of doing so during the semester
void add(Student*&, size_t&);

//prints to the STDOUT info about the best student
void bestStudent(const Student*, size_t);

//writes to file "Report.txt" information about each school 
//formatted as : »Ã≈_Õ¿_”◊»À»Ÿ≈ - ¡–Œ… ”◊≈Õ»÷» | —–≈ƒ≈Õ_”—œ≈’
void report(const Student*,size_t);

//by a school name, increments each student from the data base 
//with the value ADJUST
void corrupt(Student*, size_t);

// helpers

//converts a string into a School's enum type variable
const char* school_toStr(School);

//reads a school name as a string
//returns a variable from the enum type
School readSchool();

//helper to check is a double number between 2.00 and 6.00
bool isValidMark(double);

#endif // !__HELPERS_H__

