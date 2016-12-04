#pragma once
#include "../general/InputHandler.h"
#include"CharCount.h"
#include <algorithm>

class AOC_04
{
public:
	AOC_04(std::string fileName);

private:
	//members
	int sectorSum;
	std::vector<CharCount> chrCount;

	//methods
	int checkRoom(std::vector<std::string> room);
	bool compareChecksum(std::string checksum);
	int getChecksumAndID(std::string sectorIDChecksum, std::string * checksum);
	void countOccurences(std::vector<std::string> str);
	void addChar(char chr);
};

