#include<fstream>
#include<iostream>

int main(){

	

	//word by word
	std::cout << "first way word by word : \n";

	std::ifstream ifs3("Source.cpp");

	if (!ifs3.is_open())
		std::cout << "failed !";
	else{

		char buffer[1024];

		while (!ifs3.eof()){

			ifs3 >> buffer;

			std::cout << buffer;
		}

		ifs3.close();

	}

	//line by line
	std::cout << "\n second way line by line : \n";

	std::ifstream ifs2("Source.cpp");

	if (!ifs2.is_open())
		std::cout << "failed !";
	else{

		char buff[1024];

		while (!ifs2.eof()){

			ifs2.getline(buff, 1023);

			std::cout << buff;
		}

		ifs2.close();
	}



	//char by char
	
	std::cout << "\n third way char by char : \n";
	std::ifstream ifs("Source.cpp");

	if (!ifs.is_open())
		std::cout << "failed !";
	else{

		char c;
		while (!ifs.eof()){

			ifs.get(c);

			if (ifs)
			 std::cout << c;

		}

		ifs.close();

	}
	
	return 0;

}