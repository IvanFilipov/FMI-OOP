#include "Nvector.h"
#include <iostream>

Nvector::Nvector() : data(nullptr), size(0) {
	
}

// exception std::bad_alloc
// if the function can not allocate memory

Nvector::Nvector(const Nvector& vec){

	data = new double[vec.size];

	memcpy(data, vec.data, sizeof(double) * vec.size);

	size = vec.size;
}

// exception std::bad_alloc
// if the function can not allocate memory
Nvector::Nvector(size_t s) {

	data = new double[s];
	size = s;

	memset(data, 0, sizeof(double) * size);
}


Nvector::~Nvector() {

	delete[] data;
}

// exception std::bad_alloc
// if the function can not allocate memory
void Nvector::resize(size_t newSize) { 

	if (data == nullptr) {

		data = new double[newSize];
		size = newSize;

		memset(data, 0, sizeof(double) * size);
	}else {

		double *temp = new double[newSize];

		memcpy(temp, data, sizeof(double) * newSize);

		delete[] data;
		data = temp;

		for (size_t i = size; i < newSize; i++)
			data[i] = 0;

		size = newSize;
	}
}

// exception std::bad_alloc
// if the function can not allocate memory
Nvector& Nvector::operator=(const Nvector& vec){

	if (this == &vec)
		return *this;

	delete[] data;
	size = vec.size;

	data = new double[size];

	memcpy(data, vec.data, size * sizeof(double));

	return *this;
}


const double Nvector::operator[](size_t pos) const {

	return (pos >= size) ?  0 : data[pos];
}

double& Nvector::operator[](size_t pos) {

	if (pos >= size)         // here Resize() is used,because in math geo vectors 
		resize(pos + 1);	//A(a1 , a2 , a3 .. an) = B (a1 , a2 ... an,0 ,0 ...) ! 

	return data[pos];
}


Nvector& Nvector::operator+=(const Nvector& vec) {

	if (vec.size > size)
		resize(vec.size);

		for (size_t i = 0; i < size; i++)
			data[i] += vec.data[i];
		

	return *this;
}


Nvector Nvector::operator+(const Nvector& vec) const {

	Nvector vecSum(*this);

	vecSum += vec;
	
	return vecSum;
}

Nvector& Nvector::operator-=(const Nvector& vec) {

	if (vec.size > size){

		resize(vec.size);

		for (size_t i = 0; i < size; i++)
			data[i] -= vec.data[i];
		

	} else {

		for (size_t i = 0; i < vec.size; i++)
			data[i] -= vec.data[i];
		
	}

	return *this;
}


Nvector Nvector::operator-(const Nvector& vec) const {

	Nvector vecSum(*this);
	vecSum -= vec;

	return vecSum;
}

Nvector& Nvector::operator*=(double scalar) {

	for (size_t i = 0; i < size; i++)
		data[i] *= scalar;

	return *this;
}


Nvector Nvector::operator*(double scalar)const{

	Nvector scalarVec(*this);
	scalarVec *= scalar;

	return scalarVec;
} 

Nvector& Nvector::operator/=(double scalar) {
	 
	for (size_t i = 0; i < size; i++)
		data[i] /= scalar;
	
	return *this;
}


Nvector Nvector::operator/(double scalar) const {

	Nvector scalarVec(*this);
	scalarVec /= scalar;

	return scalarVec;
}


double Nvector::operator%(const Nvector& vec) const {

	size_t longer = (size > vec.size) ? vec.size : size;

	double product = 0;

	for (size_t i = 0; i < longer; i++)
		product += data[i] * vec.data[i];
	
	return product;
}

double Nvector::operator~() const {

	//sqrt(vector * vector)

	return sqrt(operator%(*this));

	//actually calling :
	//return sqrt(this->operator%(*this)); or
	//return sqrt((*this).operator%(*this));
}

bool Nvector::operator||(const Nvector& other) const {

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

bool Nvector::operator|=(const Nvector& other) const {

	//if scalar product of two vectors
	//is zero => they are perpendicular
	return operator%(other) == 0;
}

void Nvector::print() const {

	std::cout << "(";

	for (size_t i = 0; i < size - 1; i++)
		std::cout << " " << data[i] << ",";
	
	std::cout <<" "<<  data[size-1] << ")\n\n";
}
