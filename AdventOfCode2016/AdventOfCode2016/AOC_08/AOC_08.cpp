#include "AOC_08.h"

AOC_08::AOC_08(std::string fileName) :
	display(6, std::string(50, '-'))
{
	//open input file
	std::string input = readFile(fileName);
	if (input == "") return;

	//split string at '\n' 
	std::vector<std::string> lines = splitString(input, '\n');

	for (int i = 0; i < (int)lines.size(); i++)
	{
		//split string at ' '
		std::vector<std::string> command = splitString(lines[i], ' ');
		
		if (command[0] == "rect")
			turnDisplayOn(command[1]);
		else if (command[1] == "column")
			rotateColumn(command);
		else if (command[1] == "row")
			rotateRow(command);
	}

	//count chars
	int countA = countPixels();

	std::cout << "--- Challenge 08 A ---" << std::endl;
	std::cout << "The number of lit pixels is [" << countA << "]." << std::endl;
	
	std::cout << "--- Challenge 08 B ---" << std::endl;
	printDisplay();
	std::cout << std::endl;
}

void AOC_08::printDisplay()
{
	for (size_t i = 0; i < display.size(); i++)
	{
		std::cout << display[i] << std::endl;
	}
}

int AOC_08::countPixels()
{
	int count = 0;
	std::cout << "Display:" << std::endl;
	for (size_t i = 0; i < display.size(); i++)
	{
		std::cout << display[i] << std::endl;
		for (size_t j = 0; j < display[i].length(); j++)
		{
			if (display[i][j] == '#')
				count++;
		}
	}
	return count;
}

void AOC_08::rotateColumn(std::vector<std::string> commands)
{
	int col = std::stoi(commands[2].substr(2));
	int nr = std::stoi(commands[4]);

	for (int i = 0; i < nr; i++)
	{
		char lastChr = display[5][col];
		for (size_t j = display.size() - 1; j > 0; j--)
		{
			display[j][col] = display[j-1][col];
		}
		display[0][col] = lastChr;
	}
}

void AOC_08::rotateRow(std::vector<std::string> commands)
{
	int row = std::stoi(commands[2].substr(2));
	int nr = std::stoi(commands[4]);

	for (int i = 0; i < nr; i++)
	{
		char lastChr = display[row][display[row].length()-1];
		display[row] = lastChr + display[row];
		display[row] = display[row].substr(0, display[row].length() -1);
	}
}

void AOC_08::turnDisplayOn(std::string values)
{
	//get display values
	int index = values.find('x');
	int x = std::stoi(values.substr(0, index));
	int y = std::stoi(values.substr(index + 1));

	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			display[i][j] = '#';
		}
	}
}