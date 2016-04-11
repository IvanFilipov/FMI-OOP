#pragma once

//used in randomize function
int const MAXVAL = 100;

class Matrix {

private:

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

	void CopyFrom(const Matrix&);
	void Clean();
	void Init(size_t, size_t);
	bool isValid(size_t, size_t)const;


	//interface
public:
	void Randomize(size_t, size_t);
	void Print()const;
	int getCols()const;
	int getRows()const;
	int GetAt(size_t, size_t);
	void SetAt(size_t, size_t, int);

public:

	Matrix getTranspose()const;
	Matrix getMultipliedBy(const Matrix &other)const;
	void Normalize();

};

