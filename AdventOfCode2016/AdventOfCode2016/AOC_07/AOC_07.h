#pragma once
#include "../general/InputHandler.h"

class AOC_07
{
public:
	AOC_07(std::string fileName);

	

private:
	//members
	int countA, countB;
	std::vector<std::string> ipParts, hyperParts;

	//methods
	bool checkAbba(std::vector<std::string> vec);
	void splitIP(std::string ip);
};

