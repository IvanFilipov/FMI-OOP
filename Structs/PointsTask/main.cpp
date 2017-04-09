//целта на задачата е да прочетем масив от точки от  текстов файл и да върнем индекса на най-близката 
//до 0,0 точка

#include<iostream>

#include"Point.h"

int main(){



	int size;
	std::cin >> size;

//заделяме памет за нужния брой точки
	Point* pntArr = new Point[size];

	for (int i = 0; i < size; i++){

//ако някоя операция с файловия поток пропадне 
//почистваме заетата памет и прекратяваме изпълнението на програмата
		if (!Points.good()){

			delete[] pntArr;
			Points.close();
			return -1;

		}
//прочитаме кооридинатите на всяка точка
		std::cin >> pntArr[i].x >> pntArr[i].y;

	}

//извеждаме желаната информация ,почистваме и приключваме програмата
	std::cout << "the index of the closest point is : "
		<< ClosestPoint(pntArr, size);

	delete[] pntArr;

	return 0;

}
