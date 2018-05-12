#pragma once

class Student {

private: 
	 
	unsigned int fn;
	char* name;

public:

	//no default constructor on purpose!!!
	Student(const char*, unsigned int);
	Student(const Student&);  
	Student& operator=(const Student&); 
	~Student(); 
	
public:

	unsigned int getFn() const { 

		return fn;
	}

	const char* getName() const { 

		return name;
	}

	void setName(const char*);  
};