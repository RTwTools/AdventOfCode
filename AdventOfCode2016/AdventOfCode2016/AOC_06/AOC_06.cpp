#include "AOC_06.h"

AOC_06::AOC_06(std::string fileName) :
	chrCount(8, std::vector<CharCount>())
{
	//open input file
	std::string input = readFile(fileName);
	if (input == "") return;

	//split string at '\n' 
	std::vector<std::string> lines = splitString(input, '\n');

	for (int i = 0; i < (int)lines.size(); i++)
	{
		countOccurences(lines[i]);
	}

	for (size_t i = 0; i < chrCount.size(); i++)
	{
		std::sort(chrCount[i].begin(), chrCount[i].end(), CharCount::before);
		message += chrCount[i][0].chr;
		messageB += chrCount[i][chrCount[i].size() - 1].chr;
	}

	std::cout << "--- Challenge 0x A ---" << std::endl;
	std::cout << "The error-corrected message is [" << message << "]." << std::endl;
	
	std::cout << "--- Challenge 0x B ---" << std::endl;
	std::cout << "The error-corrected message is [" << messageB << "]." << std::endl;
	std::cout << std::endl;
}

void AOC_06::countOccurences(std::string str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		addChar(str[i], chrCount[i]);
	}
}

void AOC_06::addChar(char chr, std::vector<CharCount> &vec)
{
	for (size_t i = 0; i < vec.size(); i++)
	{
		if (vec[i].chr == chr)
		{
			//char exists
			vec[i].count++;
			return;
		}
	}

	//char is new
	CharCount newChar;
	newChar.chr = chr;
	newChar.count = 1;
	vec.push_back(newChar);
}