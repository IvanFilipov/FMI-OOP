#include "SelfCnt.h"

unsigned int SelfCnt::ObjCnt = 0;

SelfCnt::SelfCnt(){

	++ObjCnt;

}

SelfCnt::SelfCnt(const SelfCnt& other) {

	++ObjCnt;

}

SelfCnt::~SelfCnt(){

	--ObjCnt;
}

int SelfCnt::HowMany() {

	return ObjCnt;
}
