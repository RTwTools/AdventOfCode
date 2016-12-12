#pragma once
#include "../general/InputHandler.h"

class AOC_12
{
public:
	AOC_12(std::string fileName);

private:
	//members
	std::vector<int> passReg;
	std::vector<std::vector<std::string> > commands;
	//methods
	int executeCommand(std::vector<std::string> command);
	int getValue(std::string str);
	int getRegIndex(std::string reg);
};

