#include "Text.h"

Text::Text(const char * src,Align agn) : Element (src) ,align(agn) {

}

Text::Text(const Text& other) : Element(other),align(other.align) {

}

Text& Text::operator=(const Text& other) {

	if (this != &other) {

		Element::operator=(other);
		align = other.align;
	}

	return *this;
}

const char * Text::convertToHtml(){

	static char FormatBuffer[256];
	memset(FormatBuffer, 0, 256); //make sure that the memory is clean

	strcat(FormatBuffer, textSlot);
	strcat(FormatBuffer, "<input type=\"text\" align=\"");

	switch (align)
	{
	case Middle: 
		strcat(FormatBuffer, "middle\" "); break;

	case Left:
		strcat(FormatBuffer, "left\" "); break;

	case Right:
		strcat(FormatBuffer, "right\" "); break;

	default:
		break;
	}

	strcat(FormatBuffer, "> </br>\n");

	return FormatBuffer;
	
}



Element* Text::clone() {

	//this is how we make a new heap object as same as ours 
	//and we return base class pointer in order to use the polymorphism
	return new Text(*this);
}
