#include <cstdio> // printf, perror
#include <cmath> //log
#include <cerrno> // defines errno macro, 
#include <cstring> //strerror
#include <cassert> //assert

//#define NDEBUG //will disable assert macros

int division(int a, int b) {

	assert(b != 0); //checks the condition
	//if it is false, then the macro 
	//expands to an error message and
	//calling std::abort

	return a / b;
}

int main() {

	
	for(int i = 0 ; i < 42; i++)
		printf("value of errno : %d | mapped string : %s\n",
			i, std::strerror(i));

	double num = std::log(-1.0);

	if (errno == EDOM) {

		printf("value of errno : %d | log(-1) failed: %s\n",
			errno, std::strerror(errno));
	}

	//another example
	FILE* f = fopen("non_existent", "r");

	if (f == NULL) {

		printf("value of errno : %d | ", errno);
		perror("fopen() failed");
	} else 
		fclose(f);

	int res = division(10, 0);
	
	return 0;
}