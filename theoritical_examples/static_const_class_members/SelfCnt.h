#ifndef __SELFCNT_H__
#define __SELFCNT_H__

class SelfCnt { 

private:
	
	//one variable per Class, it is the same for
	//each object
	static unsigned int objectsCount;

	//same, but constant
	static const unsigned int MAX;
	
	//a constant, which may be different
	//for different objects
	//so it is "per object"
	const int const_val;

public:

	SelfCnt(const int = 42);
	SelfCnt(const SelfCnt&);
	~SelfCnt();

public:

	//a method which isn't
	//related with particular
	//instance
	static int howMany();

	const int getConst() const;

};

#endif // __SELFCNT_H__
