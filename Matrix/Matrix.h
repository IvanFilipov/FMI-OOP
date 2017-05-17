#pragma once

//used in randomize function
int const MAXVAL = 100;

class Matrix {

private:

//представяме матрицата като масив от указатели
	int **matrix;
	size_t rows, cols;

public:

	//big four + ctor
	Matrix();
	Matrix(size_t, size_t);
	Matrix(const Matrix&);
	Matrix& operator=(const Matrix&);
	~Matrix();

	//help functions
private:


        //копира съдържанието на друга матрица
	void CopyFrom(const Matrix&);
	
	//изчиства заделените ресурси
	void Clean();
	
	//заделя памет за матрицата
	void Init(size_t, size_t);
	
	//казава дали една точка е вътрешна за матрицата или не
	bool isValid(size_t, size_t)const;


	//interface
public:

        //заделя матрица с желаните размери и попълва клетките със случайни стойности < MAXVAL
	void Randomize(size_t, size_t);
	
	//извежда съдържанието на матрицата на екрана
	void Print()const;
	//връща броя на колоните
	int getCols()const;
	//връща броя на редовете
	int getRows()const;
	
	//връща стойността на клетка с поискани координати
	int GetAt(size_t, size_t);
	
	//задава стойност на клетка с поискани координати
	void SetAt(size_t, size_t, int);

public:
        
        //връща транспонираната матрица
	Matrix getTranspose()const;
	//връща матрица - резултат от умножението на наща с друга
	Matrix getMultipliedBy(const Matrix &other)const;
	
	//нормализира стойностите , като пише 0 там където няма зададена стойност и 1 в другите клетки
	void Normalize();

};

