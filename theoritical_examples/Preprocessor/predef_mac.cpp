// predefined macros
//for more : https://gcc.gnu.org/onlinedocs/gcc-3.0.2/cpp_3.html#SEC20
#include <iostream>

int main(){

	std::cout << "This is the line number " << __LINE__;
	std::cout << " of file " << __FILE__ << ".\n";
	std::cout << "Its compilation began " << __DATE__;
	std::cout << " at " << __TIME__ << ".\n";
	
	return 0;
}