#include"Army.h"
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


void Army::PushBack(const Tank& elem) {

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

