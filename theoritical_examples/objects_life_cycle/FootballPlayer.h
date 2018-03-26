#ifndef __FOOTBALLPLAYER_H__
#define __FOOTBALLPLAYER_H__

class FootballPlayer{

private:

	unsigned int number;
	char* name; //we have a field with pointer to dynamic memory

public:

	FootballPlayer(); //default constructor
	FootballPlayer(unsigned int, const char*); //constructor with parameters

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
};

#endif

