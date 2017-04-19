#include "Nvector.h"
#include <iostream>

Nvector::Nvector()
{
	data = NULL;
	size = 0;
}

// exception std::bad_alloc
// if the function can not allocate memory

Nvector::Nvector(const Nvector & vec){

	data = new double[vec.size];

	memcpy(data, vec.data, sizeof(double)*vec.size);

	size = vec.size;

}


// exception std::bad_alloc
// if the function can not allocate memory

Nvector::Nvector(int _size){

	data = new double[_size];
	size = _size;

	for (int i = 0; i < size; i++){
		data[i] = 0;
	}

}


Nvector::~Nvector()
{
	delete[] data;
}

// exception std::bad_alloc
// if the function can not allocate memory

void Nvector::Resize(int Nsize){ 

	if (data == NULL){

		data = new double[Nsize];
		size = Nsize;


		memset(data, 0, sizeof(double)*size);

		//for (int i = 0; i < Nsize; i++){

			//data[i] = 0;
		//}

	}
	else{

		double *temp = new double[Nsize];

		memcpy(temp, data, sizeof(double)*Nsize);

		delete[] data;
		data = temp;

		//memset(data+size, 0, sizeof(double)*(Nsize-size));
		for (int i = size; i < Nsize; i++){

			data[i] = 0;
		}

		size = Nsize;
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

	memcpy(data, vec.data, size*sizeof(double));

	return *this;

}


double Nvector::operator[](int pos) const{

	return (pos >= size) ?  0 : data[pos];
		

}

double& Nvector::operator[](int pos){


	if (pos >= size){          // here Resize() is used,because in math geo vectors 
		                       //A(a1 , a2 , a3 .. an) = B (a1 , a2 ... an,0 ,0 ...) ! 
		Resize(pos+1);
	}
 
	return data[pos];
}


Nvector& Nvector::operator+=(const Nvector &vec){

	
	if (vec.size > size)
		Resize(vec.size);

		for (int i = 0; i < size; i++){

			data[i] += vec.data[i];
		}

	return *this;
}


Nvector Nvector::operator+(const Nvector &vec)const{

	Nvector vecSum  (*this);

	vecSum += vec;
	
	return vecSum;
}

Nvector& Nvector::operator-=(const Nvector &vec){


	if (vec.size > size){

		Resize(vec.size);

		for (int i = 0; i < size; i++){

			data[i] -= vec.data[i];
		}

	}
	else {

		for (int i = 0; i < vec.size; i++){

			data[i] -= vec.data[i];
		}
	}

	return *this;
}


Nvector Nvector::operator-(const Nvector &vec)const{

	Nvector vecSum(*this);

	vecSum -= vec;

	return vecSum;
	

}

Nvector& Nvector::operator*=(double scalar){

	for (int i = 0; i < size; i++){

		data[i] *= scalar;
	}

	return *this;
}


Nvector Nvector::operator*(double scalar)const{

	Nvector scalarVec(*this);

	scalarVec *= scalar;

	return scalarVec;
} 

Nvector& Nvector::operator/=(double scalar){

	for (int i = 0; i < size; i++){

		data[i] /= scalar;
	}

	return *this;
}


Nvector Nvector::operator/(double scalar)const{

	Nvector scalarVec(*this);

	scalarVec /= scalar;

	return scalarVec;

}


double Nvector::operator%(const Nvector& vec)const{

	int Ssize = (size > vec.size) ? vec.size : size;

	double ScalarProduct = 0;

	for (int i = 0; i < Ssize; i++){
		ScalarProduct += data[i] * vec.data[i];
	}

	return ScalarProduct;
}

void Nvector::Print() const {

	std::cout << "(";

	for (int i = 0; i < size - 1; i++){

		std::cout << " " << data[i] << ",";
	}

	std::cout <<" "<<  data[size-1] << ")\n\n";
}
