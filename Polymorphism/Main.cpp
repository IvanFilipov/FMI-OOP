// FigureProject.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Figure.h"
#include "FigureCreator.h"


void CreatVectorFromFile(std::vector<Figure*>& vec){

	std::ifstream ifs("Input.txt");


	while (!ifs.eof()){

		Figure* curFig = FigureCreator::Create(ifs);

		if (curFig != nullptr && ifs) {

			vec.push_back(FigureCreator::Create(ifs));
			vec.back()->Read(ifs);
		}

	}

}

void AtIndex(std::vector<Figure*>&vec){

	int index;

	std::cout << "you are searching for Figure at index = ";

	std::cin >> index;

	int searched = 0;

	for (int i = 0; i < vec.size(); i++){

		int j = 0;

		while (vec[i]->At(j) != NULL){

			searched++;

			if (searched - 1 == index){
				vec[i]->At(j)->Print();
				return;
			}
			
			j++;
		}

		std::cout << '\n';
	}

	std::cout << "none";
}

void SolveIsThere(std::vector<Figure*>& vec){

	double x, y;

	std::cout << "enter coordinates for point A\n";

	std::cin >> x >> y;

	std::cout << "the following figures contain the point A ("
		<< x << " ," << y << ")\n";

	for (int i = 0; i < vec.size(); i++){

		vec[i]->isIn(x, y);
		std::cout << '\n';

	}


}

int main(){
	
	std::vector<Figure*> vec;

	CreatVectorFromFile(vec);

	SolveIsThere(vec);
	
	AtIndex(vec);
	
	return 0;
}

