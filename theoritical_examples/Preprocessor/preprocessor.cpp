//references http://www.cplusplus.com/doc/tutorial/preprocessor/,
//https://gcc.gnu.org/onlinedocs/gcc-3.0.2/cpp.html#SEC_Top

//for header guards refer to all examples with user defined headers
//for conditional inclusions refer to cond_incl.cpp
//for predefined macros refer to predef_mac.cpp

#include <iostream> //include directive, just paste this file's contain

//macro as a constant
#define MAX_SIZE 24 
int arr[MAX_SIZE]; //we can use it as an ordinary constant

//if directive
#if MAX_SIZE > 16 //MAX_SIZE should be defined, only constant expressions here are allowed
//redefining 
#undef MAX_SIZE 
#define MAX_SIZE 16

int arr1[MAX_SIZE];

#endif

//macros as functions
//notice the large amount of brackets used
//in order to do the right job if
//expression is passed not only a variable
#define min(a,b) (((a) > (b)) ? (b) : (a))

#define max(a,b) (((a) > (b)) ? (a) : (b))

#define sq(x) (x)*(x) 

#define bug_sq(x) x*x //try this with bug_sq(x + 3), what will happen

//multi-line macros
#define abs(x) \
		((x > 0) ? \
		(x) : \
		((-1)*(x)))


#define DEBUG

//argument to string macro
#define toString(x) #x

//concatenation macro
#define concat(x,y) x##y



int main() {

#ifdef DEBUG //if defined
    
	//will include these lines if only
	//DEBUG is defined
	std::cout << "debug mode\n";

#endif // DEBUG

	int a = 10, b = 15;

	int x = -11;


	//macros function usage

	std::cout << toString(MAX_SIZE) << MAX_SIZE << '\n';

	std::cout << toString(max(a, b) =) << max(a, b) << '\n';
	std::cout << toString(min(a, b) = ) << min(a, b) << '\n';
	std::cout << toString(abs(x) = ) << abs(x) << '\n';
	std::cout << toString(sq(x) = ) << sq(x) << '\n';

	std::concat(c, out) << "wow how is this even possible?!\n";

	int catNum = concat(10, 11);
	std::cout << catNum;

	return 0;
}