#pragma once
#include<iostream>

class Car {

private:

	char* brand;

	char* model;

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

	void Print(std::ostream& = std::cout) const;
	
};
