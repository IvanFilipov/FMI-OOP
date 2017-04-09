#include<iostream>

#include"Point.h"

int main() {

   //създаваме обект от типа Point
   //паметта за него е на стека
	Point pnt;

//викаме методите чрез "."
	pnt.Read();

	pnt.Print();

	std::cout << pnt.DistToBeg() << '\n';

	pnt.Set(3, 4);

	pnt.Print();

	std::cout << pnt.DistToBeg() << '\n';

//заделяме динамично памет за точка и я манипулираме чрез указател към нея
	Point* pPnt = new Point;

//тук използваме оператора "->" за да извикаме методите на обекта
	pPnt->Read();

	pPnt->Print();

	delete pPnt;


	return 0;
}
