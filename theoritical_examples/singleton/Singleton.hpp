#pragma once

#include<iostream>
#include<ctime>
#include<random>
#include<iomanip>

#define _4MB 4194304

class Singleton {

private:

	char aLotOfData[_4MB];

public:

	Singleton& operator=(const Singleton&) = delete;
	Singleton(const Singleton&) = delete;

private:

	Singleton() = default;

public:

	static Singleton& getInstance() {

		static Singleton instance; //creates the object only the first time 
								   //the getInstance method is invoked
								   //here we can "see" the private constructor

		return instance;
	}

	void init() {

		srand(time(NULL));

		for (int i = 0; i < _4MB; i++)
			aLotOfData[i] = rand() % 128;
	}

	void printContain() const {

		for (int i = 0; i < _4MB; i++)
			std::cout << std::setw(4) << aLotOfData[i];
	}
};