#pragma once
#include "../general/InputHandler.h"

#define CHAR0	48
#define CHARA	65

class AOC_02
{
public:
	AOC_02(std::string fileName);

private:
	//members
	std::vector<std::string> elements;
	std::string code, codeB;
	int curKey;
	char curKeyB;

	//methods
	void move(char dir);
	void moveB(char dir);
};

