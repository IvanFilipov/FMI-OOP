#pragma once

#include <iostream>

template<typename T>
class Nvector {

private:

	T* data;
	size_t size;

public:

	//the BIG FOUR
	Nvector();
	~Nvector();
	Nvector& operator=(const Nvector &);
	Nvector(const Nvector &);
	//alternative cctor
	Nvector(size_t);

private:

	void resize(size_t);
	void copy(const Nvector&);

public:

	const T& operator[](size_t) const;
	T& operator[](size_t);

	Nvector& operator+=(const Nvector&);

	Nvector operator+(const Nvector&) const;

	Nvector& operator-=(const Nvector&);

	Nvector operator-(const Nvector&) const;

	Nvector& operator*=(const T&);

	Nvector operator*(const T&) const;

	Nvector& operator/=(const T&);

	Nvector operator/(const T&) const;

	//scalar product
	const T operator%(const Nvector&) const;

	//vector length
	double operator~() const;

	//are two vectors parallel
	bool operator||(const Nvector&) const;

	//are two vectors perpendicular
	bool operator|=(const Nvector&) const;

	void print() const;
};


template<typename T>
Nvector<T>::Nvector() : data(nullptr), size(0) {

}


template<typename T>
Nvector<T>::Nvector(const Nvector<T>& other) {

	copy(other);
}

template<typename T>
Nvector<T>::Nvector(size_t s) {

	data = new T[s];
	size = s;
}

template<typename T>
Nvector<T>::~Nvector() {

	delete[] data;
}

template<typename T>
void Nvector<T>::resize(size_t newSize) {

	if (data == nullptr) {

		data = new T[newSize];
		size = newSize;
	} else {

		T* old = data;
		data = new T[newSize];

		for (size_t i = 0; i < size; i++)
			data[i] = old[i];

		delete[] old;
		size = newSize;
	}
}

template<typename T>
void Nvector<T>::copy(const Nvector& other) {

	data = new T[other.size];
	size = other.size;

	for (size_t i = 0; i < size; i++)
		data[i] = other.data[i];
}

template<typename T>
Nvector<T>& Nvector<T>::operator=(const Nvector<T>& other) {

	if (this != &other) {

		delete[] data;
		copy(other);
	}

	return *this;
}

template<typename T>
const T& Nvector<T>::operator[](size_t pos) const {
	//we can't resize here, because the object is "const"
	if (pos >= size)
		throw std::out_of_range("invalid index");
		
	return data[pos];
}

template<typename T>
T& Nvector<T>::operator[](size_t pos) {

	if (pos >= size)         // here Resize() is used,because in math geo vectors 
		resize(pos + 1);	//A(a1 , a2 , a3 .. an) = B (a1 , a2 ... an,0 ,0 ...) ! 

	return data[pos];
}

template<typename T>
Nvector<T>& Nvector<T>::operator+=(const Nvector<T>& other) {

	if (other.size > size)
		resize(other.size);

	for (size_t i = 0; i < size; i++)
		data[i] += other.data[i];

	return *this;
}

template<typename T>
Nvector<T> Nvector<T>::operator+(const Nvector<T>& other) const {

	Nvector vecSum(*this);
	vecSum += other;

	return vecSum;
}

template<typename T>
Nvector<T>& Nvector<T>::operator-=(const Nvector<T>& other) {

	if (other.size > size)
		resize(other.size);
		
	for (size_t i = 0; i < other.size; i++)
		data[i] -= other.data[i];
	
	return *this;
}

template<typename T>
Nvector<T> Nvector<T>::operator-(const Nvector<T>& other) const {

	Nvector vecSum(*this);
	vecSum -= other;

	return vecSum;
}

template<typename T>
Nvector<T>& Nvector<T>::operator*=(const T& scalar) {

	for (size_t i = 0; i < size; i++)
		data[i] *= scalar;

	return *this;
}

template<typename T>
Nvector<T> Nvector<T>::operator*(const T& scalar) const {

	Nvector scalarVec(*this);
	scalarVec *= scalar;

	return scalarVec;
}

template<typename T>
Nvector<T>& Nvector<T>::operator/=(const T& scalar) {

	for (size_t i = 0; i < size; i++)
		data[i] /= scalar;

	return *this;
}

template<typename T>
Nvector<T> Nvector<T>::operator/(const T& scalar) const {

	Nvector scalarVec(*this);
	scalarVec /= scalar;

	return scalarVec;
}

template<typename T>
const T Nvector<T>::operator%(const Nvector<T>& other) const {

	size_t longer = (size > other.size) ? other.size : size;

	T product(0);

	for (size_t i = 0; i < longer; i++)
		product += data[i] * other.data[i];

	return product;
}

template<typename T>
double Nvector<T>::operator~() const {

	//sqrt(vector * vector)

	return sqrt(operator%(*this));

	//actually calling :
	//return sqrt(this->operator%(*this)); or
	//return sqrt((*this).operator%(*this));
}

template<typename T>
bool Nvector<T>::operator||(const Nvector<T>& other) const {

	if (size != other.size) //we want the same dimensions
		return false;

	T coeff = data[0] / other.data[0];
	
	for (size_t i = 0; i < size; i++)
		if ((data[i] / other.data[i]) != coeff)
			return false;

	return true;
}

//specialization for doubles
template<>
bool Nvector<double>::operator||(const Nvector<double>& other) const {

	if (size != other.size) //we want the same dimensions
		return false;


	double coeff = data[0] / other.data[0];
	double curCoeff;

	const double eps = 0.00001;

	for (size_t i = 0; i < size; i++) {

		curCoeff = data[i] / other.data[i];

		if (abs(coeff - curCoeff) > eps)
			return false;
	}

	return true;
}

template<typename T>
bool Nvector<T>::operator|=(const Nvector<T>& other) const {

	//if scalar product of two vectors
	//is zero => they are perpendicular
	return operator%(other) == 0;
}

template<typename T>
void Nvector<T>::print() const {

	std::cout << "(";

	for (size_t i = 0; i < size - 1; i++)
		std::cout << " " << data[i] << ",";

	std::cout << " " << data[size - 1] << ")\n\n";
}
