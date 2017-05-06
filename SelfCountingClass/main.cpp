#include"SelfCnt.h"
#include<iostream>


int main() {

	std::cout << SelfCnt::HowMany() <<std::endl;

	SelfCnt* pSel = new SelfCnt[10];

	SelfCnt sf;

	std::cout << SelfCnt::HowMany() << std::endl;

	delete[] pSel;


	std::cout << SelfCnt::HowMany() << std::endl;

	return 0;

}