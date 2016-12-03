#pragma once

#include "Direction.h"
#include "Coordinate.h"
#include "../general/InputHandler.h"

class AOC_01
{
public:
	AOC_01(std::string fileName);
	void showFirstDoubleLocation();

private:
	//members
	Coordinate curLocation;
	Coordinate firstDoubleLocation;
	Direction curDirection;
	std::vector<std::string> elements;
	std::vector<Coordinate> locations;
	bool doubleLocationFound;

	//methods
	void moveToNewLocation();
	void getNewDirection(char dir);
	void checkLocation();
};