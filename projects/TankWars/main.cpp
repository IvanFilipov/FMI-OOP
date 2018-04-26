#include<ctime>

#include"Army.h"

int const flagPos = 10;

int main() {

	//tank status : name, pwr, weight, pos
	Tank t("V's tank", 12, 1, 1);
	Tank t1("USA", 15, 3, 4);
	Tank t2("Russia", 14, 2, 3);
	
	Army ar;

	ar.pushBack(t);
	ar.pushBack(t1);
	ar.pushBack(t2);

	srand(time(NULL));
	ar.attack(flagPos);

	return 0;
}