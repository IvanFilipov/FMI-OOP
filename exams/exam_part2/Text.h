#pragma once
#include "Element.h"

class Text : public Element{

private:

	Align align;

public:

	Text(const char*,Align);
	Text(const Text&);
	Text& operator= (const Text&);

	virtual const char* convertToHtml();

	virtual Element* clone() ;

};

