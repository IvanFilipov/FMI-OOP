#include "SportCar.h"

//a reference to car,
//we can have a reference to sportcar also
//because sportcar is a car
void refFun(const Car& c) {
	
	c.print();
	std::cout << std::endl;
}

//same with pointer
void pointerFun(Car* c) {

	c->print(); 
	std::cout << std::endl;
}

//same with objects as parameters
//silly version, why?
void fun(Car c) {

	std::cout << std::endl;
	c.print();
}

//only sportcars 
void hoursePower(const SportCar& sc) {

	std::cout << std::endl;
	std::cout << "this sport car has " 
		<< sc.getHP() << "hs\n";
}


int main(){

	std::cout << "\n=== Entering main()\n";
	
	Car c("Renault", "Megane Scenic", 3000);

	//problem ! can't convert car -> sportcar
	fun(c);
	pointerFun(&c);
	refFun(c);
	//hoursePower(c);

	std::cout << "\n=== SportCar object 1 : \n";
	SportCar s1("Audi", "R8", 130000 , 610 );
	s1.print();

	std::cout << "\n=== SportCar object 2\n";
	SportCar s2 (s1);
	s2.print();

	std::cout << "\n=== SportCar heap object 3\n";
	SportCar * scPtr = new SportCar;

	delete scPtr;
	
	//we can pass SportCar where Car is wanted ,
	//because SportCar Is-A Car
	fun(s1);
	pointerFun(&s1);
	refFun(s1);
	hoursePower(s1);

	std::cout << "\n=== SportCar object 1 after tunning : \n";
	s1.tune(40);
	s1.print();

	try {

		s2.tune(200);
	}
	catch (std::logic_error& e) {

		std::cerr << e.what();
	}


	std::cout << "\n=== Leaving main()\n";

	return 0;
}