#pragma once

#include "Element.h"

class Password : public Element{

private:

	bool isReq;

public:

	Password(const char*,bool);
	Password(const Password&);
	Password& operator= (const Password&);


	//~Horse(); we don't have our destructor cuz we are gonna use
	// the base class' one
	virtual const char* convertToHtml();
	virtual Element* clone();

	void SetReq(bool);

};

