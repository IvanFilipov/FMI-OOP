#ifndef __DYNAMIC_ARRAY_H__
#define __DYNAMIC_ARRAY_H__

class DynamicArray {

private:

	int* pData;
	size_t curSize; //how many actual values are stored
	size_t capacity; //what is the maximum allocated memory in given moment
	static const unsigned int MAX_TRYS; //how many times to retry resize on push_back failure

public:

	//THE BIG FOUR + constructor with parameter
	DynamicArray();
	DynamicArray(size_t);

	DynamicArray& operator=(const DynamicArray&);
	DynamicArray(const DynamicArray&);
	~DynamicArray();

	//help functions
private:

	void copyFrom(const DynamicArray&);
	void clean();
	void resize(size_t);

	//interface
public:

	//adds new element at array's end
	void pushBack(const int);

	//read-write for non-constant object
	int& operator[](size_t);
	//read-write for constant object
	//for build-in types return a copy is
	//the proper approach, for returning 
	//a user defined object -> const T&
	const int operator[](size_t) const;

	//!!! if we want to know when oper[] is
	//used for reading or for writing, then we
	//should use the "Proxy" design pattern

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

	void printInfo() const;
};

#endif