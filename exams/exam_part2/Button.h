#pragma once

#include "Element.h"

class Button : public Element{

public:

	Button(const char*);
	Button(const Button&);
	Button& operator= (const Button&);

	virtual const char* convertToHtml();
	virtual Element* clone();


};

