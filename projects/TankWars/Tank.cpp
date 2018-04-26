#include <ctime>
#include <cmath>
#include <cstring>
#include <cstdlib>

#include"Tank.h"
#include"Constants.h"


Tank::Tank() :name(nullptr), shootPower(0), shellWeight(0), pos(0) {

}

Tank::Tank(const char* n, size_t sp = 0, size_t sw = 0, size_t p = 0)
	: shootPower(sp), shellWeight(sw), pos(p) {

	name = new char[strlen(n) + 1];

	strcpy(name, n);

}

Tank::Tank(const Tank& other) {

	copyFrom(other);
}

Tank& Tank::operator=(const Tank& other) {

	if (this != &other) {

		delete[]name;
		copyFrom(other);
	}

	return *this;
}

void Tank::copyFrom(const Tank& other) {

	name = new char[strlen(other.name) + 1];

	strcpy(name, other.name);

	shootPower = other.shootPower;

	shellWeight = other.shellWeight;

	pos = other.pos;
}


const int Tank::calcWind(){

	short sign = rand() % 1;

	int Wpwr = rand() % MAXWINDPWR;

	if (sign)
		return Wpwr;
	else
		return (-1) * Wpwr;
}


//used formula : P(t) = -t^2 + ShootPower*t + (WingPower / ShellWeight) + c 
//and knowing the fact that P(Tank.pos) = 0 
//we find c and than 
//we calculate P(FlagPos)
int Tank::fire(size_t const FlagPos, std::ostream& os) const {

	const int windPower = calcWind();

	int c = pos * pos - shootPower * pos
		- (int)(windPower / shellWeight);

	os << "\n wind "
		<< windPower << "m/s "
	    << ((windPower > 0) ? "<----" : "---->")
		<< '\n';

	int whereFallen = FlagPos + ((-1)*(FlagPos*FlagPos) +
		shootPower*FlagPos + (int)(windPower / shellWeight) + c);

	drawTheShot(pos, windPower, c, whereFallen, os);

	return (-1)*FlagPos*FlagPos + shootPower*FlagPos + (int)(windPower / shellWeight) + c;
}

void Tank::printUnit(std::ostream& os) {

	os << TANKSYM;
}


//with mathematical approach
/*
void Tank::DrawTheShot(const int wPwr,const int ConstDiff, std::ostream& os)const {

	for (int i = CONSOLE_VERTICAL; i > 0; i--) {
		for (int j = 0; j < CONSOLE_HORIZONTAL; j++) {

			bool isThere = false;

			for (double t = j; t < j + TIMES_TRY&!isThere; t += STEP) {
				if ((((-1)*(wPwr / ShellWeight)*t*t + ShootPower*t + ConstDiff) < i + DIFF) &&
					(((-1)*(wPwr / ShellWeight)*t*t + ShootPower*t + ConstDiff) > i - DIFF))
					isThere = true; 
			}

			if (isThere)
				os << '.';
			else
				os << ' ';

		}
		os << '\n';
	}
}

*/

//with hack 
void Tank::drawTheShot(const int TankPos, const int wPwr, 
	const int ConstDiff,const int WhereDown, std::ostream& os) const {

	bool ConsoleWindow[CONSOLE_VERTICAL][CONSOLE_HORIZONTAL] = { 0, };

	//-b/2a
	int peakH = shootPower / 2 + TankPos;


	//f(-b/2a)
	int peakV = (-1)*peakH*peakH + shootPower*peakH + (int)(wPwr / shellWeight) + ConstDiff;


	for (int i = peakH; i < CONSOLE_HORIZONTAL; i++) {

		peakV = (-1) * i * i + shootPower * i + 
			(int)(wPwr / shellWeight) + ConstDiff;

		if(peakV < CONSOLE_VERTICAL && peakV > 0)
		  ConsoleWindow[peakV][i] = 1;
	}

	for (int i = peakH; i > 0; i--) {

		peakV = (-1) * i * i + shootPower * i + 
			(int)(wPwr / shellWeight) + ConstDiff;

		if (peakV < CONSOLE_VERTICAL && peakV > 0)
			ConsoleWindow[peakV][i] = 1;
	}

	for (int i = CONSOLE_VERTICAL-1; i > 0; i--) {

		for (int j = 0; j < CONSOLE_HORIZONTAL; j++)
			if (ConsoleWindow[i][j])
				os << '.';
			else
				os << ' ';

		os << '\n';
	}

}




void Tank::printInfo(std::ostream& os) const {

	os << "Tank information : \n"
		<< "  name :" << name 
		<< "  shooting power:" << shootPower << '\n';
}


size_t Tank::getPos() const {

	return pos;
}