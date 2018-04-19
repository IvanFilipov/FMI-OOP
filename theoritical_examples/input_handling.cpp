#include<iostream>
#include<iomanip>

const unsigned int BUFF_SIZE = 24;

int main() {

	char buff[BUFF_SIZE];
	int a, b, c;

	while (1) {

		std::cin >> std::setw(BUFF_SIZE) >> buff;

		if (strcmp(buff, "quit")) { //buff != "quit"
 
			std::cin >> a >> b >> c;

			if (std::cin) {

				std::cout << "went well!\n";
				std::cout << "input was : "
					<< buff << ' '
					<< a << ' '
					<< b << ' '
					<< c << std::endl;
			}
			else {

				std::cout << "wrong input";
				std::cin.clear(); //clear all flags
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //flush until newline
			}

		}
		else {

			break;
		}
	}

	return 0;
}