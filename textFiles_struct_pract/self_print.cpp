//МАХНЕТЕ КОМЕНТАРИТЕ ПРЕДИ ДА ПУСКАТЕ ПРИМЕРА

//демонстрираме три варината една програма да изпечата на конзолата
//собствения си код

#include<fstream>
#include<iostream>

const int MAXN = 1024;

int main() {

	//в този буфер ще държим текущата прочетена дума
	char buffer[MAXN] = { 0 };

	//дума по дума
	//проблемът тук е ,че четейки с оператора ">>" ние четем до
	//нов ред или интервал и така няма да изпринтим форматирано кода
	//защото новите редове,табулациите и интервалите няма да бъдат прочетени
	std::cout << "first way word by word : \n";

	std::ifstream ifs("self_print.cpp");

	//ако не успеем да отворим файла, прекратяваме програмата 
	if (!ifs.is_open()) {

		std::cout << "failed openning!";
		return -1;
	}

	//до края на файла четем
	while (!ifs.eof()) {

		//взимаме конкретната дума
		ifs >> buffer;

		//ако всичко е наред с файловия поток , принтим прочетената дума
		if (ifs)
			std::cout << buffer;

		//почистваме буфера
		memset(buffer, 0, MAXN);
	}

	//четем ред по ред , така табулациите и интервалите ще бъдат успешно прочетени и
	//в последствие изпечатани , но какво ще стане с новите редове ?
	std::cout << "\n second way line by line : \n";

	//std::ifstream ifs2("self_print.cpp");
	//we can re-use the ifs object and 
	//to read form the beginning again
	ifs.clear(); //re-setting flag as EOF
	ifs.seekg(0, std::ios::beg);
	

	while (!ifs.eof()) {

		//четем с getline , абсолютно аналогично на cin.getline
		ifs.getline(buffer, MAXN);
		
		if(ifs)
			std::cout << buffer;

		memset(buffer, 0, MAXN);
	}

	ifs.clear();
	ifs.seekg(0, std::ios::beg);

	//четем символ по символ , така всичко ще се изпринти едно към едно с кода на програмата ни
	std::cout << "\n third way char by char : \n";

	char c;
	while (!ifs.eof()) {

		//с функцията get взимаме един символ от потока
		ifs.get(c);

		if (ifs)
			std::cout << c;
	}

	ifs.close();
	return 0;
}
