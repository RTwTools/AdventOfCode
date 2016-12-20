#pragma once
#include <vector>
#include <string>
#include "../general/Coordinate.h"
#include "../general/md5.h"

#define UP    0
#define DOWN  1
#define LEFT  2
#define RIGHT 3

const char pathChar[4] = { 'U', 'D', 'L', 'R' };
const Coordinate pathCoord[] = { Coordinate{ 0, -1 }, Coordinate{ 0, 1 }, Coordinate{ -1, 0 },Coordinate{ 1, 0 } };

class Route
{
private:
	//members
	Coordinate curCoord;
	std::vector<Route> children;
	std::string route, code;
	
	//methods
	std::vector<bool> checkDoors(std::string str);
	void generateChildren();

public:
	Route(Coordinate c, std::string path, std::string passCode);
	std::vector<Route> getChildren();
	int getNrOfSteps() { return (int)route.length(); }
	std::string getPath() { return route; }
	Coordinate getCoordinate() { return curCoord; }
};