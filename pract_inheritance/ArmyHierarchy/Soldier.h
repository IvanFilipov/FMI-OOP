#ifndef __SOLDIER__HEADER__INCLUDED__
#define __SOLDIER__HEADER__INCLUDED__

class Soldier {

protected:

	char* name;
	unsigned short age;
	unsigned short salary;
	unsigned short combatSkills;

public:

	Soldier();
	Soldier(const char *, unsigned short, unsigned short, unsigned short);
	~Soldier();
	Soldier(const Soldier &);
	Soldier& operator=(const Soldier &);


protected:

	void copy(const Soldier &);
	void clean();

public:

	unsigned short getSalary() const;
	unsigned short getCombatSkills() const;
    const char* getName() const;
};

#endif // !__SOLDIER__HEADER__INCLUDED__
