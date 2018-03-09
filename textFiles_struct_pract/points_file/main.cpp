//целта на задачата е да прочетем масив от точки от  текстов файл и да върнем индекса на най-близката 
//до 0,0 точка

#include<fstream>
#include<iostream>

#include"Point.h"

int main(){

	std::ifstream points("points.txt");

//при неуспешно отваряне на файла ,програмата приключва
	if (!points.is_open()) {

		std::cout << "can't open the file!\n";
		return -1;
	}

	size_t size;
	points >> size;

//заделяме памет за нужния брой точки
	Point* pntArr = new Point[size];

	for (size_t i = 0; i < size; i++) {

//ако някоя операция с файловия поток пропадне 
//почистваме заетата памет и прекратяваме изпълнението на програмата
		if (!points.good()){

			delete[] pntArr;
			points.close();
			return -1;
		}
//прочитаме кооридинатите на всяка точка
		points >> pntArr[i].x >> pntArr[i].y;
	}

//извеждаме желаната информация, почистваме и приключваме програмата
	std::cout << "the index of the closest point is : "
		<< closestPoint(pntArr, size);

	delete[] pntArr;
	points.close();

	return 0;
}
