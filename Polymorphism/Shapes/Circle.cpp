#include "stdafx.h"
#include "Circle.h"


Circle::Circle() :x(0), y(0), Rad(0)
{
	/* .. */
}


void Circle::Read(std::ifstream& ifs){

	ifs >> x >> y >> Rad;

}


void Circle::Print()const{

	std::cout << "circle "
		<< x << " "
		<< y << " "
		<< Rad << "\n";

}

void Circle::translate(double _x, double _y){

	x += _x;

	y += _y;
}

void Circle::isIn(double _x,double _y)const{

	//doing some serious math out there

	double dist = sqrt((x - _x)*(x - _x) + (y - _y)*(y - _y));

	if((Rad - dist) > 0.00001 || Rad == dist){

		Print();

	}


}

Figure* Circle::At(int pos){

	if (pos == 0){
		return this;
	}
	else{
		return NULL;
	}

}