#pragma once
#include<iostream>

class Rational {

private:

	int64_t numerator;
	int64_t denominator;

private:

	int64_t gcd(int64_t, int64_t);

public:

	//can be used as transformer (implicit conversions)  
	//from long long to Rational or as a default constructor
	Rational(int64_t = 0, int64_t = 1);
	//the compiler's generated op= is good enough for us
	Rational& operator=(const Rational&) = default;

public : //some methods for better class usage
	
	void simplify();
	Rational simplified() const;

public: 

//assignment operators 
	Rational& operator+=(const Rational&);
	Rational& operator-=(const Rational&);
	Rational& operator*=(const Rational&);
	Rational& operator/=(const Rational&);

//comparison operators :

	//operator== is not a method !
	//it is a friend function
	friend bool operator==(const Rational&, const Rational&);
	friend bool operator<(const Rational&, const Rational&);

	//or could be member as well :
	/*
	bool operator<(const Rational&rhs) const{

		Rational l = this->simplified();
		Rational r = rhs.simplified();

		(l.numerator*r.denominator < l.denominator*r.numerator) ? true : false;
	}
	*/

//input - output operators 

	//the non-member functions operator<<, operator>>
	//will have access to Rational's private members
	friend std::ostream& operator<<(std::ostream&, const Rational&);
	friend std::istream& operator>>(std::istream&, Rational&);


//type convert operators

	//cast operators
	//operator double()const;
	double asDouble()const;

	//C++ way of creating predictable operator bool
	//explicit operator bool() const;

//increment	- decrement operators

	//add and take
	Rational& operator++(); //<-prefix ++i;
	//take and add
	const Rational operator++(int); //takes int as a rule , but uses 0
									//constant return, because i++++ shouldn't be possible

	Rational& operator--();
	const Rational operator--(int);

//arithmetic unary operators

	//TODO
	//Rational operator+() const;
	//Rational operator-() const;
};

//outside operators realizations :

//arithmetic operators

//single operators + , - , * , / etc should not be friend functions , because 
//they use the public operators += and etc
//constant because a + b = c is not valid, copy because the result is a new object 
const Rational operator+(const Rational& , const Rational&);

const Rational operator-(const Rational& , const Rational&);

const Rational operator*(const Rational& , const Rational&);

const Rational operator/(const Rational& , const Rational&);


//comparators

//friend function of the class Rational, so it has access to private members
inline
bool operator==(const Rational& rhs, const Rational& lhs) {

	return  (lhs.numerator * rhs.denominator ==
			lhs.denominator * rhs.numerator);
}

inline
bool operator!=(const Rational& rhs, const Rational& lhs) {

	return !(rhs == lhs);
}

inline
bool operator<(const Rational& lhs, const Rational& rhs) {

	return (lhs.numerator * rhs.denominator <
			lhs.denominator * rhs.numerator);
}

inline
bool operator>(const Rational& lhs, const Rational& rhs) {

	return rhs < lhs;
}

inline
bool operator<=(const Rational& lhs, const Rational& rhs) {

	return !(lhs > rhs);
}

inline
bool operator>=(const Rational& lhs, const Rational& rhs) {

	return !(lhs < rhs);
}




