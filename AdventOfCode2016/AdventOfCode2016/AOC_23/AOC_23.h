#pragma once
#include "../general/InputHandler.h"

#define ONE_ARGUMENT  2
#define TWO_ARGUMENTS 3

class AOC_23
{
public:
	AOC_23(std::string fileName);

private:
	//members
	int line;
	std::vector<int> passReg;
	std::vector<std::vector<std::string> > commands;
	//methods
	int executeCommand(std::vector<std::string> command);
	int getValue(std::string str);
	int getRegIndex(std::string reg);
	bool isRegister(std::string str);
};

