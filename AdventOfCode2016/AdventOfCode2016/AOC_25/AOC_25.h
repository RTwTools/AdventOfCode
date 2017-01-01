#pragma once
#include "../general/InputHandler.h"

class AOC_25
{
public:
	AOC_25(std::string fileName);

private:
	//members
	std::vector<int> passReg;
	std::vector<std::vector<std::string> > commands;
	bool clockSignal;
	int regA, line, lastTransmit, count;
	//methods
	int executeCommand(std::vector<std::string> command);
	int getValue(std::string str);
	int getRegIndex(std::string reg);
	void setNewSignal();
};

