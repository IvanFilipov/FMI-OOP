#pragma once


class Nvector{

private :

	double * data;
	int size;

public:

	//the BIG FOUR
	Nvector();
	~Nvector();
	Nvector& operator=(const Nvector &);
	Nvector(const Nvector &);


	//alternative cctor
	Nvector(int);

	void Resize(int);

	double operator[](int) const;
	double& operator[](int);

	Nvector& operator+=(const Nvector&);

	Nvector operator+(const Nvector&) const;

	Nvector& operator-=(const Nvector&);

	Nvector operator-(const Nvector&) const;

	Nvector& operator*=(double);

	Nvector operator*(double) const;

	Nvector& operator/=(double);

	Nvector operator/(double) const;

	double operator%(const Nvector&)const;

	void Print() const;
};

