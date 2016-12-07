#pragma once
#include "../general/InputHandler.h"

class AOC_07
{
public:
	AOC_07(std::string fileName);

	

private:
	//members
	int countA, countB;
	std::vector<std::string> ipParts, hyperParts, bab;

	//methods
	bool checkAbba(std::vector<std::string> vec);
	bool findABA(std::string bab_str);
	bool findBAB();
	void splitIP(std::string ip);
};

