#pragma once
#include "../general/InputHandler.h"
#include "../general/Coordinate.h"
#include <queue>
#include "Move.h"

class AOC_13
{
public:
	AOC_13(int input);

private:
	//members
	std::vector<Coordinate> locations;

	//methods
	//void printMaze(int input);
	int breadthFirstSearch(Move root, Coordinate goal);
	void addLocation(Coordinate coord);
};

