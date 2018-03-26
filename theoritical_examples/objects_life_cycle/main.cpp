#include<iostream>
#include "FootballPlayer.h"

//the example is showing the life-cycle of objects
//and zero functionality

int main() {

	FootballPlayer fp1; //ok creates a football player using default constructor

	FootballPlayer fp2(7, "Cristiano Ronaldo"); //using constructor with params

	{
		FootballPlayer fp(4, "Sergio Ramos");
		
		fp2 = fp; //operator=
 
	} //here the destructor for fp is called
	//and if we hadn't define operator=, it will result in something interesting 

	FootballPlayer fp3 = fp2; //calls copy constructor same as
	//FootballPlayer fp3(fp2); 

	FootballPlayer* squad = new FootballPlayer[10]; //calls 10 default constructors
	delete[] squad; //calls 10 destructors
	
	return 0;
} //here the destrcutors for fp3, fp2 and f1 are called
