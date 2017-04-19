#include "Rational.h"

Rational::Rational(long long n , long long d ) : numerator(n) , denominator(d){

	if (denominator == 0)
		denominator = 1;

}

//Euclidean's algorithm ...
long long Rational::gcd(long long a, long long b){

	a = abs(a);
	b = abs(b);

	long long temp = 0;

	while (b != 0) {
		temp = a % b;
		a = b;
		b = temp;
	}

	return a;

}


void Rational::Simplify(){

	long long g = gcd(numerator, denominator);

	numerator /= g;
	denominator /= g;

}

Rational Rational::simplified()const
{
	Rational r  = *this;
	r.Simplify();

	return r;
}

Rational& Rational::operator+=(const Rational& rhs){

	numerator = numerator*rhs.denominator + rhs.numerator*denominator;
	denominator *= rhs.denominator;

	return *this;
	
}

Rational& Rational::operator-=(const Rational& rhs){

	numerator = numerator*rhs.denominator - rhs.numerator*denominator;
	denominator *= rhs.denominator;

	return *this;
}

Rational& Rational::operator*=(const Rational& rhs){
	
	numerator *= rhs.numerator;
	denominator *= rhs.denominator;

	return *this;
}

Rational& Rational::operator/=(const Rational& rhs){
	
	numerator *= rhs.denominator;
	denominator *= rhs.numerator;

	return *this;
}

//single operators + , - , * , / etc should not be friend functions , because 
//they use the public operators += and etc
//const because a + b = c it not valid , copy because the result is a new object 
const Rational operator+(const Rational& lhs, const Rational& rhs) { 
	
	//creating the new object using copy constructor
	//then use operator+=
	return Rational(lhs) += rhs;

}

const Rational operator-(const Rational& lhs, const Rational& rhs) {

	return Rational(lhs) -= rhs;

}

const Rational operator*(const Rational& lhs, const Rational& rhs) {

	return Rational(lhs) *= rhs;

}

const Rational operator/(const Rational& lhs, const Rational& rhs) {

	return Rational(lhs) /= rhs;

}

//Rational::operator double() const{
	//return (double)numerator / (double)denominator;
//}

double Rational::asDouble() const{
	return (double)numerator / (double)denominator;
}

Rational& Rational::operator++(){ 

	numerator += denominator;
	return *this;
}

const Rational Rational::operator++(int){ 

	Rational temp(*this);
	this->operator++();

	return temp;
}

Rational& Rational::operator--(){

	numerator -= denominator;
	return *this;
	
}

const Rational Rational::operator--(int){

	Rational temp(*this);
	this->operator--();

	return temp;
}

bool operator==(const Rational& rhs, const Rational& lhs){

	return (lhs.numerator*rhs.denominator == lhs.denominator*rhs.numerator) ? true : false;

}

bool operator!=(const Rational& rhs, const Rational& lhs) {

	return !(rhs==lhs);

}

bool operator<(const Rational& lhs, const Rational& rhs){

	return (lhs.numerator*rhs.denominator < lhs.denominator*rhs.numerator) ? true : false;

}

bool operator> (const Rational& lhs, const Rational& rhs) { 
	return rhs < lhs;
}

bool operator<=(const Rational& lhs, const Rational& rhs) { 
	return !(lhs > rhs); 
}

bool operator>=(const Rational& lhs, const Rational& rhs) { 
	return !(lhs < rhs); 
}

std::ostream& operator<<(std::ostream& ofs, const Rational& r){
	
	 return ofs << "" << r.numerator << '\\' << r.denominator;
	 
}

std::istream& operator>>(std::istream& ifs, Rational& r){
	
	return ifs >> r.numerator >> r.denominator;

}
