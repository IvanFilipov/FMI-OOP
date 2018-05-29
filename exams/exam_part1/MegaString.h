#pragma once
#include<iostream>

//MegaString = MulString + GrString
class MegaString {

private:

	char* str;

public:

	MegaString();
	MegaString(const MegaString&);
	MegaString(const char*);
	MegaString& operator=(const MegaString&);
	~MegaString();

	MegaString& operator += (const MegaString&);

	MegaString& operator *= (int);

	MegaString& operator %= (const MegaString&);

	MegaString& operator /= (const MegaString&);

	friend std::ostream& operator<<(std::ostream&, const MegaString&);
	friend std::istream& operator >> (std::istream&, MegaString&);


public:

	long getW()const;
	bool containSym(char)const;

};


const MegaString operator+(const MegaString&, const MegaString&);
const MegaString operator*(const MegaString&, int);
const MegaString operator*(int, const MegaString&);


const MegaString operator/(const MegaString&, const MegaString&);
const MegaString operator%(const MegaString&, const MegaString&);

inline
bool operator==(const MegaString &lhs, const MegaString &rhs) {

	return lhs.getW() == rhs.getW();
}

inline
bool operator!=(const MegaString &lhs, const MegaString &rhs) {

	return lhs.getW() != rhs.getW();
}

