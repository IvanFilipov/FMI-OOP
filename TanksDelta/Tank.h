#pragma once

class Tank {

private:

	char* name;
	size_t ShootPower;
	size_t ShellWeight;
	size_t pos;

public:

	Tank();
	Tank(const char*, size_t, size_t, size_t);
	Tank(const Tank&);
	Tank& operator=(const Tank&);

private:

	void CopyFrom(const Tank&);
	//static int CalcWind();

public:

	//returns the difference between where the shot has fallen and where the flag is
	//int Fire(size_t FlagPos);

	//void PrintShot()const;




};
