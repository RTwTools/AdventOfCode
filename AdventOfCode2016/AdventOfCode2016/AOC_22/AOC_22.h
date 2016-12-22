#pragma once
#include "../general/InputHandler.h"
#include "PC.h"

class AOC_22
{
public:
	AOC_22(std::string fileName);

private:
	//members
	std::vector<PC> nodes;

	//methods
	int countViablePairs();
};

