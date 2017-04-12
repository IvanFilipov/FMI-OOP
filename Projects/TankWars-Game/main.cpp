#include"Army.h"

int const FlagPos =10;

int main() {

	//tank status : pwr,weight,pos
	Tank t("V's tank",12,1,1);
	Tank t1("USA", 15, 3, 4);
	Tank t2("Russia", 14, 2, 3);
	
	Army ar;

	ar.PushBack(t);
	ar.PushBack(t1);
	ar.PushBack(t2);

	

	ar.Attack(FlagPos);

	return 0;

}