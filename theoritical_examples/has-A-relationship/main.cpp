#include<iostream>

#include "FootballTeam.h"

int main() {

	//creating some players
	FootballPlayer fp2(97, "Cristiano Ronaldo", 7, "CR7");
	FootballPlayer fp1(94, "Sergio Ramos", 4, "SR4");
	FootballPlayer fp(15, "Benzema", 9, "B9");

	//testing get functions
	std::cout << "real name : " << fp2.getRealName()
		<< "\nname on shirt : " << fp2.getShirtName()
		<< std::endl;
 
	//creating a team object
	FootballTeam realMadrid;

	//inserting the players
	realMadrid.pushBack(fp2);
	realMadrid.pushBack(fp1);
	realMadrid.pushBack(fp);

	std::cout << "overall of RM is : " 
		<< realMadrid.getOverall();

	return 0;
}
