//see also : http://en.cppreference.com/w/cpp/language/explicit

class A {

public:

	A(int) { } // converting constructor implicit constructor
};

struct B {

public:

	explicit B(int) { } //cannot be used for converting 
};

void func_A(const A& a) {

}

void func_B(const B& b) {


}

int main() {

	A a1 = 1;      // OK: copy-initialization selects A::A(int)
	A a2(2);       // OK: direct-initialization selects A::A(int)
	
	A a5 = (A)1;   // OK: explicit cast performs static_cast

	func_A(5); // OK: the function parameter is created using 5
	
//  B b1 = 1;  error: copy-initialization does not consider B::B(int)
	B b2(2);       // OK: direct-initialization selects B::B(int)
	
	B b5 = (B)1;   // OK: explicit cast performs static_cast

	//func_B(5); error: there is no constructor for converting from int to B
	
	return 0;
}