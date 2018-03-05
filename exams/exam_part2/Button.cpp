#include "Button.h"


Button::Button(const char * src) : Element(src) {

}

Button::Button(const Button& other) : Element(other) {

}

Button& Button::operator=(const Button& other) {

	if (this != &other) {

		Button::operator=(other);

	}

	return *this;
}



const char * Button::convertToHtml(){
	
	static char FormatBuffer[256];
	memset(FormatBuffer, 0, 256); //make sure that the memory is clean

	strcat(FormatBuffer, "<input type=\"button\" value=\"");
	strcat(FormatBuffer, textSlot);
	strcat(FormatBuffer, "\"> </br>\n");

	return FormatBuffer;
}

Element* Button::clone() {

	//this is how we make a new heap object as same as ours 
	//and we return base class pointer in order to use the polymorphism
	return new Button(*this);
}