#include"Army.h"
#include<iostream>

Army::Army() :tanks(nullptr), CurSize(0), Capacity(0) {

	/*...*/
}

Army::Army(size_t size) : Capacity(size), CurSize(size) {

	tanks = new Tank[size];

}


Army::~Army() {
	Free();
}

void Army::Free() {

	delete[] tanks;

	tanks = nullptr;
	CurSize = 0;
	Capacity = 0;

}


void Army::CopyFrom(const Army& other) {

	tanks = new Tank[other.CurSize];

	for (int i = 0; i < other.CurSize; i++) {

		tanks[i] = other.tanks[i];
	}

	CurSize = other.CurSize;
	Capacity = other.Capacity;

}


Army::Army(const Army &other) :tanks(nullptr), CurSize(0), Capacity(0) {

	CopyFrom(other);

}

Army& Army::operator=(const Army& other) {

	if (this != &other) {

		Free();
		CopyFrom(other);

	}

	return *this;

}

void Army::Resize(size_t NewCap) {

	Tank *temp = tanks;

	tanks = new Tank[NewCap];

	for (int i = 0; i < CurSize; i++) {

		tanks[i] = temp[i];
	}

	Capacity = NewCap;

	delete[] temp;
}


void Army::AddTank(const Tank& elem) {

	if (CurSize >= Capacity) {

		size_t NewCap = (Capacity == 0) ? 2 : Capacity * 2;
		Resize(NewCap);
	}

	tanks[CurSize++] = elem;

}

size_t Army::GetSize()const {

	return CurSize;
}


size_t Army::GetCapacity()const {

	return Capacity;
}



bool Army::CanDestroy(size_t TargetLifePnts){

	for (int i = 0; i < CurSize; i++) {

		if (tanks[i].GetShotPwr() > TargetLifePnts)
			return true;
		
		TargetLifePnts -= tanks[i].GetShotPwr();

	}
	
	return false;

}

int Army::DestroyWithMinShots(int TargetLifePnts){

	Tank** sortedTanks = new Tank*[CurSize];
	bool* TakenPos = new bool[CurSize];

	for (int i = 0; i < CurSize; i++)
		TakenPos[i] = false;


	int SortedPos = 0;
	int CurBestIndex = 0;
	int CurMaxPwr = 0;
	
	for (int i = 0; i < CurSize; i++) {

		CurMaxPwr = 0;

		for (int j = 0; j < CurSize; j++) {

			if ((tanks[j].GetShotPwr() > CurMaxPwr) && !TakenPos[j]) {
				
				CurMaxPwr = tanks[j].GetShotPwr();
				CurBestIndex = j;
			}
		}

		TakenPos[CurBestIndex] = true;
		sortedTanks[SortedPos++] = &tanks[CurBestIndex];
		CurBestIndex = 0;

	}

	/* DEBUG INFO
	std::cout << std::endl;
	for (int i = 0; i < CurSize; i++)
		std::cout << sortedTanks[i]->GetShotPwr() << " ";
	std::cout << std::endl;
	*/

	int shotsTaken = 0;

	do {

		TargetLifePnts -= sortedTanks[shotsTaken]->GetShotPwr();
		shotsTaken++;
	
	} while (TargetLifePnts > 0 );

	delete[]sortedTanks;
	delete[]TakenPos;

	return shotsTaken;

}

void Army::AttackAt(const Tank& t){

	if (!CanDestroy(t.GetHitPoints())) {

		std::cout << "the target cannot be destroyed , sir ! ";
		return;

	}
	
	std::cout << "Processing with the attack ...\n";

	std::cout << "Destroying the target with " << t.GetHitPoints() 
		<< "hit points required only " 
		<< DestroyWithMinShots(t.GetHitPoints())
		<< " from our tanks to shot,sir !\n";

}

void Army::Serialize(const char* fName){

	std::ofstream file(fName, std::ios::binary | std::ios::trunc);

	if (!file.is_open()) {
		std::cout << "can't open file\n";
		return;
	}

	file.write((char*)&CurSize, sizeof(size_t));
	file.write((char*)&Capacity, sizeof(size_t));
	
	if (!file.good()) {
		std::cout << "error writing\n";
		return;
	}

	for (int i = 0; i < CurSize; i++) {

		tanks[i].WriteToBin(file);

		if (!file.good()) {
			std::cout << "error writing\n";
			return;
		}
	}

	if (file.good()) {
		std::cout << "serializing successful!\n";
		return;
	}

}

void Army::Deserialize(const char *fName){

	Free();

	std::ifstream file(fName, std::ios::binary);

	if (!file.is_open()) {
		std::cout << "can't open file\n";
		return;
	}

	file.read((char*)&CurSize, sizeof(size_t));
	file.read((char*)&Capacity, sizeof(size_t));

	if (!file.good()) {
		std::cout << "error reading\n";
		return;
	}

	tanks = new Tank[Capacity];

	for (int i = 0; i < CurSize; i++) {

		tanks[i].ReadFromBin(file);

		if (!file.good()) {
			std::cout << "error reading\n";
			return;
		}
	}

	if (file.good())
		std::cout << "deserializing successful!\n";
	
}




