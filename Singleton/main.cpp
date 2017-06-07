#include "Singleton.hpp"


int main() {

	//Singleton s; :(

	std::cout << "wow is this the Matrix ?!\n";

	Singleton::getInstance().Init();
	Singleton::getInstance().PrintContain();

	std::cout << std::endl;


	Singleton* pSingle = &Singleton::getInstance();

	pSingle->Init();
	pSingle->PrintContain();

	return 0;


}