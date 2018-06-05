#include <cstring>
#include <iostream>

#include "SportCar.h"

const unsigned int SportCar::singleHpProfit = 2000;


SportCar::SportCar() : horsePower(0), tuningLimit(0) {

#ifdef DEBUG
	std::cout << "[ SportCar ctor working ] at 0x" << this << " ]\n";
#endif

}


SportCar::SportCar(const char* br, const char* md, unsigned int pr, unsigned int hp, unsigned int tl)
	:Car(br, md, pr), horsePower(hp), tuningLimit(tl) {

#ifdef DEBUG

	std::cout << "[ SportCar ctor with parameters working  at 0x"
		<< this << " ]\n";
#endif

}

unsigned int SportCar::getTuningLimit() const {

	return tuningLimit;
}

void SportCar::printSp(std::ostream& os) const {

#ifdef DEBUG
	os << "A SportCar object at 0x" << this << '\n';
#endif

	Car::print(os);

	os << "\n  HP: " << horsePower << "\n";
}

void SportCar::readSp(std::istream & is) {

	Car::read(is);
	is >> horsePower;
	is >> tuningLimit;
}

unsigned int SportCar::getHorsePower() const {

	return horsePower;
}

void SportCar::tuning() {

	horsePower += tuningLimit;
	price += tuningLimit * singleHpProfit;

}

unsigned const int SportCar::getSingleHpProfit() {

	return SportCar::singleHpProfit;
}
