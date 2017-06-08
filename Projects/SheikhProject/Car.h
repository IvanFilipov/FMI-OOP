#pragma once
#include<iostream>
#include<string>

//#define DEBUG

class Car {

protected:

	std::string brand;

	std::string model;

	unsigned int price;

protected:

	void CopyFrom(const Car&);
	void Clear();

public:


	Car();
	Car(const char* , const char*,int = 0 );
	Car(const Car& other);
	~Car();

	Car& operator=(const Car& );
	
	const char* GetModel() const;
	void SetModel(const char* value);

	unsigned int GetPrice()const;

	void Print(std::ostream& = std::cout) const;
	void Read(std::istream& = std::cin);
	
};
