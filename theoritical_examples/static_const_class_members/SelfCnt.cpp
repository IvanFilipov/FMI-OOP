#include "SelfCnt.h"

//static class member's should be
//initialized here ( "only in one .cpp" )
unsigned int SelfCnt::objectsCount = 0;



const unsigned int SelfCnt::MAX = 1024;

SelfCnt::SelfCnt(const int cv) : const_val(cv) { //initialization of constants
					//can only be done while creating them
					//so the only possible way is in
					//the initialization list
	
					
	//const_var = 10; 
	//!!! the initialization can't be done here
	++objectsCount;

}

SelfCnt::SelfCnt(const SelfCnt& other) 
	: const_val(other.const_val) {

	++objectsCount;

}

SelfCnt::~SelfCnt(){

	--objectsCount;
}

int SelfCnt::howMany() {

	return objectsCount;
}

const int SelfCnt::getConst() const {

	return const_val;
}