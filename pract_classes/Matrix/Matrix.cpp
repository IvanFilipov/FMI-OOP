#include"Matrix.h"
#include<iostream>
#include<stdlib.h>
#include<time.h>


Matrix::Matrix() :matrix(nullptr), rows(0), cols(0) {
	//... no work here for us
}

Matrix::Matrix(size_t n, size_t m) : matrix(nullptr) {


//guarding if the allocation fails 
	try {

		init(n, m);
	}
	catch (std::bad_alloc& e) {
		
//if bad_alloc cough, then cleaning everything
		if (matrix != nullptr)
			clean();
//throwing the same exception again
		throw;
	}
}


void Matrix::init(size_t n, size_t m) {

//standard allocation of matrix with n rows и m columns
	rows = n;

	cols = m;

	matrix = new int* [rows];

	//needed if an exception is thrown
	for (int i = 0; i < rows; i++)
		matrix[i] = nullptr;

	//allocating rows
	for (int i = 0; i < rows; i++)
		matrix[i] = new int[cols];

	//if exception is thrown we can't get here
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			matrix[i][j] = 0;
}


Matrix::Matrix(const Matrix& other):matrix(nullptr) {
	
		copyFrom(other);
}

Matrix& Matrix::operator=(const Matrix& other) {

//self assignment check
	if (this != &other) {

//cleaning the old contain
        clean();
//copy the values from the other matrix
		copyFrom(other);
	}

	return *this;
}

Matrix::~Matrix() {

	clean();
}

void Matrix::clean() {

	for (int i = 0; i < rows; i++)
		delete[] matrix[i];

	delete[] matrix;

	matrix = nullptr;
	rows = 0;
	cols = 0;
}

void Matrix::copyFrom(const Matrix& other) {

	try {

		init(other.getRows(), other.getCols());
	} catch (std::bad_alloc&) {

		if (matrix != nullptr)
			clean();

		throw;
	}

//copying elements one by one, it can't be done with memcpy, why?
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			matrix[i][j] = other.matrix[i][j];
}

//fills the matrix with random values
void Matrix::randomize() {

	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			matrix[i][j] = rand() % MAXVAL;
}


bool Matrix::isValid(size_t x, size_t y) const {

	if (x >= rows || y >= cols)
		return false;
	else
     	return true;
}


void Matrix::print() const {

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++)
			printf("%4d ", matrix[i][j]);

		printf("\n\n");
	}
}



int Matrix::getRows() const {

	return rows;
}

int Matrix::getCols() const {

	return cols;
}

int Matrix::getAt(size_t x, size_t y) {

	if (!isValid(x, y))
		throw std::out_of_range("can't be reached!");

	return matrix[x][y];
}

void Matrix::setAt(size_t x, size_t y, int val) {

	if (!isValid(x, y))
		throw std::out_of_range("can't be reached!");

	 matrix[x][y] = val;
}

//we MUST return a copy, not reference, why?
Matrix Matrix::getTranspose()const {

	Matrix T(cols, rows);

	for (int i = 0; i < cols; i++)
		for (int j = 0; j < rows; j++)
			T.matrix[i][j] = matrix[j][i];

//a copy is returned !
	return T;
}

Matrix Matrix::getMultipliedBy(const Matrix &other)const {

	if (cols != other.rows)
		throw std::logic_error("can't be multiplied !");

	Matrix C(rows, other.cols);

	for (int i = 0; i < rows; i++)
		for (int j = 0; j < other.cols; j++) {

			for (int k = 0; k < cols; k++)
				C.matrix[i][j] += matrix[i][k] * other.matrix[k][j];
		}

	return C;
}

void Matrix::normalize() {

	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			if (matrix[i][j])
				matrix[i][j] = 1;
}
