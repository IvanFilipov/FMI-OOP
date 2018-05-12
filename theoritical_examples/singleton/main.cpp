#include "Singleton.hpp"


int main() {

	//Singleton s; :(

	std::cout << "wow is this the Matrix ?!\n";

	Singleton::getInstance().init();
	Singleton::getInstance().printContain();

	std::cout << std::endl;


	Singleton* pSingle = &Singleton::getInstance();

	pSingle->init();
	pSingle->printContain();

	return 0;
}