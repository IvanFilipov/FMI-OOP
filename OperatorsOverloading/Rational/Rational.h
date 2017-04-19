#pragma once
#include<iostream>

class Rational{

private:

	long long numerator;
	long long denominator;

private:

	long long gcd(long long, long long);

public:

	//can be used as transformer from long long to Rational or as a default constructor
	Rational(long long=0,long long=1); 

	void Simplify();
	Rational simplified()const;

	Rational& operator+=(const Rational&);
	Rational& operator-=(const Rational&);
	Rational& operator*=(const Rational&);
	Rational& operator/=(const Rational&);

	//operator== is not a method !
	//it is a friend function
	friend bool operator==(const Rational&, const Rational&);
	friend bool operator<(const Rational&, const Rational&);


	//or could be member as well :
	/*
	bool operator<(const Rational&rhs)const{

		Rational l = this->simplified();
		Rational r = rhs.simplified();

		(l.numerator*r.denominator < l.denominator*r.numerator) ? true : false;
	}
	*/

	//the non-member functions operator<<, operator>>
	//will have access to Rational's private members
	friend std::ostream& operator<<(std::ostream&, const Rational&);
	friend std::istream& operator>>(std::istream&, Rational&);


	//cast operators
	//operator double()const;
	double asDouble()const;


	//add and take
	Rational& operator++(); //<-prefix ++i;
	//take and add
	const Rational operator++(int); //takes int as a rule , but uses 0
									//const return ,because i++++ shouldn't be possible

	Rational& operator--();
	const Rational operator--(int);
	
};

//outside operators realizations :

//single operators + , - , * , / etc should not be friend functions , because 
//they use the public operators += and etc
//const because a + b = c it not valid , copy because the result is a new object 
const Rational operator+(const Rational& , const Rational&);

const Rational operator-(const Rational& , const Rational&);

const Rational operator*(const Rational& , const Rational&);

const Rational operator/(const Rational& , const Rational&);


//comparators
bool operator!=(const Rational& , const Rational&);

bool operator>(const Rational& , const Rational&);

bool operator<=(const Rational& , const Rational&);

bool operator>=(const Rational& , const Rational&);




