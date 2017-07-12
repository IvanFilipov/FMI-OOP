#pragma once
#include "G:\GitHub\FMI-OOP\Polymorphism\Farm\Element.h"


class CheckBox : public Element {

private:

	bool isChecked;

public:

	CheckBox(const char*, bool);
	CheckBox(const CheckBox&);
	CheckBox& operator= (const CheckBox&);


	//~Horse(); we don't have our destructor cuz we are gonna use
	// the base class' one
	virtual const char* convertToHtml();
	virtual Element* clone();

	void SetChecked(bool);

};


