#include "stdafx.h"
#include "Rectangle.h"


Rectangle::Rectangle() :x1(0), y1(0), x2(0), y2(0){

	/* ...  */
}

void Rectangle::Read(std::ifstream &ifs){

	ifs >> x1 >> y1 >> x2 >> y2;

}


void Rectangle::Print()const{

	std::cout << "rect "
		<< x1 << ' '
		<< y1 << ' '
		<< x2 << ' '
		<< y2 <<'\n';

}


void Rectangle::translate(double _x, double _y){

	x1 += _x;
	y1 += _y;

	x2 += _x;
	y2 += _y;
}
void Rectangle::isIn(double _x, double _y)const{

	//doing some serious math out there
	
	if ((_x >= std::min(x1, x2)) && _x <= std::max(x1, x2))
	{
		if ((_y >= std::min(y1, y2)) && _y <= std::max(y1, y2)){

			Print();
		}

	}


	//std::cout << "not here \n";
}


Figure* Rectangle::At(int pos){

	if (pos == 0){
		return this;
	}
	else{
		return NULL;
	}

}