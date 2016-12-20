#pragma once
#include "../general/InputHandler.h"

struct Disc
{
	int Position;
	int nrOfPositions;
};

class AOC_15
{
public:
	AOC_15(std::string fileName);

private:
	//members
	int time;
	std::vector<Disc> discs;

	//methods
	void readInput(std::string fileName);
	int TryMove(Disc disc, int moves);
	void move(Disc * disc);
	bool pushButton();
	void wait();
};

