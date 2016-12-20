#pragma once
#include "../general/InputHandler.h"
#include "Route.h"
#include <queue>

class AOC_17
{
public:
	AOC_17(std::string input);

private:
	//members
	std::string data;

	//methods
	std::string breadthFirstSearch(Route root, Coordinate goal, bool partB);
};

