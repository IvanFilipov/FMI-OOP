#include "Point.h" //задължително включваме "главата" на класа
#include<iostream>
#include<math.h>


//constructor with parameters
//creates an instance with these values
Point::Point(int coordX, int coordY) : x(coordX), y(coordY) {
	//..
}

//syntax :
//return value / where is the function::name
void Point::print() const {

	std::cout << '(' << x << ','
		<< y << ')' << '\n';
}

//all the methods have access to the private data
void Point::read() {

	std::cout << "enter x and y coordinates :\n";
	std::cin >> x >> y;
}

double Point::distToBeg() const {

	return sqrt((x * x) + (y * y));
}

//inside class methods we have access to data members
//for all instances passed as arguments
double Point::pntToPntDist(const Point& other) {

	return sqrt((x - other.x) * (x - other.x) + (y - other.y) * (y - other.y));
}