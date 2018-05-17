#include <fstream>
#include <iostream>

#include "FigureContainer.h"

void creatVectorFromFile(FigureContainer& vec) {

	std::ifstream ifs("Input.txt");
	
	if (!ifs.is_open())
		return;

	while (!ifs.eof()) { //last reading will return nullptr...ok

		Figure* curFig = Figure::createFigure(ifs);

		if (curFig != nullptr && ifs) {

			vec.push_back(curFig);
			vec.back()->readFromFile(ifs);
		}
	}
}

void solveAtIndex(const FigureContainer& vec){

	int index;

	std::cout << "you are searching for Figure at index = ";

	std::cin >> index;

	int searched = 0;

	for (size_t i = 0; i < vec.getSize(); i++){

		size_t j = 0;

		while (vec.getAt(i)->getFigureAt(j) != NULL) {

			searched++;

			if (searched - 1 == index) {

				vec.getAt(i)->getFigureAt(j)->print();
				return;
			}
			
			j++;
		}

		std::cout << '\n';
	}

	std::cout << "none";
}

void solveIsThere(const FigureContainer& vec){

	double x, y;

	std::cout << "enter coordinates for point A\n";

	std::cin >> x >> y;

	std::cout << "the following figures contain the point A ("
		<< x << " ," << y << ")\n";

	bool seen = false;
	for (size_t i = 0; i < vec.getSize(); i++){

		if (vec.getAt(i)->isInside(x, y)) {
		
			seen = true;
			std::cout << '\n';
		}
	}

	if (!seen)
		std::cout << "none\n";
}


int main() {
	
	FigureContainer vec;

	creatVectorFromFile(vec);

	std::cout << "all figures : \n";
	for (size_t i = 0; i < vec.getSize(); i++)
		vec.getAt(i)->print();

	solveIsThere(vec);
	
	solveAtIndex(vec);
	
	return 0;
}

