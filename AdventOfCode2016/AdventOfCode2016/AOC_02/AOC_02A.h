#pragma once
#include "../general/InputHandler.h"

class AOC_02A
{
public:
	AOC_02A(std::string fileName);

private:
	//members
	std::vector<std::string> elements;
	std::string code;
	int curNumber;

	//methods
	void move(char dir);
};

