#pragma once

class SelfCnt{

private:

	static unsigned int ObjCnt;
	

public:

	static int HowMany();


	SelfCnt();
	SelfCnt(const SelfCnt&);
	~SelfCnt();
};

