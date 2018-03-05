#include "Form.h"
#include "G:\GitHub\oop-toAdd\HTMLform\HTMLform\CheckBox.h"
#include "Password.h"
#include "Button.h"
#include "Text.h"
#include "Element.h"


int main() {

	Form myForm;

	myForm.AddElement(new Text("User :" ,Middle));
	myForm.AddElement(new Password("Password : ",true));
	myForm.AddElement(new CheckBox("I agree! ", true));
	myForm.AddElement(new Button("Submit"));
	
	myForm.CreateHtml("test0");

	Form copyForm = myForm;

	copyForm.CreateHtml("test1");

	try {
		std::cout << "at index 3 : " << myForm[3].getText() << '\n';
	}
	catch (std::out_of_range& e) {

		std::cout << e.what() << '\n';

	}


	try {
		std::cout << "at index 10 : " << myForm[10].getText() << '\n';
	}
	catch (std::out_of_range& e) {

		std::cout << e.what() << '\n';

	}

	std::cout << "searching for \"Submit\"" << myForm.FindByText("Submit") << '\n';

	myForm.HideAtIndex(2);

	myForm.CreateHtml("test2");

	myForm.RevealAtIndex(2);

	myForm.CreateHtml("test3");

	return 0;
}