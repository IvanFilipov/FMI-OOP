#include"DynamicArray.h"
#include<iostream>

DynamicArray::DynamicArray() : pData(nullptr), curSize(0), capacity(0) {

	/*...*/
}

//creates a dynamic array with wanted size,
//initialize all values to zero
DynamicArray::DynamicArray(size_t size) : curSize(size), capacity(2 * size) {

   pData = new int[capacity];
   memset(pData, 0, capacity * sizeof(int));
}


DynamicArray::~DynamicArray() {

	clean();
}

void DynamicArray::clean() {

	delete[] pData;

	pData = nullptr;
	curSize = 0;
	capacity = 0;
}


void DynamicArray::copyFrom(const DynamicArray& other) {

	pData = new int[other.capacity];

	memcpy(pData, other.pData, other.curSize * sizeof(int));

	//or
	/*for (int i = 0; i < other.CurSize; i++) {

		data[i] = other.data[i];
	}*/

	curSize = other.curSize;
	capacity = other.capacity;
}


DynamicArray::DynamicArray(const DynamicArray &other) : 
	pData(nullptr), curSize(0), capacity(0) {

	copyFrom(other);
}


DynamicArray& DynamicArray::operator=(const DynamicArray& other) {

	if (this != &other) {
         
		clean();
		copyFrom(other);
	}

	return *this;
}

//allocates new memory for our buffer
//copies all old values
void DynamicArray::resize(size_t newCap) {

	int *temp = pData;

	//allocating new memory
	pData = new int[newCap];

	//copies all old values
	memcpy(pData, temp, curSize * sizeof(int));

	capacity = newCap;

	delete[] temp;
}


void DynamicArray::pushBack(const int elem) {

	if (curSize >= capacity) {

		size_t newCap = (capacity == 0) ? 2 : capacity * 2; //handles capacity 0
		resize(newCap);
	}

	pData[curSize++] = elem;
}

void DynamicArray::popBack() {

	if (curSize)
		curSize--;
	else
		return; //we will discus "exceptions" letter throw the semester
		//throw std::length_error("already empty!");

	if (curSize * 2 <= capacity) { //downsizing needed

		size_t newCap = ((curSize == 0) ? 0 : capacity / 2);
		resize(newCap);
	}
}


void DynamicArray::setAt(size_t pos, const int elem) {

	if (pos >= curSize)
		return;
		//throw std::out_of_range("out of range!");

	pData[pos] = elem;
}

int DynamicArray::getAt(size_t pos) const {

	if (pos >= curSize)
		return -1; //not really the best error handling
		//throw std::out_of_range("out of range!!!");
	return pData[pos];
}

void DynamicArray::removeAt(size_t pos, bool isSorted) {

	if (pos >= curSize || curSize == 1) { //just removes the last elem
		
		popBack();
		return;
	}

	//faster version O(1), but can be unexpected
	//from the class' client
	if (!isSorted) { 

		pData[pos] = pData[curSize - 1];
		popBack();
		return;
	}

	//else ..rolling back all elements
	for (size_t i = pos; i < curSize - 1; i++)
		std::swap(pData[i], pData[i + 1]);

	popBack();
}

size_t DynamicArray::getSize() const {

	return curSize;
}


size_t DynamicArray::getCapacity() const {

	return capacity;
}

void DynamicArray::printInfo() const {

	std::cout << "obj at: Ox" << this
		<< " buffer starts at: Ox" << pData
		<< " length:" << curSize
		<< " capacity:" << capacity << std::endl;
}