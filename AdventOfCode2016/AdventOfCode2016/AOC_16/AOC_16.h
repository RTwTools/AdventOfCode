#pragma once
#include "../general/InputHandler.h"
#include <algorithm>

#define DISK_SIZE_A 272
#define DISK_SIZE_B 35651584

class AOC_16
{
public:
	AOC_16(std::string input);

private:
	//members
	std::string data;

	//methods
	std::string generateData(std::string initialData, int length);
	std::string generateChecksum(std::string data);
};

