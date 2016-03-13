#include<fstream>
#include<iostream>

#include"Point.h"

int main(){

	std::ifstream Points("points.txt");

	if (!Points.is_open())
		return -1;


	int size;
	Points >> size;


	Point* pntArr = new Point[size];

	for (int i = 0; i < size; i++){

		if (!Points.good()){

			delete[] pntArr;
			Points.close();
			return -1;

		}

		Points >> pntArr[i].x >> pntArr[i].y;

	}

	std::cout << "the index of the closest point is : "
		<< ClosestPoint(pntArr, size);

	delete[] pntArr;
	Points.close();

	return 0;

}