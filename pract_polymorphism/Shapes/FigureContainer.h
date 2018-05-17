#pragma once

#include "Figure.h"

typedef Figure* FigurePtr;

//a polymorphic container of figures
class FigureContainer {

	FigurePtr* figures;
	size_t size;

public:

	FigureContainer();

	//no need to be copyable
	FigureContainer(const FigureContainer&) = delete;
	FigureContainer& operator=(const FigureContainer&) = delete;

	~FigureContainer();

public:

	void push_back(Figure*);
	Figure* back() const;
	Figure* getAt(size_t) const;


	size_t getSize() const {

		return size;
	}
};

