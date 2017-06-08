#include "stdafx.h"
#include "Triangle.h"


Triangle::Triangle() :x1(0), x2(0), x3(0), y1(0), y2(0), y3(0){
	/*...*/
}


void Triangle::Read(std::ifstream &ifs){

	ifs >> x1 >> y1
		>> x2 >> y2
		>> x3 >> y3;



}
void Triangle::Print()const{

	std::cout << "triangle "
		<< x1 << ' '
		<< y1 << ' '
		<< x2 << ' '
		<< y2 << ' '
		<< x3 << ' '
		<< y3 << '\n';

}

void Triangle::translate(double _x, double _y){

	x1 += _x;
	y1 += _y;

	x2 += _x;
	y2 += _y;

	x3 += _x;
	y3 += _y;
}

void Triangle::isIn(double _x, double _y)const{
	//doing some serious math out there

	//for each two points from the triangle  we create a line 
	//then check if the third point and the searched one  
	//are both from a + or - side of the line


	//coefficients
	double A = 0 ,B = 0 , C = 0;
	
	B = -(x1 - x2);

	A = y1 - y2;

	C = -(A*x1 + B*y1);

	//line is Ax + By + C = 0 

	//we don't need C 

	//checking if signs are not equal

	// - * - = +  ... + * + = + , only - * + = -

	if ((A*_x + B*_y + C)* (A*x3 + B*x3 +C) < 0){

		return;
	}

	//repeat for other points

	B = -(x1 - x3);

	A = y1 - y3;

	C = -(A*x1 + B*y1);


	if ((A*_x + B*_y + C)* (A*x2 + B*x2 + C) < 0){

		return;
	}


	B = -(x2 - x3);

	A = y2 - y3;

	C = -(A*x2 + B*y2);

	if ((A*_x + B*_y + C)* (A*x1 + B*x1 + C) < 0){

		return;
	}

	Print();

	//std::cout << "not here \n";

}

Figure* Triangle::At(int pos){

	if (pos == 0){
		return this;
	}
	else{
		return NULL;
	}
}