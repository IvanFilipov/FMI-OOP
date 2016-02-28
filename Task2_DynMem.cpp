
//условие : заделяме ДИНАМИЧНО двумерна матрица n на m ,
//попълваме клетките със случайни числа и след това ги отпечатваме на екрана

#include<iostream>
#include<iomanip>
#include<random>
#include<time.h>

//генерираните числа ще са по малки от това число
const int MAXNUM = 100;
//брой клетки , в които принтим всеки елемент на матрицата
const int NCELLS = 3;

//Matrix е от тип указател към масив от указатели и 
//го взимаме по референция , защото ще го пренасочваме , 
// ако не го вземем по псевдоним , ще пренасочим само копието , което ще бъде използвано от функцията
void Init(int** &Matrix, int n, int m){

	Matrix = new int*[n];

	for (int i = 0; i < n; i++)
		Matrix[i] = new int[m];

	srand(time(NULL));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			Matrix[i][j] = rand() % MAXNUM;

}

//принтим числата , тук не е необходимо подаването по референция,
//защото няма да пренасочваме самият указател 
void Print(int** Matrix, int n, int m){

	for (int i = 0; i < n; i++){

		for (int j = 0; j < m; j++)
			std::cout << std::setw(NCELLS) << Matrix[i][j];

		std::cout << std::endl;
	}


}

//освобождаваме заделената памет
void Clean(int** &Matrix, int n){


	for (int i = 0; i < n; i++)
		delete[] Matrix[i];

	delete[] Matrix;

	Matrix = NULL;

}

int main(){

	int n, m;

	int **Matrix = NULL;

	std::cin >> n >> m;


	Init(Matrix, n, m);

	Print(Matrix, n, m);

	Clean(Matrix, n);

	return 0;

}
