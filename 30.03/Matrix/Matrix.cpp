#include"Matirx.h"
#include<iostream>
#include<stdlib.h>
#include<time.h>

Matrix::Matrix() :matrix(nullptr), rows(0), cols(0) {

	// ...
}

Matrix::Matrix(size_t N, size_t M) {

	try {
		Init(N, M);
	}
	catch (std::bad_alloc&) {

		if (matrix != nullptr)
			Clean();

		throw;
	}
}


void Matrix::Init(size_t N, size_t M) {

	rows = N;

	cols = M;

	matrix = new int*[rows];

	//needed if an exception is thrown
	for (int i = 0; i < rows; i++)
		matrix[i] = nullptr;


	for (int i = 0; i < rows; i++)
		matrix[i] = new int[cols];

	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			matrix[i][j] = 0;

}




Matrix::Matrix(const Matrix& other) {
	
		CopyFrom(other);

}


Matrix& Matrix::operator=(const Matrix& other) {

	if (this != &other) {

		Clean();

	    CopyFrom(other);
	}

	return *this;

}

Matrix::~Matrix() {

	Clean();

}


void Matrix::Clean() {

	for (int i = 0; i < rows; i++)
		delete[] matrix[i];

	delete[]matrix;

	matrix = nullptr;
	rows = 0;
	cols = 0;

}



void Matrix::CopyFrom(const Matrix& other) {

	try {
		Init(other.getRows(), other.getCols());
	}
	catch (std::bad_alloc&) {

		if (matrix != nullptr)
			Clean();
		 
		throw;
	}

	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			matrix[i][j] = other.matrix[i][j];

}

//fills the matrix with random values
void Matrix::Randomize(size_t rows, size_t cols) {

	Clean();
	Init(rows, cols);

	srand(time(NULL));

	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			matrix[i][j] = rand() % MAXVAL;


}


bool Matrix::isValid(size_t x, size_t y)const {

	if (x >= rows || y >= cols)
		return false;
	else
     	return true;
}


void Matrix::Print()const {

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++)
			printf("%3d", matrix[i][j]);

		printf("\n\n");
	}


}



int Matrix::getRows()const {

	return rows;

}

int Matrix::getCols()const {

	return cols;

}

int Matrix::GetAt(size_t x, size_t y) {

	if (!isValid(x, y))
		throw std::out_of_range("can't be reached!");

	return matrix[x][y];

}

void Matrix::SetAt(size_t x, size_t y,int val) {

	if (!isValid(x, y))
		throw std::out_of_range("can't be reached!");

	 matrix[x][y] = val;

}


Matrix Matrix::getTranspose()const {


	Matrix T(cols, rows);


	for (int i = 0; i < cols; i++)
		for (int j = 0; j < rows; j++)
			T.matrix[i][j] = matrix[j][i];


	return T;

}

Matrix Matrix::getMultipliedBy(const Matrix &other)const {


	if (cols != other.rows) {
		throw std::exception("can't be multiplied !");
	}

	Matrix C(rows, other.cols);

	for (int i = 0; i < rows; i++)
		for (int j = 0; j < other.cols; j++) {

			//C.matrix[i][j] = 0;
			for (int k = 0; k < cols; k++)
				C.matrix[i][j] += matrix[i][k] * other.matrix[k][j];
		}

	return C;


}

void Matrix::Normalize() {

	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			if (matrix[i][j])
				matrix[i][j] = 1;

}