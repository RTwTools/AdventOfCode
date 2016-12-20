#pragma once
#include "../general/InputHandler.h"
#include "../general/CharCount.h"

#define SAFETILE '.'
#define TRAPTILE '^'

#define TILE_LEFT   0
#define TILE_CENTER 1
#define TILE_RIGHT  2

class AOC_18
{
public:
	AOC_18(std::string fileName);

private:
	//members
	std::vector<CharCount> chrCount;
	//methods
	void generateFloor(std::string startRow, int rows);
	char getTileType(std::string tiles);
	void countOccurences(std::string str);
	void addChar(char chr);
	int getCount(char c);
};

