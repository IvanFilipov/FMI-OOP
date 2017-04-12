#include"Army.h"
#include"Constants.h"
#include<iostream>

Army::Army() :tanks(nullptr), CurSize(0), Capacity(0) {

	/*...*/
}

Army::Army(size_t size) : Capacity(size), CurSize(size) {

	tanks = new Tank[size];

}


Army::~Army() {
	Free();
}

void Army::Free() {

	delete[] tanks;

	tanks = nullptr;
	CurSize = 0;
	Capacity = 0;

}


void Army::CopyFrom(const Army& other) {

	tanks = new Tank[other.CurSize];

	//memcpy(tanks, other.tanks, sizeof(T)*other.CurSize);

	for (int i = 0; i < other.CurSize; i++) {

		tanks[i] = other.tanks[i];
	}

	CurSize = other.CurSize;
	Capacity = other.Capacity;

}


Army::Army(const Army &other) :tanks(nullptr), CurSize(0), Capacity(0) {

	CopyFrom(other);

}

Army& Army::operator=(const Army& other) {

	if (this != &other) {

		Free();
		CopyFrom(other);

	}

	return *this;

}

void Army::Resize(size_t NewCap) {


	Tank *temp = tanks;

	tanks = new Tank[NewCap];

	for (int i = 0; i < CurSize; i++) {

		tanks[i] = temp[i];
	}

	Capacity = NewCap;

	delete[] temp;
}


//we can't add a tank on a position where we already have a tank
void Army::PushBack(const Tank& elem) {

	if (!isFreePos(elem.GetPos()))
		return;

	if (CurSize >= Capacity) {

		size_t NewCap = (Capacity == 0) ? 2 : Capacity * 2;
		Resize(NewCap);
	}

	tanks[CurSize++] = elem;

}



size_t Army::GetSize()const {

	return CurSize;
}


size_t Army::GetCapacity()const {

	return Capacity;
}


void Army::Attack(size_t FlagPos, std::ostream& os)const {

	if (CurSize == 0)
		os << "there aren't any units available!\n";

	for (int i = 0; i < CurSize; i++) {

		int diff = tanks[i].Fire(FlagPos, os);

		PrintTheSituation(tanks[i].GetPos(),FlagPos,diff,os);

		os << "\n the shot has been taken by tank number " << i << " with \n";
		tanks[i].PrintInfo(os);

		/*
		if (diff == 0) {

			os << "we have got a HIT !\n";
			return;
		}
		*/

	}


}

void Army::PrintTheSituation(size_t TankPos, size_t FlagPos, int diff,std::ostream& os)const{

	bool hit = false;

	if (diff == 0)
		hit = true;

	for (int i = 0; i < CONSOLE_HORIZONTAL; i++) {

		if (i == TankPos) {
			Tank::PrintUnit(os);
			continue;
		}

		if (i == FlagPos && hit) {
			os << HITSYM;
			continue;
		}

		if (i == FlagPos && !hit) {
			os << FLAGSYM;
			continue;
		}

		if (i == FlagPos + diff && !hit) {
			os << SHOTSYM;
			continue;
		}

		//else ..

		os << GROUNDSYM;

	}

}

bool Army::isFreePos(size_t pos)const {

	for (int i = 0; i < CurSize; i++)
		if (tanks[i].GetPos() == pos)
			return false;

	return true;
}



