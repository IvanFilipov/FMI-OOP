#include <iostream>

#include"Army.h"

int main() {

	//name - power - hit points
	Tank t0("ALFA", 120, 1000);
	Tank t1("BETA", 150, 2000);
	Tank t2("GAMA", 200, 200);
	Tank t3("DELTA", 210, 200);

	Tank target("enemy", 30, 500);

	Army ar;

	ar.addTank(t0);
	ar.addTank(t1);
	ar.addTank(t2);
	ar.addTank(t3);

	ar.attackAt(target);

	if (ar.serialize("army.bin"))
		std::cout << "\nar serialized!\n";

	//should be same as ar
	Army ar1;

	if(ar1.deserialize("army.bin"))\
		std::cout << "\nar1 deserialized!\n";

	ar1.attackAt(target);

	return 0;
}