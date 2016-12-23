#include "AOC_23.h"

AOC_23::AOC_23(std::string fileName) :
	passReg(4, 0),
	line(0)
{
	//open input file
	std::string input = readFile(fileName);
	if (input == "") return;

	//split string at '\n', split commands at  ' '
	std::vector<std::string> lines = splitString(input, '\n');
	for (int i = 0; i < (int)lines.size(); i++)
		commands.push_back(splitString(lines[i], ' '));

	//execute commands
	passReg[0] = 7;

	for (;;)
	{
		if (line >= (int)commands.size()) break;
		line += executeCommand(commands[line]);
	}

	std::cout << "--- Challenge 23 A ---" << std::endl;
	std::cout << "The value in reg A is [" << passReg[0] << "]." << std::endl;

	//reset all values for part B
	passReg[1] = passReg[2] = passReg[3] = line = 0;
	passReg[0] = 12;

	//re-read commands because the new command 'tgl' changes the initial values
	commands.clear();
	for (int i = 0; i < (int)lines.size(); i++)
		commands.push_back(splitString(lines[i], ' '));

	for (;;)
	{
		if (line >= (int)commands.size()) break;
		line += executeCommand(commands[line]);
	}

	std::cout << "--- Challenge 23 B ---" << std::endl;
	std::cout << "The value in reg A is [" << passReg[0] << "]." << std::endl;
	std::cout << std::endl;
}

int AOC_23::executeCommand(std::vector<std::string> command)
{
	//optimization for my specific input
	if (line == 4)
	{
		passReg[0] = passReg[1] * passReg[3];
		passReg[2] = passReg[3] = 0;
		line = 10;
		return 0;
	}

	if (command[0] == "cpy")
	{
		if (isRegister(command[2]))
			passReg[getRegIndex(command[2])] = getValue(command[1]);
	}
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
	else if (command[0] == "tgl")
	{
		int commandID = getValue(command[1]) + line;
		if (commandID >= 0 && commandID < (int)commands.size())
		{
			if (commands[commandID].size() == ONE_ARGUMENT)
				commands[commandID][0] = (commands[commandID][0] == "inc") ? "dec" : "inc";
			else if (commands[commandID].size() == TWO_ARGUMENTS)
				commands[commandID][0] = (commands[commandID][0] == "jnz") ? "cpy" : "jnz";
		}
	}
	else
		std::cout << "invalid command: [" << command[0] << "]." << std::endl;

	return 1;
}

int AOC_23::getValue(std::string str)
{
	if (isRegister(str))
		return passReg[getRegIndex(str)];
	else
		return std::stoi(str);
}

bool AOC_23::isRegister(std::string str)
{
	return (str[0] >= 'a' && str[0] <= 'd');
}

int AOC_23::getRegIndex(std::string reg)
{
	return (int)reg[0] - (int)'a';
}