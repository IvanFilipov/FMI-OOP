#include<iostream>

//#include <stdint.h> //this is where the types are defined

#define BYTESIZE 8
#define BYTE_PER_UINT32 4

uint8_t getByte(uint32_t num, uint8_t pos) {

	//zeros everywhere except the wanted byte 
	uint32_t mask = 0xFF << (pos * BYTESIZE);

	return (num & mask) >> (pos * BYTESIZE);

}

uint32_t setByte(uint32_t num, uint8_t pos, uint8_t val) {

	//ones every where except the wanted byte
	uint32_t clearMask = ~(0xFF << (pos * BYTESIZE));

	//the wanted byte is now free (only zeros)
	num &= clearMask;

	//will contain only zeros except 
	//the wanted byte on the wanted position
	uint32_t setMask = val << (pos * BYTESIZE);

	return num | setMask;

}

uint32_t swapBytes(uint32_t num, uint8_t fPos, uint8_t sPos) {

	uint8_t firstByte = getByte(num, fPos);
	uint8_t secondByte = getByte(num, sPos);

	num = setByte(num, sPos, firstByte);

	return setByte(num, fPos, secondByte);

}

int main() {

	uint32_t number = 0x7DA1F2BC;

	std::cout << std::hex << number << std::endl;

	uint8_t fPos, sPos;
	std::cout << "enter two numbers for positions [0,3] : ";
	std::cin >> fPos >> sPos;
	
	//char to int bug fixing
	fPos -= '0';
	sPos -= '0';

	if (fPos >= BYTE_PER_UINT32 ||
		sPos >= BYTE_PER_UINT32) {

		std::cout << "Invalid input!";
		return 1;
	}

	std::cout << "Number after swapping bytes : "
		<< std::hex << swapBytes(number, fPos, sPos) << std::endl;

	return 0;
}