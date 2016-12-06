#pragma once
#include "../general/InputHandler.h"
#include"../general/CharCount.h"
#include <algorithm>

class AOC_04
{
public:
	AOC_04(std::string fileName);

private:
	//members
	int sectorSum;
	int northPoleSectorID;
	std::vector<CharCount> chrCount;

	//methods
	bool checkRoom(std::vector<std::string> room, int * roomSectorID);
	bool compareChecksum(std::string checksum);
	int getChecksumAndID(std::string sectorIDChecksum, std::string * checksum);
	void countOccurences(std::vector<std::string> str);
	void addChar(char chr);
	void decodeRoomName(std::vector<std::string> &room, int shift);
	void shiftChar(char * chr, int shift);
};

