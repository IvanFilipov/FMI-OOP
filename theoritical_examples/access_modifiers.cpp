//https://stackoverflow.com/questions/860339/difference-between-private-public-and-protected-inheritance
#include<iostream>

class B {

private:
	
	int private_var;
	int getPrivateVar() {

		return private_var;
	}

protected:
	
	int protected_var;
	int getProtected_var() {

		return protected_var;
	}

public:

	int public_var; //wtf?! data members in interface
 	int getPublic_var() {

		return public_var;
	}

public:

	B(int x = 0, int y = 0, int z = 0) :
		private_var(x), protected_var(y), public_var(z) {
		//..
	}

};


class D : private B {

	//private_var is inaccessible
	//protected_var is private
	//public_var is private

public:

	void func() {

		//std::cout << x; inaccessible
		std::cout << protected_var;
		std::cout << public_var;

		//std::cout << getX(); inaccessible
		std::cout << getProtected_var();
		std::cout << getPublic_var();
	}
};

int main() {

	B obj;
	obj.getPublic_var();

	D d;
	//d.getZ(); everything from the base class is inaccessible 

	return 0;
}