#include "CheckBox.h"

CheckBox::CheckBox(const char * src, bool req) : Element(src), isChecked(req) {

}

CheckBox::CheckBox(const CheckBox& other) : Element(other), isChecked(other.isChecked) {

}

CheckBox& CheckBox::operator=(const CheckBox& other) {

	if (this != &other) {

		CheckBox::operator=(other);
		isChecked = other.isChecked;

	}

	return *this;
}


Element* CheckBox::clone() {

	//this is how we make a new heap object as same as ours 
	//and we return base class pointer in order to use the polymorphism
	return new CheckBox(*this);
}

void CheckBox::SetChecked(bool ch) {

	isChecked = ch;
}

const char * CheckBox::convertToHtml() {

	static char FormatBuffer[256];
	memset(FormatBuffer, 0, 256); //make sure that the memory is clean

	strcat(FormatBuffer, "<input type=\"checkbox\" ");

	if (isChecked)
		strcat(FormatBuffer, "checked> ");

	strcat(FormatBuffer, textSlot);
	strcat(FormatBuffer, " </br> \n");

	return FormatBuffer;

}
