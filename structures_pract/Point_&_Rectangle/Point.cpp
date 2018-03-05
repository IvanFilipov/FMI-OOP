#include<iostream>
#include<math.h>

//задължително включваме заглавния файл , в който са описани декларациите на функциите
#include"Point.h"

void readPnt(Point& pnt){

	std::cout << "Enter point coordinates :\n";
	std::cin >> pnt.x >> pnt.y;

}

void printPnt(const Point& pnt){

	std::cout << '(' << pnt.x << ',' 
		      << pnt.y << ')' 
			  << '\n';

}

double pntToBegDist(const Point& pnt){


	return sqrt(pnt.x*pnt.x + pnt.y*pnt.y);

}


double pntToPntDist(const Point& A, const Point& B){

	return sqrt((A.x - B.x)*(A.x - B.x) + (A.y - B.y)*(A.y - B.y));

}
