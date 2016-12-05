#pragma once
#include "../general/InputHandler.h"
#include <windows.h>
#include "md5.h"

#define FIVEZEROS	"00000"
#define INVALID     8

class AOC_05
{
public:
	AOC_05(std::string input);

private:
	//members
	std::string password, hash;
	int count, nrOfChrs, position;

	//methods
};

