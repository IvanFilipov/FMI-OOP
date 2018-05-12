#ifndef  __SOME_HDR_H__
#define __SOME_HDR_H__

//all global variables are
//allocated in the STATIC MEMORY
//no matter if they are
//extern, static or just plain type
//so they live before entering main
//and die after leaving main

//we don't have problem with constants
int const MAX = 10;
//but.. with ordinary variables :

//both declaration and definition
//is wrong we will have
//problem redefinition + multiple initialization,
//if included in more then one .c/.cpp
//int gVar = 15;
//same with :
//int gVar;

//if we want a global variable
//which we can use in multiple
//source files ->

//no memory is allocated
//just declaration, no definition
//there should be only one definition
//somewhere in one .c/.cpp file
extern int e_globalVar;

//using static modifier
//the linkage will be internal
//which means that s_Var
//will be visible only
//in current source file
static int s_Var = 23;

//this function will be defined only in one file's scope
static void staticFunction();

//ordinary function with static variable inside it
void count();

extern void printExternalVarValue();

void printStaticVarValue();

#endif // ! __SOME_HDR_H__
