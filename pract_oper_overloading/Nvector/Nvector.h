#pragma once

class Nvector {

private:

	double * data;
	size_t size;

public:

	//the BIG FOUR
	Nvector();
	~Nvector();
	Nvector& operator=(const Nvector &);
	Nvector(const Nvector &);
	//alternative cctor
	Nvector(size_t);

private:

	void resize(size_t);

public:

	const double operator[](size_t) const;
	double& operator[](size_t);

	Nvector& operator+=(const Nvector&);

	Nvector operator+(const Nvector&) const;

	Nvector& operator-=(const Nvector&);

	Nvector operator-(const Nvector&) const;

	Nvector& operator*=(double);

	Nvector operator*(double) const;

	Nvector& operator/=(double);

	Nvector operator/(double) const;

	//scalar product
	double operator%(const Nvector&) const;

	//vector length
	double operator~() const;

	//are two vectors parallel
	bool operator||(const Nvector&) const;

	//are two vectors perpendicular
	bool operator|=(const Nvector&) const;

	void print() const;
};

