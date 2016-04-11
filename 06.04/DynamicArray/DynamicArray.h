#pragma once
class DynamicArray {

private:

	int *data;
	size_t CurSize;
	size_t Capacity;

public:

	//THE BIG FOUR
	DynamicArray();
	DynamicArray(size_t);
	~DynamicArray();
	DynamicArray(const DynamicArray&);
	DynamicArray& operator=(const DynamicArray&);

	//help functions
private:

	void CopyFrom(const DynamicArray&);
	void Free();
	void Resize(size_t NewSize);

	//interface
public:
	void PushBack(const int);
	int GetAt(size_t)const;
	void SetAt(size_t, const int);
	
	//const T& operator[](size_t)const;
	//T& operator[](size_t);

	size_t GetSize()const;
	size_t GetCapacity()const;

	void PrintInfo()const;
};

