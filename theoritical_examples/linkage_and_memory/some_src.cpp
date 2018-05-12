#include<iostream>

#include "some_hdr.h"

int e_globalVar = 11;

void printExternalVarValue(){

	std::cout << e_globalVar << std::endl;

}


void printStaticVarValue() {

	std::cout << s_Var << std::endl;
}


//this function will be visible only in this file
static void staticFunction() {

	//DO SOMETHING >>
	std::cout << "heyy, I am well defined in some_src.cpp";
}


void count() {

	//changing the memory model
	//this variable will be allocated only once
	//in the first entrance of the function
	//in the STATIC MEMORY
	//and will be released after main
	static int counter = 0;

	std::cout << counter++;

}

