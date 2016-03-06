#include"Rectangle.h"
#include<iostream>


//няколко макроси показващи алтернативен начин за
//разписване на добре познатите ни функции
//обърнете внимание на голямото количество скоби , които ни трябват
//за да можем да подаваме цели изрази , не само отделни променливи
#define min(a,b) ((a > b) ? b : a)

#define max(a,b) ((a > b) ? a : b)
 
#define abs(x) (x > 0) ? (x) : ((-1)*(x))

//прочитането на правоъгълника не е нищо друго освен
//последователното прочитане на двете му точки
void ReadRect(Rect& rect){

	ReadPnt(rect.A);
	ReadPnt(rect.B);

}

void PrintRect(const Rect& rect){

	if (!isValid(rect)){

		std::cout << "can't be drawn!";
		return;
	}

	//колко реда трябва да отстъпим надолу
	int downOffset = min(rect.A.y, rect.B.y);

	//колко колони ще трябва да отстъпваме на всеки ред
	int rightOffset = min(rect.A.x, rect.B.y);

	//колко са редовете
	int rows = abs(rect.A.y - rect.B.y) + 1;

	//колко колоните
	int cols = abs(rect.A.x - rect.B.x) + 1;

	//променлива ,която ще ни служи да печатим текущия отстъп
	int curOffset = downOffset;

	while (curOffset--)
		std::cout << std::endl;

	//първата линия , която трябва да е пълна
	curOffset = rightOffset;
	while (curOffset--)
		std::cout << " ";

	for (int i = 0; i < cols; i++)
		std::cout << "*";

	std::cout << std::endl;


	//страничните рамки на правоъгълника
	for (int i = 1; i < rows - 1; i++){

		curOffset = rightOffset;
		while (curOffset--)
			std::cout << " ";

		std::cout << "*";
        
		for (int j = 1; j < cols - 1; j++)
			std::cout << " ";

		std::cout << "*" << std::endl;
	}


	//последният ред, също пълен
	curOffset = rightOffset;
	while (curOffset--)
		std::cout << " ";

	for (int i = 0; i < cols; i++)
		std::cout << "*";

	std::cout << std::endl;

}



bool isValid(const Rect& rect){

	if (rect.A.x < 0 || rect.A.y < 0)
		return false;

	if (rect.B.x < 0 || rect.B.y < 0)
		return false;


	if (rect.A.x == rect.B.x)
		return false;


	if (rect.A.y == rect.B.y)
		return false;


	return true;
}




bool isInside(const Point& pnt, const Rect& rect){

	//връщаме резултата от този булев израз , който не е нищо повече от следните две неравенства
    // A(a1,a2) B(b1,b2) - точките , дали x(х1,х2) изпълнява :
    // |a1<x1<b1
	// |a2<x2<b2
    //използваме мин и макс , защото не знаем кои координати ще ограничават х отляво и кои отдясно
	return (pnt.x > min(rect.A.x, rect.B.x)) && (pnt.x < max(rect.A.x, rect.B.x)) &&
		(pnt.y > min(rect.A.y, rect.B.y)) && (pnt.y < max(rect.A.y, rect.B.y));


}


//за да сме сигурни ,че двата правоъгълника се пресичат
//е достатъчно да знем ,че един от върховете на някой от двата правоъгълника се съдържа в другия
//
bool Collision(const Rect& first, const Rect& second){

	if (isInside(first.A, second))
		return true;

	if (isInside(first.B, second))
		return true;
	
	//изчисляваме къде се намира точка D на първия правоъгълник
	Point first_D;

	first_D.x = first.A.x;
	first_D.y = first.B.y;

	//провеяваме дали се съдържа във втория
	if (isInside(first_D, second))
		return true;

	Point first_C;

	first_C.x = first.B.x;
	first_C.y = first.A.y;

	if (isInside(first_C, second))
		return true;


	//for the second rectangle's points
	if (isInside(second.A, first))
		return true;

	if (isInside(second.B, first))
		return true;

	Point second_D;

	second_D.x = second.A.x;
	second_D.y = second.B.y;

	if (isInside(second_D, first))
		return true;

	Point second_C;

	second_C.x = second.B.x;
	second_C.y = second.A.y;

	if (isInside(second_C, first))
		return true;


	//we have failed all the tests
	return false;
}