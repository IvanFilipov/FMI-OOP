//for better understanding
//take a look at the older example
//from the IP course

#include<iostream> 
#include<iomanip> 
#include<random> 
#include<time.h>

const int MAXNUM = 100;
const int NCELLS = 3;

void cleanMat(int**&, size_t);

void fillMat(int** matrix, size_t n, size_t m) {

	for (size_t i = 0; i < n; i++)
		for (size_t j = 0; j < m; j++)
			matrix[i][j] = rand() % MAXNUM;
}

bool allocMat(int**& matrix, size_t n, size_t m) {

	matrix = new (std::nothrow) int*[n];
	
	if (!matrix)
		return false;

	for (size_t i = 0; i < n; i++) {

		matrix[i] = new (std::nothrow) int[m];

		if (!matrix[i]) {

			cleanMat(matrix, i - 1);
			return false;
		}
	}

	return true;
}

void print(int** matrix, size_t n, size_t m) {

	if (matrix == nullptr)
		return;

	for (size_t i = 0; i < n; i++) {

		for (size_t j = 0; j < m; j++)
			std::cout << std::setw(NCELLS) << matrix[i][j];
	
		std::cout << std::endl;
	}
}

void cleanMat(int**& matrix, size_t n) {

	if (matrix == nullptr)
		return;

	for (size_t i = 0; i < n; i++)
		delete[] matrix[i];

	delete[] matrix;

	matrix = nullptr;
}

int** getTranspose(int** matrix, size_t n, size_t m) {
	
	if (matrix == nullptr)
		return nullptr;

	int** transposeMat = nullptr;
	
	//allocating enough memory
	if (!allocMat(transposeMat, m, n)) {

		std::cout << "not enough memory!\n";
		return nullptr;

	}

	for (size_t i = 0; i < m; i++)
		for (size_t j = 0; j < n; j++)
			transposeMat[i][j] = matrix[j][i];

	return transposeMat;
}

int main() {

	size_t n, m;

	//указател към място в паметта където има други указатели
	int** matrix = nullptr;

	std::cin >> n >> m;

	srand(time(NULL));

	allocMat(matrix, n, m);

	fillMat(matrix, n, m);

	std::cout << "\nthe random generated matrix looks like : \n";
	print(matrix, n, m);

	//allocating and copying elements
	int **transposeMat = getTranspose(matrix, n, m);

	std::cout << "\nthe transpose matrix looks like : \n";
	print(transposeMat, m, n);


	//free memory for the first matrix
	cleanMat(matrix, n);

	//free memory for the second matrix
	cleanMat(transposeMat, m);

	return 0;
}