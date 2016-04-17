#pragma once
class SelfCnt{

	static unsigned int ObjCnt;

public:

	static int HowMany();


	SelfCnt();
	SelfCnt(const SelfCnt&);
	~SelfCnt();
};

