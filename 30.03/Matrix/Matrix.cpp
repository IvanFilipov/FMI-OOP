#include"Matirx.h"
#include<iostream>
#include<stdlib.h>
#include<time.h>


//извършваме работата на дефалтният конструктор ,използвайки инициализиращ списък
Matrix::Matrix() :matrix(nullptr), rows(0), cols(0) {

         //тук работа нямаме  , но изискване на C++ е всяка функция да има тяло
	// ...
}

//конструктор с параметри
Matrix::Matrix(size_t N, size_t M) {

//следим дали не е пропаднало заделянето на памет повреме на инициализацията 
	try {
		Init(N, M);
	}
	catch (std::bad_alloc&) {

//ако бъде хванато изключение от типа bed alloc , изчистваме динамично заделените ресурси
		if (matrix != nullptr)
			Clean();
//хвърляме отново същото изключение
		throw;
	}
}


void Matrix::Init(size_t N, size_t M) {

//стандартно заделяне на двумерна матрица с N редове и М колони
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



//копи - конструктора , просто прави обръщение към копиращата функция
Matrix::Matrix(const Matrix& other) {
	
		CopyFrom(other);

}

//върнатия тип е Matrix& , а не void , за да можем да поддържаме присвояваня от видя :
// int a,b,c,d;
// a = b = c = d = 5;

Matrix& Matrix::operator=(const Matrix& other) {

//проверяваме за присвояваня от вида А = А
	if (this != &other) {

//почистваме обекта , защотот той вече е бил създаден и след това копираме
            Clean();

	    CopyFrom(other);
	}

//връщаме стойността на this
	return *this;

}

//в деструктора просто се обръщаме към чистещата функция
Matrix::~Matrix() {

	Clean();

}


//тук се грижим да освободим паметта
void Matrix::Clean() {

	for (int i = 0; i < rows; i++)
		delete[] matrix[i];

	delete[]matrix;

	matrix = nullptr;
	rows = 0;
	cols = 0;

}


//тук копираме от друга матрица
void Matrix::CopyFrom(const Matrix& other) {

//ако не успеем да заделим матрица с нужната големина , за да изкопираме 
//почиистваме , каквото сме заделили и хвърляме изключение
	try {
		Init(other.getRows(), other.getCols());
	}
	catch (std::bad_alloc&) {

		if (matrix != nullptr)
			Clean();
		 
		throw;
	}

//копира елемент по елемент
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

//обърнете внимание на върнатия тип - връщаме нова матрица по копие , защото 
// ако върнем по псевдоним или указател матрицата T , ще изгубим нейното съдържание , тъй 
//като тя "живее " само в текущия scope
Matrix Matrix::getTranspose()const {


	Matrix T(cols, rows);


	for (int i = 0; i < cols; i++)
		for (int j = 0; j < rows; j++)
			T.matrix[i][j] = matrix[j][i];

//връща се копие !
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
