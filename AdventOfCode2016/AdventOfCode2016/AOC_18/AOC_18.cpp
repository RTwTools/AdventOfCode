#include "AOC_18.h"

AOC_18::AOC_18(std::string fileName)
{
	std::string startLine = readFile(fileName);

	generateFloor(startLine, 40);
	std::cout << "--- Challenge 18 A ---" << std::endl;
	std::cout << "The number of safe tiles is [" << getCount(SAFETILE) << "]." << std::endl;
	
	generateFloor(startLine, 400000);
	std::cout << "--- Challenge 18 B ---" << std::endl;
	std::cout << "The number of safe tiles is [" << getCount(SAFETILE) << "]." << std::endl;
	std::cout << std::endl;
}

void AOC_18::generateFloor(std::string startRow, int rows)
{
	chrCount.clear();
	std::string currentLine = startRow;
	std::string previousLine;
	int count = 1;

	countOccurences(currentLine);
	while (count < rows)
	{
		previousLine = currentLine;
		currentLine.clear();

		for (size_t i = 0; i < previousLine.length(); i++)
		{
			if (i == 0)
				currentLine += getTileType(SAFETILE + previousLine.substr(i, 2));
			else if (i == previousLine.length() - 1)
				currentLine += getTileType(previousLine.substr(i - 1, 2) + SAFETILE);
			else
				currentLine += getTileType(previousLine.substr(i - 1, 3));
		}
		countOccurences(currentLine);
		count++;
	}
}

char AOC_18::getTileType(std::string tiles)
{
	if (tiles[TILE_LEFT] == TRAPTILE && tiles[TILE_CENTER] == TRAPTILE && tiles[TILE_RIGHT] == SAFETILE)
		return TRAPTILE;
	if (tiles[TILE_LEFT] == SAFETILE && tiles[TILE_CENTER] == TRAPTILE && tiles[TILE_RIGHT] == TRAPTILE)
		return TRAPTILE;
	if (tiles[TILE_LEFT] == TRAPTILE && tiles[TILE_CENTER] == SAFETILE && tiles[TILE_RIGHT] == SAFETILE)
		return TRAPTILE;
	if (tiles[TILE_LEFT] == SAFETILE && tiles[TILE_CENTER] == SAFETILE && tiles[TILE_RIGHT] == TRAPTILE)
		return TRAPTILE;

	return SAFETILE;
}

int AOC_18::getCount(char c)
{
	for (size_t i = 0; i < chrCount.size(); i++)
	{
		if (chrCount[i].chr == c)
			return chrCount[i].count;
	}

	std::cout << "Char [" << c << "] not found!" << std::endl;
	return 0;
}

void AOC_18::countOccurences(std::string str)
{
	for (size_t j = 0; j < str.length(); j++)
		addChar(str.c_str()[j]);
}

void AOC_18::addChar(char chr)
{
	for (size_t i = 0; i < chrCount.size(); i++)
	{
		if (chrCount[i].chr == chr)
		{
			//char exists
			chrCount[i].count++;
			return;
		}
	}

	//char is new
	CharCount newChar;
	newChar.chr = chr;
	newChar.count = 1;
	chrCount.push_back(newChar);
}