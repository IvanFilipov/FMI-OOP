#include <iostream>
#include<ctime>

class Shape {

public:

	virtual void draw() { 
	
		std::cout << "I am just a shape :(\n";
	}

	virtual ~Shape(){}
};

class Circle : public Shape {

	void draw() {

		std::cout << "I am circle\n";
	}

};

class Rectangle : public Shape {

	void draw() {

		std::cout << "I am rectangle\n";
	}

};

class Triangle : public Shape {

	void draw() {

		std::cout << "I am triangle\n";
	}
};

int main() {
	
	srand(time(nullptr));

	Shape** collection = new Shape* [10];

	int c;

	for (int i = 0; i < 10; i++) {

		c = rand() % 3;

		switch (c) {

		case 0 :
			collection[i] = new Circle;
			break;
		case 1:
			collection[i] = new Rectangle;
			break;
		case 2:
			collection[i] = new Triangle;
		}

	}

	for (int i = 0; i < 10; i++)
		collection[i]->draw();

	for (int i = 0; i < 10; i++)
		delete collection[i];

	delete[] collection;

	return 0;
}
