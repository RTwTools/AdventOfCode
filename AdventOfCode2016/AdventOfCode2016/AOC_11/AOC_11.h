#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <queue>
#include "Floor.h"
#include "Node.h"

class AOC_11
{
public:
	AOC_11();

private:
	//members
	
	//methods
	void setFloorsP1(std::vector<Floor> &floors);
	void setFloorsP2(std::vector<Floor> &floors);
	void setFloorsTest(std::vector<Floor> & floors);
	int breadthFirstSearch(Node root);
};

