#ifndef __FOOTBALLTEAM_H__
#define __FOOTBALLTEAM_H__

#include "FootballPlayer.h"

//as same as ordinary dynamic array, but 
//containing objects not integers
class FootballTeam {

	FootballPlayer* team; //a collection of FootballPlayer objects
	unsigned int curSize;
	unsigned int capacity;

public:


	FootballTeam();
	FootballTeam(size_t);

	FootballTeam(const FootballTeam&);
	FootballTeam& operator=(const FootballTeam&);
	~FootballTeam();

private:

	void clean();
	void copyFrom(const FootballTeam&);
	void resize(size_t);

public:

public:

	void pushBack(const FootballPlayer&);

	const FootballPlayer& getAt(size_t) const;
	//sets a value at wanted index
	void setAt(size_t, const FootballPlayer&);
	//removes the last element
	void popBack();
	//removes element on given index,
	//the second parameter stands for
	//algorithm usage - by passing true
	//the array is sorted, so the client
	//wants it to remain sorted after
	//our remove operation
	void removeAt(size_t, bool);

	size_t getSize() const;
	size_t getCapacity() const;

	double getOverall() const;
};

#endif // !__FOOTBALLTEAM_H__

