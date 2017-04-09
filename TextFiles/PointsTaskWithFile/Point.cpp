#include<iostream>
#include<math.h>

//задължително включваме заглавния файл , в който са описани декларациите на функциите
#include"Point.h"

void ReadPnt(Point& pnt){

	std::cin >> pnt.x >> pnt.y;

}

void PrintPnt(const Point& pnt){

	std::cout << '(' << pnt.x << ',' 
		      << pnt.y << ')' 
			  << '\n';

}

double PntToBegDist(const Point& pnt){


	return sqrt(pnt.x*pnt.x + pnt.y*pnt.y);

}


double PntToPntDist(const Point& A, const Point& B){

	return sqrt((A.x - B.x)*(A.x - B.x) + (A.y - B.y)*(A.y - B.y));

}

int ClosestPoint(Point* pnts, int n){

	if (pnts == NULL || n <= 0)
		return -1;

	int bestIndex = 0;

	double minDist = PntToBegDist(pnts[0]);


	for (int i = 1; i < n; i++){

		if (minDist > PntToBegDist(pnts[i])){
           
			minDist = PntToBegDist(pnts[i]);
			bestIndex = i;

		}

	}

	return bestIndex;

}

