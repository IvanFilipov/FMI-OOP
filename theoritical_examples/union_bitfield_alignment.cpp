//some alignment and memory allocation examples about structures 

#include<iostream>

//structure alignment :
//depends on the both architecture & compiler

//anonymous structure - we can create instances
//only after its declaration
struct {

	int x;
	int y;
	char c; //<-- will take four bytes instead of one
	int z;


}t1; //<-- the instance

struct {

	char c;
	char c2; //<-- the compiler will help us 
			 // allocating less memory than 4B 
}t2;


//bit fields

//optimizing the memory usage as we wish
//setting each field 's size (in bits)
struct filePerm {

	unsigned char read : 1;
	unsigned char write : 1;
	unsigned char execute : 1;

}fpr; // three bits at all , but 'memory allocated 
	  //cannot be less than a byte , so this field size is ...


//unions :
//allocating memory as much as the bigger
//member needs , can hold values from each of 
//it's member's types 
union u_tag {

	int val;
	char *name;
	double price;

}tag;



int main() {

	//unions and fields usage is same as the structure's


	//tag.val = 5;
	//std::cout << tag.val;
	//std::cout << tag.price; // same results
	//tag.name = new char[8];
	//std::cout << tag.val; // oops


	/*
	fpr.read = true;
	fpr.execute = false;

	if (fpr.read && fpr.read || fpr.execute)
		...;
	*/

	//sizeof operator applied on structure
	//returns something different then the sum
	//of members' bytes, usually sizeof(s) >= sum(members bytes)

	std::cout << "t1 :" << sizeof(t1) << std::endl
		<< "t2 :" << sizeof(t2) << std::endl
		<< "bit field : " << sizeof(filePerm) << std::endl
		<< "union :  " << sizeof(u_tag);

	return 0;
}