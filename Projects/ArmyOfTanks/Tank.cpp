#include"Tank.h"
#include"string.h"


Tank::Tank() :name(nullptr), ShotPower(0) {

}

Tank::Tank(const char* n, size_t sp = 0,size_t hp = 0) : ShotPower(sp) , HitPoints(hp) {

	name = new char[strlen(n) + 1];

	strcpy(name, n);

}

Tank::Tank(const Tank& other) {

	CopyFrom(other);
}

Tank& Tank::operator=(const Tank& other) {

	if (this != &other) {
		delete[]name;

		CopyFrom(other);
	}

	return *this;

}

Tank::~Tank(){

	delete[]name;

}

void Tank::CopyFrom(const Tank& other) {

	name = new char[strlen(other.name) + 1];

	strcpy(name, other.name);

	ShotPower = other.ShotPower;
	HitPoints = other.HitPoints;
}


size_t Tank::GetShotPwr()const {

	return ShotPower;
}

size_t Tank::GetHitPoints() const{
	
	return HitPoints;
}

void Tank::SetHitPoints(size_t nHitP){
	
	HitPoints = nHitP;
}

void Tank::WriteToBin(std::ofstream& ofs){

	ofs.write((char*)&ShotPower, sizeof(int));
	ofs.write((char*)&HitPoints, sizeof(int));


	int NameLen = strlen(name);
	ofs.write((char*)&NameLen, sizeof(int));

	ofs.write(name, NameLen * sizeof(char));

}

void Tank::ReadFromBin(std::ifstream& ifs){

	//cleaning our object
	delete[]name;
	ShotPower = 0;
	HitPoints = 0;

	ifs.read((char*)&ShotPower, sizeof(int));
	ifs.read((char*)&HitPoints, sizeof(int));


	int NameLen ;
	ifs.read((char*)&NameLen, sizeof(int));

	name = new char[NameLen + 1];
	ifs.read(name, NameLen * sizeof(char));
	
	name[NameLen] = '\0';
}
