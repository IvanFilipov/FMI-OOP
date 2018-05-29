#pragma once
#include<iostream>

template<typename T>
class Box {

	T foo;

public:

	Box(const T& bar) : foo(bar) {}
	const T& getFoo() const;
};

template<typename T>
const T& Box<T>::getFoo() const {

	return foo;
}

//specialization for the method when using ints
template<>
const int& Box<int>::getFoo() const {

	return foo + 42;
}

//specialization for the class when using char*
template<>
class Box<char*> {

private:

	char* str;

public:

	Box(const char* s) : str(nullptr) {

		std::cout << "using char* specialization";
		size_t size = strlen(s) + 1;

		str = new char[size];
		strncpy_s(str, size, s, size);
	}

	const char* getFoo() const { return str; };
};


