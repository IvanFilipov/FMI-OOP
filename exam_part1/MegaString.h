#pragma once
#include<iostream>

//MegaString = MulString + GrString
class MegaString{

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
	friend std::istream& operator>>(std::istream&, MegaString&);


public:

	long GetW()const;
	bool ContainSym(char)const;

};


const MegaString operator+(const MegaString&, const MegaString&);
const MegaString operator*(const MegaString&, int);
const MegaString operator*( int,const MegaString&);


const MegaString operator/(const MegaString&, const MegaString&);
const MegaString operator%(const MegaString&, const MegaString&);

bool operator==(const MegaString&, const MegaString&);
bool operator!=(const MegaString&, const MegaString&);

