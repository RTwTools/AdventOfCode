#include "AOC_03.h"

AOC_03::AOC_03(std::string fileName) :
	count(0),
	countB(0)
{
		//open input file
	std::string input = readFile(fileName);
	if (input == "") return;

	//split string at '\n' and remove whitespace at the front and the back
	std::vector<std::string> lines = splitString(input, '\n');

	//add 3 vectors to save 3 triangles
	for (size_t i = 0; i < 3; i++)
	{
		triangles.push_back(std::vector<std::string>());
	}

	for (int i = 0; i < (int)lines.size(); i++)
	{
		std::vector<std::string> triangle = splitString(lines[i], ' ');
		removeWhiteSpaces(triangle);
		if (checkTriangle(triangle))
			count++;

		triangles[0].push_back(triangle[0]);
		triangles[1].push_back(triangle[1]);
		triangles[2].push_back(triangle[2]);

		//every 3 lines
		if (i % 3 == 2)
		{
			for (size_t j = 0; j < triangles.size(); j++)
			{
				if (checkTriangle(triangles[j]))
					countB++;
				triangles[j].clear();
			}
		}
	}

	std::cout << "--- Challenge 03 A ---" << std::endl;
	std::cout << "The number of possible triangles is [" << count << "]." << std::endl;
	
	std::cout << "--- Challenge 03 B ---" << std::endl;
	std::cout << "The number of possible triangles is [" << countB << "]." << std::endl;
	std::cout << std::endl;
}

bool AOC_03::checkTriangle(std::vector<std::string> triangle)
{
	int sideA = std::atoi(triangle[0].c_str());
	int sideB = std::atoi(triangle[1].c_str());
	int sideC = std::atoi(triangle[2].c_str());

	if (sideA + sideB > sideC && sideA + sideC > sideB && sideB + sideC > sideA)
		return true;
	return false;
}
