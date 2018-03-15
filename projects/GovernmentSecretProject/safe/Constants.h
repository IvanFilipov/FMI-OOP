#ifndef __CONSTANTS_H__
#define __CONSTANTS_H__

//path to the file with the data base
#define FILE_NAME "students.dat"

const double MAXGRADE = 6.00;

const double MINGRADE = 2.00;

//government's requirement
const double ADJUST = 0.10;

//a little difference for comparing doubles
const double EPS = 0.0001;

//max length of a name 
const size_t MAXL = 24; 

//school's stings max length
const size_t SSIZE = 4;

//enumeration for the schools
enum School {

	INVALID = -1,

	SMG, //0
	NTBG,
	IEG,
	NFSG,

	SCHOOLS_COUNT //4
};

#endif // __CONSTANTS_H__