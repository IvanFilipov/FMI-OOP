#include <iostream>
#include <algorithm>

using std::min;
using std::max;
using std::abs;

#include "Rectangle.h"


//прочитането на правоъгълника не е нищо друго освен
//последователното прочитане на двете му точки
void readRect(Rect& rect) {

	std::cout << "Enter a rectangle's two points\n";
	readPnt(rect.a);
	readPnt(rect.b);
}

void printRect(const Rect& rect){

	if (!isValid(rect)){

		std::cout << "can't be drawn!";
		return;
	}

	//колко реда трябва да отстъпим надолу
	int downOffset = min(rect.a.y, rect.b.y);

	//колко колони ще трябва да отстъпваме на всеки ред
	int rightOffset = min(rect.a.x, rect.b.y);

	//колко са редовете
	int rows = abs(rect.a.y - rect.b.y) + 1;

	//колко колоните
	int cols = abs(rect.a.x - rect.b.x) + 1;

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

	if (rect.a.x < 0 || rect.a.y < 0)
		return false;

	if (rect.b.x < 0 || rect.b.y < 0)
		return false;


	if (rect.a.x == rect.b.x)
		return false;


	if (rect.a.y == rect.b.y)
		return false;


	return true;
}




bool isInside(const Point& pnt, const Rect& rect){

    //връщаме резултата от този булев израз , който не е нищо повече от следните две неравенства
    // a(a1,a2) B(b1,b2) - точките , дали x(х1,х2) изпълнява :
    // |a1<x1<b1
    // |a2<x2<b2
    //използваме мин и макс , защото не знаем кои координати ще ограничават х отляво и кои отдясно
	return (pnt.x > min(rect.a.x, rect.b.x)) && (pnt.x < max(rect.a.x, rect.b.x)) &&
		(pnt.y > min(rect.a.y, rect.b.y)) && (pnt.y < max(rect.a.y, rect.b.y));


}


//The algorithm works by ensuring there is no gap between
//any of the 4 sides of the rectangles
//Any gap means a collision does not exist.
//ref : https://developer.mozilla.org/kab/docs/Games/Techniques/2D_collision_detection
bool areInCollision(const Rect& first, const Rect& second) {

	Point firstTop, secondTop; //the closest to the right top points

	unsigned int fWidth, fHeight, //width and height of both rectangles
		sWidth, sHeight;

	firstTop.x = min(first.a.x, first.b.x);
	firstTop.y = min(first.a.y, first.b.y);
	fWidth = abs(first.a.x - first.b.x);
	fHeight = abs(first.a.y - first.b.y);

	secondTop.x = min(second.a.x, second.b.x);
	secondTop.y = min(second.a.y, second.b.y);
	sWidth = abs(second.a.x - second.b.x);
	sHeight = abs(second.a.y - second.b.y);

	// collision detected!
	return (firstTop.x <= secondTop.x + sWidth &&
		firstTop.x + fWidth >= secondTop.x &&
		firstTop.y <= secondTop.y + sHeight &&
		fHeight + firstTop.y >= secondTop.y);

}
