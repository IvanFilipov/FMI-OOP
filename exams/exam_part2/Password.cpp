#include "Password.h"




Password::Password(const char * src,bool req) : Element(src),isReq(req){

}

Password::Password(const Password& other) : Element(other),isReq(other.isReq){

}

Password& Password::operator=(const Password& other){

	if (this != &other) {

		Password::operator=(other);
		isReq = other.isReq;

	}

	return *this;
}


Element* Password::clone(){

	//this is how we make a new heap object as same as ours 
	//and we return base class pointer in order to use the polymorphism
	return new Password(*this);
}

void Password::SetReq(bool req){

	isReq = req;
}

const char * Password::convertToHtml() {

	static char FormatBuffer[256];
	memset(FormatBuffer, 0, 256); //make sure that the memory is clean

	strcat(FormatBuffer, textSlot);
	strcat(FormatBuffer, "<input type=\"password\" ");

	if (isReq)
		strcat(FormatBuffer, "required");

	strcat(FormatBuffer, "> </br>\n");

	return FormatBuffer;

}



