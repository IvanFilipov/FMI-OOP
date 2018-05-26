#include "FigureContainer.h"

FigureContainer::FigureContainer() : figures(nullptr), size(0) {
	//...
}


FigureContainer::~FigureContainer() {

	for (size_t i = 0; i < size; i++)
		delete figures[i];

	delete[] figures;
}

void FigureContainer::push_back(Figure* newFig) {

	if (newFig == nullptr)
		return;

	
	FigurePtr* newFigures = new FigurePtr[size + 1];

	//using the old pointers
	for (size_t i = 0; i < size; i++)
		newFigures[i] = figures[i];

	newFigures[size] = newFig;

	size++;

	//cleaning only the array of pointers 
	//not the pointers themselves
	delete[] figures;

	figures = newFigures;
}


Figure * FigureContainer::back() const {

	if (size == 0)
		return nullptr;
	else
		return figures[size - 1];
}

Figure * FigureContainer::getAt(size_t pos) const {

	if (pos >= size)
		return nullptr;
	else
		return figures[pos];
}
