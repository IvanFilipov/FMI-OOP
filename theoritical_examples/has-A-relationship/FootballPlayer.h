#ifndef __FOOTBALLPLAYER_H__
#define __FOOTBALLPLAYER_H__

#include "FootballShirt.h"

class FootballPlayer {

private:

	FootballShirt shirt; //football player "has-A" football shirt
	char* name; //we have a field with pointer to dynamic memory
	unsigned int rating;

public:

	FootballPlayer(); //default constructor
	FootballPlayer(unsigned int, const char*, unsigned int, const char*); //constructor with parameters

	//if we have a pointer as data member
	//below methods are a MUST
	//if we don't declare them, the compiler
	//will automatically generate them
	//but they will work not as we expect

	FootballPlayer(const FootballPlayer&); //copy constructor
	FootballPlayer& operator=(const FootballPlayer&); //operator=

	~FootballPlayer(); //destructor

private:

	//inside class mechanisms

	void setDefaultName(); //a helper function which
						   //allocates memory and sets name to UNKNOWN

	void copyFrom(const FootballPlayer&); //helper to copy data
										  //from another object
	void clean(); //frees the memory

public:

	//interface function for getting some info
	const char* getShirtName() const;
	const char* getRealName() const;

	unsigned int getRating()const;
};

#endif

