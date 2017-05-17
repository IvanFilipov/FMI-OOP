#ifndef __SERGEANT__HEADER__INCLUDED__
#define __SERGEANT__HEADER__INCLUDED__

#include "Soldier.h"

class Commander : public Soldier {

private:

	char * description;
	Soldier* squad;
	unsigned short size;
	unsigned short capacity;

public:

	Commander();
	Commander(const Soldier &,const char * );
	Commander(const char *, unsigned short, unsigned short, unsigned short, const char *);
	~Commander();
	Commander(const Commander &);
	Commander& operator=(const Commander &);

	bool addSoldier(const Soldier &);

	unsigned int getSquadSalary() const;
	unsigned int getSquadSize() const;
	unsigned int getSquadCombatSkills() const;

private:

	void copy(const Commander &);
	bool resize();
	void clean();

};

#endif // !__SERGEANT__HEADER__INCLUDED__
