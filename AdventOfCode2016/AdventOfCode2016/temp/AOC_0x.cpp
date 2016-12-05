#include "AOC_0x.h"

AOC_0x::AOC_0x(std::string fileName)
{
	//open input file
	std::string input = readFile(fileName);
	if (input == "") return;

	//split string at '\n' 
	std::vector<std::string> lines = splitString(input, '\n');

	for (int i = 0; i < (int)lines.size(); i++)
	{
		//split string at '-' and remove whitespace at the front and the back
		std::vector<std::string> room = splitString(lines[i], '-');
		
	}

	std::cout << "--- Challenge 0x A ---" << std::endl;
	//std::cout << " [" << solutionA << "]." << std::endl;
	
	std::cout << "--- Challenge 0x B ---" << std::endl;
	//std::cout << " [" << solutionB << "]." << std::endl;
	std::cout << std::endl;
}