#pragma once
#include "../general/InputHandler.h"
#include <algorithm>

class AOC_20
{
public:
	AOC_20(std::string fileName);

private:
	//members
	unsigned long ip;
	std::vector<std::pair<unsigned long, unsigned long> > rules;
};

