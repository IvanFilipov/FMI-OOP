#include"Army.h"

int main() {
	
	//name - power - hit points
	Tank t0("ALFA",120,1000);
	Tank t1("BETA", 150, 2000);
	Tank t2("GAMA", 200, 200);
	Tank t3("DELTA", 210, 200);
	

	Tank target("enemy", 30, 500);

	Army ar;

	ar.AddTank(t0);
	ar.AddTank(t1);
	ar.AddTank(t2);
	ar.AddTank(t3);

	ar.AttackAt(target);

	ar.Serialize("army.bin");

	//should be same as ar
	Army ar1;

	ar1.Deserialize("army.bin");

	ar1.AttackAt(target);


	return 0;

}