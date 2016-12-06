#pragma once
#include "../general/InputHandler.h"
#include "../general/CharCount.h"
#include <algorithm>

class AOC_06
{
public:
	AOC_06(std::string fileName);

	

private:
	//members
	std::string message;
	std::vector<std::vector<CharCount> > chrCount;
	//methods
	void countOccurences(std::string str);
	void addChar(char chr, std::vector<CharCount>& vec);
};

