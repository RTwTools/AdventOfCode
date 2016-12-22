#pragma once
#include <vector>
#include <string>
#include "../general/Coordinate.h"
#include "../general/md5.h"

#define UP    0
#define DOWN  1
#define LEFT  2
#define RIGHT 3

const char neighborsChar[4] = { 'U', 'D', 'L', 'R' };
const Coordinate neighborsCoord[] = { Coordinate{ 0, -1 }, Coordinate{ 0, 1 }, Coordinate{ -1, 0 },Coordinate{ 1, 0 } };

class PC
{
private:
	//members
	Coordinate coord_;
	//std::vector<Route> children;
	int size_, used_, avail_, use_;
	
	//methods
	//std::vector<bool> checkDoors(std::string str);
	//void generateChildren();

public:
	PC(Coordinate c, int size, int used, int avail, int use);
	int getSize() { return size_; }
	int getUsed() { return used_; }
	int getAvail() { return avail_; }
	int getUse() { return use_; }
	//std::vector<Route> getChildren();
	//int getNrOfSteps() { return (int)route.length(); }
	//std::string getPath() { return route; }
	Coordinate getLocation() { return coord_; }
};