#ifndef __ARMY_H__
#define __ARMY_H__

#include"Tank.h"

class Army {

private:

	Tank* tanks;
	size_t curSize;
	size_t capacity;

public:

	//THE BIG FOUR
	Army();
	Army(size_t);
	~Army();
	Army(const Army&);
	Army& operator=(const Army&);

	//help functions
private:

	void copyFrom(const Army&);
	void clean();
	void resize(size_t);

private:

	bool canDestroy(unsigned int);

	unsigned int destroyWithMinShots(unsigned int);

	//interface
public:

	void addTank(const Tank&);
	
	size_t getSize() const;
	size_t getCapacity() const;

	void attackAt(const Tank&);

	bool serialize(const char*);

	bool deserialize(const char*);
};

#endif
