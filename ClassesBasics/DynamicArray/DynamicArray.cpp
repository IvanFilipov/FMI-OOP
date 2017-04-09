#include"DynamicArray.h"
#include<iostream>

DynamicArray::DynamicArray() :data(nullptr), CurSize(0), Capacity(0) {

	/*...*/
}

DynamicArray::DynamicArray(size_t size):Capacity(size),CurSize(size) {

   data = new int[size];

}


DynamicArray::~DynamicArray() {
	Free();
}

void DynamicArray::Free() {

	delete[] data;

	data = nullptr;
	CurSize = 0;
	Capacity = 0;

}


void DynamicArray::CopyFrom(const DynamicArray& other) {

	data = new int[other.Capacity];

	//memcpy(data, other.data, sizeof(T)*other.CurSize);

	for (int i = 0; i < other.CurSize; i++) {

		data[i] = other.data[i];
	}

	CurSize = other.CurSize;
	Capacity = other.Capacity;

}


DynamicArray::DynamicArray(const DynamicArray &other) :data(nullptr), CurSize(0), Capacity(0) {

	CopyFrom(other);

}


DynamicArray& DynamicArray::operator=(const DynamicArray& other) {

	if (this != &other) {
         
		Free();
		CopyFrom(other);

	}

	return *this;

}

void DynamicArray::Resize(size_t NewCap) {

	int *temp = data;

	data = new int[NewCap];

	for (int i = 0; i < CurSize; i++) {

		data[i] = temp[i];
	}

	Capacity = NewCap;

	delete[] temp;
}


void DynamicArray::PushBack(const int elem) {

	if (CurSize >= Capacity) {

		size_t NewCap = (Capacity == 0) ? 2 : Capacity * 2;
		Resize(NewCap);
	}

	data[CurSize++] = elem;

}

void DynamicArray::PopBack() {

	if (CurSize)
		CurSize--;
	else
		throw std::length_error("already empty!");

	if (CurSize * 2 <= Capacity) {

		size_t NewCap = ((CurSize == 0) ? 0 : Capacity / 2);
		Resize(NewCap);
	}


}


void DynamicArray::SetAt(size_t pos, const int elem) {


	if (pos >= CurSize) {

		throw std::out_of_range("out of range!");

	}

	data[pos] = elem;

}

int DynamicArray::GetAt(size_t pos)const {

	if (pos >= CurSize) {

		throw std::out_of_range("out of range!!!");

	}

	return data[pos];
}

size_t DynamicArray::GetSize()const {

	return CurSize;
}


size_t DynamicArray::GetCapacity()const {

	return Capacity;
}



void DynamicArray::PrintInfo()const {

	std::cout << "obj at: Ox" << this
		<< " buffer starts at: Ox" << data
		<< " length:" << CurSize
		<< " capacity:" << Capacity << std::endl;

}