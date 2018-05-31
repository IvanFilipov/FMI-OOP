#include "Rational.h"

Rational::Rational(int64_t n, int64_t d) : numerator(n), denominator(d) {

	if (denominator == 0) //or throw exception...
		denominator = 1;
}

//Euclidean's algorithm ...
int64_t Rational::gcd(int64_t a, int64_t b) {

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

void Rational::simplify() {

	long long g = gcd(numerator, denominator);

	numerator /= g;
	denominator /= g;
}

Rational Rational::simplified() const {

	Rational r  = *this;
	r.simplify();

	return r;
}

Rational& Rational::operator+=(const Rational& rhs) {

	numerator = numerator * rhs.denominator +
				rhs.numerator * denominator;

	denominator *= rhs.denominator;

	return *this;
}

Rational& Rational::operator-=(const Rational& rhs) {

	numerator = numerator * rhs.denominator - 
				rhs.numerator * denominator;

	denominator *= rhs.denominator;

	return *this;
}

Rational& Rational::operator*=(const Rational& rhs) {
	
	numerator *= rhs.numerator;
	denominator *= rhs.denominator;

	return *this;
}

Rational& Rational::operator/=(const Rational& rhs) {
	
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

//Rational::operator double() const {
	//return (double)numerator / (double)denominator;
//}

double Rational::asDouble() const {

	return static_cast<double>(numerator) / denominator;
}

Rational::operator bool() const {

	return numerator != 0;
}

bool Rational::operator!() const {

	return !this->operator bool();
}

Rational& Rational::operator++() { 

	numerator += denominator;
	return *this;	
}

const Rational Rational::operator++(int) { 

	Rational temp(*this); //old value
	this->operator++(); //increment our value

	return temp; //return the old
}

Rational& Rational::operator--() {

	numerator -= denominator;
	return *this;
}

const Rational Rational::operator--(int) {

	Rational temp(*this);
	this->operator--();

	return temp;
}

std::ostream& operator<<(std::ostream& ofs, const Rational& r) {
	
	 return ofs << r.numerator << '/' 
				<< r.denominator;
}

std::istream& operator>>(std::istream& ifs, Rational& r) {
	
	return ifs >> r.numerator >> r.denominator;
}
