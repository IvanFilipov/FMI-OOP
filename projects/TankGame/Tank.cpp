#include"Tank.h"
#include"string.h"

Tank::Tank() : name(nullptr), ShootPower(1), ShellWeight(1), pos(0), angle(45)
{}

Tank::Tank(const char* n, size_t sp = 1, size_t sw = 1, size_t p = 0) 
	: name(nullptr), ShootPower(sp), ShellWeight(sw), pos(p), angle(45)
{
	if (n)
	{
		size_t len = strlen(n) + 1;
		name = new char[len];
		strcpy_s(name, len, n);
	}

	if (ShellWeight < 1)
		ShellWeight = 1;
	if (ShellWeight > 20)
		ShellWeight = 20;
	if (ShootPower < 1)
		ShootPower = 1;
	if (ShootPower > 100)
		ShootPower = 100;
}

Tank::Tank(const Tank& other) : name(nullptr)
{
	CopyFrom(other);
}

Tank& Tank::operator=(const Tank& other)
{

	if (this != &other)
	{
		delete[]name;
		CopyFrom(other);
	}

	return *this;

}

void Tank::CopyFrom(const Tank& other)
{
	if (other.name)
	{
		size_t len = strlen(other.name) + 1;
		name = new char[len];
		strcpy_s(name, len, other.name);
	}
	ShootPower = other.ShootPower;
	ShellWeight = other.ShellWeight;
	pos = other.pos;
	angle = other.angle;
}

////////////////////////////////////////////////////////////

bool Tank::MoveLeft()
{
	if (ValidPos(pos - 1))
	{
		pos--;
		return true;
	}
	return false;
}

bool Tank::MoveRight()
{
	if (ValidPos(pos + 1))
	{
		pos++;
		return true;
	}
	return false;
}

bool Tank::AdjustPower(int p)
{
	int newPow = ShootPower + p;
	if (newPow >= 1 && newPow <= 100)
	{
		ShootPower = newPow;
		return true;
	}
	return false;
}

bool Tank::AdjustWeight(int w)
{
	int newWg = ShellWeight + w;
	if (newWg >= 1 && newWg <= 20)
	{
		ShellWeight = newWg;
		return true;
	}
	return false;
}

bool Tank::AdjustAngle(int a)
{
	int newA = angle + a;
	if (newA >= 0 && newA <= 90)
	{
		angle = newA;
		return true;
	}
	return false;
}
