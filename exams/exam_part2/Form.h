#pragma once

#include "Element.h"

//this class is a polymorphic container
//it has an array of pointer to the base class

class Form{

private:

	Element** allElements;
	size_t size;

public:

	Form();
	Form(const Form&);
	Form& operator=(const Form&);
	~Form();

	//or we can just disallow operator= and copy ctor
	//if we want our farm to be uncopyable
	//Farm(const Farm&) = delete;
	//Farm& operator=(const Farm&) = delete;

private:

	void clear();

public:

	void AddElement(Element*);

	void CreateHtml(const char*);

	const Element& operator[](int)const;
	Element& operator[](int);

	void HideAtIndex(int);

	void RevealAtIndex(int);

	int FindByText(const char*);

};

