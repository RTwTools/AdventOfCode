#pragma once
#include "../general/InputHandler.h"

class AOC_03
{
public:
	AOC_03(std::string fileName);

private:
	//members
	int count, countB;
	std::vector<std::vector<std::string> > triangles;

	//methods
	bool checkTriangle(std::vector<std::string> triangle);
};

