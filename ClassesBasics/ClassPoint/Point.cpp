#include "Point.h" //задължително включваме "главата" на класа
#include<iostream>
#include<math.h>


//обърнете внимание на синтаксиса :
//първо е типа на върнатата стойност , след
//това е името на функцията - целият "път" до нея
//а именно казваме ,че е част от класа Point
//след това не забравяме ,че сме декларирали метода като const
void Point::Print()const {

	std::cout << '(' << x << ','
		<< y << ')' << '\n';
}

//друго важно нещо е ,че боравим с член данните 
//директно (без сет/гет функции) , защото на практика
//сме вътре в класа и имаме видимост към скритите данни

void Point::Read() {

	std::cin >> x >> y;

}

double Point::DistToBeg()const {

	return sqrt((x*x) + (y*y));


}

int Point::GetX()const {

	return x;
}

int Point::GetY()const {

	return y;
}

void Point::Set(int newX,int newY) {


	x = newX;
	y = newY;

}


//Други варианти на Set метода

/*

possible ,but uglier

//тук имената на параметрите съвпадат с имената на член данните
//затова изрично покказваме ,че едните принадлежат на клас , чрез указателя this
void Point::Set(int x,int y) {

      this->x = x;
	  this->y = y;
}

don't do this at home , at work or in your homeworks 

//този синтаксис е опасен за здравето
void Point::Set(int _x,int _y) {

    x = _x;
	y = _y;
}



*/


