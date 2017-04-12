#pragma once
#include<fstream>

class Tank {

private:

	char* name;
	size_t ShotPower;
	size_t HitPoints;
	
public:

	Tank();
	Tank(const char*, size_t ,size_t);
	Tank(const Tank&);
	Tank& operator=(const Tank&);
	~Tank();

private:

	void CopyFrom(const Tank&);

public:

	size_t GetShotPwr()const;

	size_t GetHitPoints()const;

	void SetHitPoints(size_t);

	void WriteToBin(std::ofstream&);

	void ReadFromBin(std::ifstream&);
};
