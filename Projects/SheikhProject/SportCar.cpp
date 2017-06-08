#include <cstring>
#include <iostream>

#include "SportCar.h"

const unsigned int SportCar::SingleHpProfit = 2000;


SportCar::SportCar() : horsePower(0), TuningLimit(0) {

#ifdef DEBUG
	std::cout << "[ SportCar ctor working ] at 0x" << this << " ]\n";
#endif

}


SportCar::SportCar(const char* br, const char* md , unsigned int pr, unsigned int hp ,unsigned int tl )
	:Car(br,md,pr) , horsePower(hp) , TuningLimit(tl){

#ifdef DEBUG

	std::cout << "[ SportCar ctor with parameters working  at 0x" 
		      << this <<  " ]\n";
#endif
	
}


SportCar::~SportCar(){

#ifdef DEBUG

	std::cout << "[SportCar destructor working at 0x" << this << " ]\n";
#endif

}

SportCar::SportCar(SportCar const & other) : Car(other) , TuningLimit(other.TuningLimit) {

#ifdef DEBUG

	std::cout << "[Sport Car copy ctor working at 0x" << this
		<< "with param at 0x" << &other << " ]\n";

#endif

	horsePower = other.horsePower;
	
}

SportCar& SportCar::operator=(SportCar const& other){

#ifdef DEBUG

	std::cout << "[Car operator= working at 0x" << this
		<< "with param at 0x" << &other << " ]\n";
#endif

    if (this != &other){

		Car::Clear();

		Car::operator=(other);
        //or
        //Car::CopyFrom(other);

		horsePower = other.horsePower;
		TuningLimit = other.TuningLimit;
    }

    return *this;
}

unsigned int SportCar::GetTuningLimit() const{
	return TuningLimit;
}

void SportCar::Print(std::ostream& os) const {
	
#ifdef DEBUG
	os << "A SportCar object at 0x" << this << '\n';
#endif

	Car::Print(os);

	os	<< "\n  HP: " << horsePower << "\n";

}

void SportCar::Read(std::istream & is){

	Car::Read(is);
	is >> horsePower;
	is >> TuningLimit;

}

unsigned int SportCar::GetHorsePower() const{
	return horsePower;
}

void SportCar::Tuning(){

	horsePower += TuningLimit;
	price += TuningLimit * SingleHpProfit;

}

unsigned const int SportCar::GetSingleHpProfit(){
	return SportCar::SingleHpProfit;
}
