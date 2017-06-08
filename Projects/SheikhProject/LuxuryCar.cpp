#include <cstring>
#include <iostream>

#include "LuxuryCar.h"


const unsigned int LuxuryCar::SingleExtraProfit = 12000;


LuxuryCar::LuxuryCar() {

}


LuxuryCar::LuxuryCar(const char* br, const char* md, unsigned int pr, const char* ex)
	:Car(br, md, pr), extras(ex) {
}


LuxuryCar::~LuxuryCar() {

}

LuxuryCar::LuxuryCar(const LuxuryCar & other) : Car(other) , extras(other.extras) {


}

LuxuryCar& LuxuryCar::operator=(const LuxuryCar& other) {

	if (this != &other) {

		Car::Clear();
		Car::operator=(other);
		
		extras = other.extras;
	}

	return *this;
}

int LuxuryCar::GetExtrasCount() const {

	int cnt = 0;
	const char* ex = extras.c_str();

	int i = 0;
	while (ex[i] != '\0') {

		if (ex[i] == ',')
			cnt++;

		i++;
	}

	if (i > 0)
		cnt++;

	return cnt;

}

void LuxuryCar::AddExtras(const char* ex) {

	int cnt = 0;
	char *temp = new char[strlen(ex) + 1];
	strcpy(temp, ex);

	char *curExtra = strtok(temp, ",");

	while (curExtra != NULL) {
		if (strstr(extras.c_str(), curExtra) == NULL) {
			extras += ',';
			extras += curExtra;
			cnt++;
		}

		curExtra = strtok(NULL, ",");
	}

	price += cnt * SingleExtraProfit;

	delete[] temp;
}

int LuxuryCar::HowManyDifferent(const char * otherExtras) const {

	int count = 0;

	//otherExtras into tokens :
	char *temp = new char[strlen(otherExtras) + 1];
	strcpy(temp, otherExtras);

	char *curExtra = strtok(temp, ",");

	while (curExtra != NULL) {
		if (strstr(extras.c_str(), curExtra) == NULL)
			count++;

		curExtra = strtok(NULL, ",");
	}

	delete[] temp;
	return count;
}

unsigned int LuxuryCar::GetSingleExtraProfit(){
	return SingleExtraProfit;
}


void LuxuryCar::Print(std::ostream& os) const {

#ifdef DEBUG
	os << "A LuxuryCar object at 0x" << this << '\n';
#endif

	Car::Print(os);

	os << "\n EXTRAS : " << extras << "\n";

}

void LuxuryCar::Read(std::istream & is) {

	Car::Read(is);
	is >> extras;

}
