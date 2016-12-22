#include "AOC_22.h"

AOC_22::AOC_22(std::string fileName)
{
	//open input file
	std::string input = readFile(fileName);
	if (input == "") return;

	//get the nodes from the input file
	std::vector<std::string> lines = splitString(input, '\n');
	for (int i = 2; i < (int)lines.size(); i++)
	{
		std::vector<std::string> node = splitString(lines[i], ' ');
		int indexX = node[0].find('-') +2;
		int indexY = node[0].find('-', indexX);
		int x = std::stoi(node[0].substr(indexX, indexY - indexX));
		int y = std::stoi(node[0].substr(indexY + 2));
		nodes.push_back(PC(Coordinate{ x, y }, 
			std::stoi(node[1].substr(0, node[1].length() - 1)),
			std::stoi(node[2].substr(0, node[2].length() - 1)),
			std::stoi(node[3].substr(0, node[3].length() - 1)),
			std::stoi(node[4].substr(0, node[4].length() - 1))));
	}

	std::cout << "--- Challenge 22 A ---" << std::endl;
	std::cout << " [" << countViablePairs() << "]." << std::endl;
	
	std::cout << "--- Challenge 22 B ---" << std::endl;
	//std::cout << " [" << solutionB << "]." << std::endl;
	std::cout << std::endl;
}

int AOC_22::countViablePairs()
{
	int count = 0;
	for (size_t a = 0; a < nodes.size(); a++)
	{
		for (size_t b = 0; b < nodes.size(); b++)
		{
			if (a == b) continue;

			if (nodes[a].getUsed() != 0)
			{
				if (nodes[b].getAvail() >= nodes[a].getUsed())
					count++;
			}
		}
	}
	return count;
}