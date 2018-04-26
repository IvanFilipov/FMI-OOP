#pragma once
#ifndef TANK_H_INCLUDED
#define TANK_H_INCLUDED

class Tank
{
private:

	char* name;
	size_t ShootPower;	// Value between 1 and 100
	size_t ShellWeight;	// Value between 1 and 20
	size_t pos;
	size_t angle;

public:

	Tank();
	Tank(const char* name, size_t power, size_t shellWg, size_t pos);
	Tank(const Tank&);
	Tank& operator=(const Tank&);

private:

	void CopyFrom(const Tank&);

public:

	size_t getPos() const { return pos; }
	size_t getSP() const { return ShootPower; }
	size_t getSW() const { return ShellWeight; }
	size_t getAngle() const { return angle; }
	

	bool ValidPos(size_t p) const { return p < 60; }
	bool MoveLeft();	// return false if at a boundary
	bool MoveRight();	// return false if at a boundary
	bool AdjustPower(int p);	// Increases ShootPower by p
	bool AdjustWeight(int w);	// Increase ShellWeight by w
	bool AdjustAngle(int a);	// Increase Angle by a
};

#endif // !TANK_H_INCLUDED