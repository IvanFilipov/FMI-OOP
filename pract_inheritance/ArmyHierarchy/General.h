#ifndef __COMMANDER__HEADER__INCLUDED__
#define __COMMANDER__HEADER__INCLUDED__

#include "Commander.h"

class General : public Soldier {

private:

	char * description;      
	Commander* army;
	unsigned short size;
	unsigned short capacity;

public:

	General();
	General(const Soldier &, const char *);
	General(const char *, unsigned short, unsigned short, unsigned short,const char * );
	~General();
	General(const General &);
	General& operator=(const General &);

private:

	unsigned int getArmySize() const;

	void copy(const General &);
	bool resize();
	void clean();

public:

	bool addComm(const Commander &);

	unsigned int getArmySalary() const;
	unsigned int getArmyCombatSkills() const;
	unsigned int getArmyAverageCombatSkills() const;

	const char* getArmyDesc() const;
	const char* getName() const;
};

#endif // !__COMMANDER__HEADER__INCLUDED__
