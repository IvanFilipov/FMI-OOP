#include"SelfCnt.h"
#include<iostream>

int main() {

	std::cout << "cpp : "
		<< __FILE__ << std::endl;
		
	//calling static methods as functions
	//there is no instace.method() because
	//static methods don't have "this"
	std::cout << "line number : " << __LINE__
		<< " objects count : " 
		<< SelfCnt::howMany() << std::endl;

	SelfCnt* pSel = new SelfCnt[10];

	SelfCnt sf;

	std::cout << "line number : " << __LINE__
		<< " objects count : "
		<< SelfCnt::howMany() << std::endl;

	delete[] pSel;

	std::cout << "line number : " << __LINE__
		<< " objects count : "
		<< SelfCnt::howMany() << std::endl;

	SelfCnt instanceOne(1); //it's constant will be 1
	SelfCnt instanceTwo(2); //it's constant will be 2

	std::cout << "instance ONE has a constant : " 
		<< instanceOne.getConst() << '\n';

	std::cout << "instance TWO has a constant : "
		<< instanceTwo.getConst() << '\n';

	return 0;
}