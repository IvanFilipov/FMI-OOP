#include <iostream>
#include<fstream>
#include "General.h"


bool writeInfo(const General* general, std::ostream& os = std::cout) {

	os << "this army belongs to " << general->getName()
		<< "\nit's description is : " << general->getArmyDesc()
		<< "\ngold needed : " << general->getArmySalary()
		<< "\narmy power : " << general->getArmyCombatSkills()
		<< "\naverage army combat skill level is : " << general->getArmyAverageCombatSkills()
		<< std::endl;
	
	return os.good();
}


int main() {

	//name - age - salary - skills
	Soldier s1("Petur", 25, 600, 20);

	Soldier s2("Asen", 35, 720, 25);

	Soldier s3("Boris", 27, 550, 17);

	Soldier s4("Shishman", 44, 850, 30);

	Soldier s5("IvailoCar", 19, 450, 10);

	Soldier s6("Asparuh", 32, 730, 28);

	Commander c("Stracimir", 24, 666, 23, "FearlessArmy");

	c.addSoldier(s1);
	c.addSoldier(s2);
	c.addSoldier(s3);
	c.addSoldier(s4);
	c.addSoldier(s5);
	c.addSoldier(s6);

	General g("Simeon", 31, 900, 42, "Together we are stronger !");

	g.addComm(c);

	Commander duplicate = c;

	g.addComm(duplicate);

	if (writeInfo(&g))
		std::cout << "successfully wrote to STDOUT" << std::endl;

	General* ptrG = &g;

	std::ofstream ofs("Report.txt");

	if (!ofs.is_open()) {

		std::cerr << "can't open Report.txt!\n";
		return -1;
	}

	if(writeInfo(ptrG, ofs))
		std::cout << "successfully wrote to Report.txt" << std::endl;

	ofs.close();

	return 0;
}