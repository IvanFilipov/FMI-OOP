#ifndef __TANK_H__
#define __TANK_H__

#include<fstream>

class Tank {

private:

	char* name;
	unsigned int shotPower;
	unsigned int hitPoints;
	
public:

	Tank();
	Tank(const char*, size_t ,size_t);
	Tank(const Tank&);
	Tank& operator=(const Tank&);
	~Tank();

private:

	void copyFrom(const Tank&);

public:

	unsigned int getShotPwr() const;

	unsigned int getHitPoints() const;

	void setHitPoints(size_t);

	void serialize(std::ofstream&) const;

	void deserialize(std::ifstream&);
};

#endif // !__TANK_H__
