#pragma once
#include <vector>
#include <string>
#include "Floor.h"

#define NOT_POSSIBLE 0
#define HIGHEST_FLOOR 3
#define LOWEST_FLOOR 0

enum dir
{
	down,
	up
};

class Node
{
private:
	//members
	int currentFloor;
	std::vector<Floor> floors;
	std::vector<Node> children;
	int steps;
	dir direction;

	//methods
	int moveOneItemUp();
	int moveOneItemDown();
	int moveTwoItemsUp();
	int moveTwoItemsDown();
	void generateChildren();

public:
	Node(int floor, std::vector<Floor> flrs, int stps, dir d);
	std::vector<Node> getChildren();
	int getNrOfSteps() { return steps; }
	bool checkState();
	bool isGoal();
};