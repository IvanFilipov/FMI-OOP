#pragma once

#include<iostream>

//useful enumeration for formating
enum Align {
	Right,
	Middle,
	Left
};

class Element{

public:

	Element(const char*,bool = false);
	Element(const Element&);
	Element& operator=(const Element&);
	virtual ~Element();


	//only interface
	virtual const char* convertToHtml() = 0; 

	virtual Element* clone() = 0; 

	//interface + realization
	bool CheckHidden()const;
	const char* getText()const;

	void Hide();
	void Reveal();

	

protected:

	char* textSlot;
	bool isHidden;

};

