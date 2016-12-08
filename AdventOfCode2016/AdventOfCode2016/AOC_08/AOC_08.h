#pragma once
#include "../general/InputHandler.h"

class AOC_08
{
public:
	AOC_08(std::string fileName);

private:
	//members
	std::vector<std::string> display;
	//methods
	void printDisplay();
	int countPixels();
	void rotateColumn(std::vector<std::string> commands);
	void rotateRow(std::vector<std::string> commands);
	void turnDisplayOn(std::string values);
};

