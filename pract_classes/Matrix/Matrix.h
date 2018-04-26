#pragma once

//used in randomize function
int const MAXVAL = 100;

class Matrix {

private:

//representing the matrix as an array of pointers
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

	void copyFrom(const Matrix&);
	void clean();
	
	//allocates enough memory and initialize with 0
	void init(size_t, size_t);
	
	//is a point inside the matrix
	bool isValid(size_t, size_t) const;

	//interface
public:
	
	//fills the matrix with random values
	void randomize();
	
	//prints the contain to STDOUT
	void print() const;

	//how many columns are there
	int getCols()const;
	//how many rows are there
	int getRows()const;
	
	//returns the value at wanted indexes
	int getAt(size_t, size_t);
	
	//sets the value at wanted indexes
	void setAt(size_t, size_t, int);

    //returns the transpose matrix
	Matrix getTranspose()const;
	//returns the result of multiplying two matrices
	Matrix getMultipliedBy(const Matrix &other)const;
	
	//each field with value becomes 1, others 0
	void normalize();
};

