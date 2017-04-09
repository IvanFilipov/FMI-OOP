//демонстрираме три варината една програма да изпечата на конзолата
//собствения си код

#include<fstream>
#include<iostream>

int main(){

	

	//дума по дума
	//проблемът тук е ,че четейки с оператора ">>" ние четем до
	//нов ред или интервал и така няма да изпринтим форматирано кода
	//защото новите редове,табулациите и интервалите няма да бъдат прочетени
	std::cout << "first way word by word : \n";

	std::ifstream ifs3("Source.cpp");

//ако не успеем да отворим файла , минаваме към следващия опит
	if (!ifs3.is_open())
		std::cout << "failed !";
	else{

//в този буфер ще държим текущата прочетена дума
		char buffer[128];

//до края на файла чете
		while (!ifs3.eof()){

//взимаме конкретната дума
		      ifs3 >> buffer;
                      
//ако всичко е наред с файловия поток , принтим прочетената дума
                      if (ifs3)
			std::cout << buffer;
			
//почистваме буфера
		       memset(buffer, 0, 1024);
		     
		}

		ifs3.close();
	}



//четем ред по ред , така табулациите и интервалите ще бъдат успешно прочетени и
//в последствие изпечатани , но какво ще стане с новите редове ?
	std::cout << "\n second way line by line : \n";

	std::ifstream ifs2("Source.cpp");

	if (!ifs2.is_open())
		std::cout << "failed !";
	else{

		char buff[1024];

		while (!ifs2.eof()){

//четем с getline , абсолютно аналогично на cin.getline
			ifs2.getline(buff, 1023);

			std::cout << buff;
			
			memset(buff, 0, 1024);
		}

		ifs2.close();
	}




//четем символ по символ , така всичко ще се изпринти едно към едно с кода на програмата ни
	std::cout << "\n third way char by char : \n";
	std::ifstream ifs("Source.cpp");

	if (!ifs.is_open())
		std::cout << "failed !";
	else{

		char c;
		while (!ifs.eof()){

//с функцията get всимаме един символ от потока
			ifs.get(c);

			if (ifs)
			 std::cout << c;

		}

		ifs.close();

	}
	
	return 0;

}
