#include <iostream>
#include <ctype.h>

//not a new type, just a new name
//for an existing one
typedef unsigned long long int ull_int;

const int MAX_SIZE = 1024;

//will move str forward until
//digit is seen, then will return the
//size of the number by characters
size_t getNumPrefixSize(const char*& str){

	size_t len = 0;

	while (*str != '\0' && !isdigit(*str))
		str++;

	while (isdigit(str[len]))
		len++;

	return len;
}

//checks if a part of a string pointed 
//by str is palindrome
bool isPali(const char* str, size_t len) {

	for (size_t i = 0; i <= len / 2; i++)
		if (str[i] != str[len - 1 - i])
			return false;

	return true;
}

ull_int strToLongLongInt(const char* str, size_t len) {

	ull_int num = 0;

	for (size_t i = 0; i < len; i++) {

		num *= 10;
		num += str[i] - '0';
	}

	return num;
}

ull_int getLongestPali(const char* str) {

	size_t numLen = getNumPrefixSize(str);
	size_t bestLen = 0;
	ull_int curLongest = 0;

	while (numLen != 0) {

		if (numLen > bestLen && isPali(str, numLen)) {

			curLongest = strToLongLongInt(str, numLen);
			bestLen = numLen;

			//std::cout << curLongest << std::endl;
		}

		str += numLen;
		numLen = getNumPrefixSize(str);
	}

	return curLongest;
}



int main() {

	char str[MAX_SIZE];

	//std::cin.getline(str, MAX_SIZE);

	strcpy(str, "1221absha128812a88sjs3210123fuuf323");

	std::cout << "longest palindrome in " << str << " is \n"
		<< getLongestPali(str) << std::endl;
	
	return 0;
}