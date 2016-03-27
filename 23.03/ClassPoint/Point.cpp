#include "Point.h"
#include<iostream>
#include<math.h>

void Point::Print()const {

	std::cout << '(' << x << ','
		<< y << ')' << '\n';
}


void Point::Read() {

	std::cin >> x >> y;

}

double Point::DistToBeg()const {

	return sqrt((x*x) + (y*y));


}

int Point::GetX()const {

	return x;
}

int Point::GetY()const {

	return y;
}

void Point::Set(int newX,int newY) {


	x = newX;
	y = newY;

}


/*

possible ,but uglier
void Point::Set(int x,int y) {

      this->x = x;
	  this->y = y;
}

don't do this at home , at work or in your homeworks 
void Point::Set(int _x,int _y) {

    x = _x;
	y = _y;
}



*/


