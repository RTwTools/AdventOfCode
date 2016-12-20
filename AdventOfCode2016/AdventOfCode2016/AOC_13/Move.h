#pragma once
#include <vector>
#include <string>
#include "../general/Coordinate.h"

#define OPEN_SPACE ' '
#define WALL       '#'

class Move
{
private:
	//members
	Coordinate curCoord;
	std::vector<Coordinate> visited;
	std::vector<Move> children;
	int steps, favNumber;

	//methods
	void generateChildren();
	int numberOfBits(int i);
	char getLocationInfo(Coordinate coord);
	bool isVisited(Coordinate coord);
	void checkNewMove(Coordinate coord);

public:
	Move(Coordinate c, std::vector<Coordinate> path, int moves, int favNr);
	std::vector<Move> getChildren();
	int getNrOfSteps() { return steps; }
	Coordinate getCoordinate() { return curCoord; }
};