#include "AOC_12.h"

AOC_12::AOC_12(std::string fileName) :
	passReg(4, 0)
{
	//open input file
	std::string input = readFile(fileName);
	if (input == "") return;

	//split string at '\n', split commands at  ' '
	std::vector<std::string> lines = splitString(input, '\n');
	for (int i = 0; i < (int)lines.size(); i++)
	{
		commands.push_back(splitString(lines[i], ' '));
	}

	//execute commands
	int line = 0;
	int count = 0;

	for (;;)
	{
		count++;
		if (line >= (int)commands.size()) break;
		line += executeCommand(commands[line]);
	}

	std::cout << "--- Challenge 12 A ---" << std::endl;
	std::cout << "The value in reg A is [" << passReg[0] << "] It[" << count << "]." << std::endl;

	//reset all values for part B
	passReg[0] = passReg[1] = passReg[3] = count = line = 0;
	passReg[2] = 1;


	for (;;)
	{
		count++;
		if (line >= (int)commands.size()) break;
		line += executeCommand(commands[line]);
	}
	
	std::cout << "--- Challenge 12 B ---" << std::endl;
	std::cout << "The value in reg A is [" << passReg[0] << "] It[" << count << "]." << std::endl;
	std::cout << std::endl;
}

int AOC_12::executeCommand(std::vector<std::string> command)
{
	if (command[0] == "cpy")
		passReg[getRegIndex(command[2])] = getValue(command[1]);
	else if (command[0] == "inc")
		passReg[getRegIndex(command[1])] += 1;
	else if (command[0] == "dec")
		passReg[getRegIndex(command[1])] -= 1;
	else if (command[0] == "jnz")
	{
		int value = getValue(command[1]);
		if (value != 0)
			return (getValue(command[2]));
	}
	else
		std::cout << "invalid command: [" << command[0] << "]." << std::endl;

	return 1;
}

int AOC_12::getValue(std::string str)
{
	int value;
	try
	{
		value = std::stoi(str);
	}
	catch (const std::exception&)
	{
		int reg = (int)str[0] - (int)'a';
		value = passReg[getRegIndex(str)];
	}
	return value;
}

int AOC_12::getRegIndex(std::string reg)
{
	return (int)reg[0] - (int)'a';
}