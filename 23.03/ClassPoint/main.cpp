#include<iostream>

#include"Point.h"

int main() {

	Point pnt;

	pnt.Read();

	pnt.Print();

	std::cout << pnt.DistToBeg() << '\n';

	pnt.Set(3, 4);

	pnt.Print();

	std::cout << pnt.DistToBeg() << '\n';

	Point* pPnt = new Point;

	pPnt->Read();

	pPnt->Print();

	delete pPnt;


	return 0;
}