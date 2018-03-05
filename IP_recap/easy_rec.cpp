//използвайки рекурсия отпечатваме цифрите на едно int число 
//една по една



#include<iostream>

//в прав ред
void PrintN(unsigned int n){

	if (n >= 10)
		PrintN(n / 10);

	std::cout << n % 10 << std::endl;

}

//в обратен ред
void PrintRevN(unsigned int n){


	std::cout << n % 10 << std::endl;

	if (n /10 )
		PrintRevN(n / 10);

}


int main(){

	unsigned int n = 1234;

	std::cout << "the number : \n";
	PrintN(n);

	std::cout << "the reverse number : \n";
	PrintRevN(n);


	return 0;

}
