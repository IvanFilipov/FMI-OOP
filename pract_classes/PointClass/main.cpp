#include<iostream>

#include"Point.h"

int main() {

	//object created on the stack
	//with default constructor
	Point pnt;
	
	//calling methods attached to an object
	//by using . operator
	std::cout << "instance pnt current state: \n";
	pnt.print();

	pnt.read();
	std::cout << "instance pnt current state: \n";
	pnt.print();

	std::cout << "pnt to (0, 0) distance : " 
		<< pnt.distToBeg() << '\n';

	pnt.setX(3);
	std::cout << "new x coordinate value is :" 
		<< pnt.getX()  << '\n';

	std::cout << "instance pnt current state: \n";
	pnt.print();

	std::cout << "pnt to (0, 0) distance : "
		<< pnt.distToBeg() << "\n\n\n";

	//creating another point using the constructor with parameters
	Point otherPnt(5, 5);

	std::cout << "instance otherPnt current state: \n";
	otherPnt.print();
	std::cout << "otherPnt to (0, 0) distnace \n" 
		<< otherPnt.distToBeg() << '\n';

	std::cout << "distance between pnt and otherPnt :\n"
		<< pnt.pntToPntDist(otherPnt) << "\n\n\n";

//dynamic allocated object
	Point* pPnt = new Point; //here the default constructor is called
	std::cout << "using a heap allocated object \n";
//same as with structures, now we should use -> operator
	pPnt->read();

	pPnt->print();

	delete pPnt;

	return 0;
}
