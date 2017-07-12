#include "Element.h"



Element::Element(const char * n, bool hidden) : isHidden(hidden) {

	if (n == nullptr) {
		textSlot = new char;
		*textSlot = '\0';
	}
	else {

		textSlot = new char[strlen(n) + 1];
		strcpy(textSlot, n);

	}

}

Element::Element(const Element& other){

	textSlot = new char[strlen(other.textSlot) + 1];
	strcpy(textSlot, other.textSlot);

	isHidden = other.isHidden;
}

Element& Element::operator=(const Element& other){
	
	if (this != &other) {

		delete[] textSlot;
		textSlot = new char[strlen(other.textSlot) + 1];
		strcpy(textSlot, other.textSlot);

		isHidden = other.isHidden;
	}

	return *this;
}

Element::~Element(){

	delete[] textSlot;
}

bool Element::CheckHidden() const{

	return isHidden;
}

const char * Element::getText() const{

	return textSlot;
}

void Element::Hide(){

	isHidden = true;

}

void Element::Reveal(){

	isHidden = false;
}
