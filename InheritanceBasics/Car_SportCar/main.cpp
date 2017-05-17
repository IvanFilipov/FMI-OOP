#include "SportCar.h"

void f(const Car& c) {
	
	std::cout << std::endl;
	c.Print();

}

void f(Car* c) {

	std::cout << std::endl;
	c->Print();

}

void g(Car c) {

	std::cout << std::endl;
	c.Print();

}

void h(const SportCar& sc) {

	std::cout << std::endl;
	std::cout << "this sport car has " 
		<< sc.GetHP() << "hs\n";

}


int main(){

	std::cout << "\n=== Entering main()\n";

	std::cout << "\n=== SportCar object 1 : \n";
	SportCar s1("Audi", "R8", 130000 , 610 );
	s1.Print();

	std::cout << "\n=== SportCar object 2\n";
	SportCar s2 (s1);
	s2.Print();

	std::cout << "\n=== SportCar heap object 3\n";
	SportCar * scPtr = new SportCar;

	delete scPtr;
	
	//we can pass SportCar where Car is wanted ,
	//because SportCar Is-A Car
	f(s1);
	f(&s1);
	g(s1);
	h(s1);

	Car c("Renault", "Megane Scenic", 3000);

	//problem ! can't convert car -> sportcar
	//h(c);
	f(c);
	f(&c);
	
	std::cout << "\n=== Leaving main()\n";

	return 0;
}