#include "Form.h"
#include <fstream>



Form::Form() : allElements(nullptr) , size(0) {

}

Form::Form(const Form& other){

	allElements = new Element*[other.size]; // allocating memory for all base pointers

	for (int i = 0; i < other.size; i++) {

		allElements[i] = other.allElements[i]->clone(); // each pointer will point to a
													  //clone of the other object 
													  //all pointer are Animal* , but the real	
													  //allocated objects are Horse,Dog or Duck
	}

	size = other.size;
}

Form& Form::operator=(const Form & other){
	
	if (this != &other) {

		clear();

		allElements = new Element*[other.size]; // allocating memory for all base pointers

		for (int i = 0; i < other.size; i++)
			allElements[i] = other.allElements[i]->clone(); 

		size = other.size;
	}

	return *this;

}


Form::~Form(){

	clear();

}

void Form::clear(){

	for (int i = 0; i < size; i++)
		delete allElements[i];

	delete allElements;
	allElements = nullptr;
	size = 0;

}

void Form::AddElement(Element* newElement){

	//memory for + one base pointer
	Element** newElements = new Element*[size + 1];

	//using the old pointers
	for (int i = 0; i < size; i++)
		newElements[i] = allElements[i];

	newElements[size] = newElement;

	size++;

	//cleaning only the array of pointers 
	//not the pointers themselves
	delete [] allElements;
	
	allElements = newElements;
}

void Form::CreateHtml(const char* fileName){

	char* fullName = new char[strlen(fileName) + 5]; // + .html

	strcpy(fullName, fileName);

	strcat(fullName, ".html");

	std::ofstream ofs(fullName);

	if (!ofs.is_open()) {

		std::cout << "can't open file\n";
		return;
	}

	ofs << "<!DOCTYPE html>\n<html>\n\t<body>\n\t\t<form>\n"; //give by the task


	for (int i = 0; i < size; i++) {

		if(!allElements[i]->CheckHidden())
			ofs << allElements[i]->convertToHtml();

	}

	ofs << "\t\t</form>\n\t</body>\n\t</html>\n";

	if (ofs)
		std::cout << "successfully created !\n";

	ofs.close();

}

const Element & Form::operator[](int index) const{
	
	if (index >= size)
		throw std::out_of_range("invalid index!");

	return *allElements[index]; //dereferencing the object

}

Element & Form::operator[](int index){

	if (index >= size)
		throw std::out_of_range("invalid index!");

	return *allElements[index];
}

void Form::HideAtIndex(int index){

	if (index >= size)
		throw std::out_of_range("invalid index!");

	return allElements[index]->Hide();

}

void Form::RevealAtIndex(int index) {

	if (index >= size)
		throw std::out_of_range("invalid index!");

	return allElements[index]->Reveal();

}

int Form::FindByText(const char * text){

	for (int i = 0; i < size; i++) {

		if (strcmp(allElements[i]->getText(), text) == 0)
			return i;
	}

	return -1; //could not be found
}


