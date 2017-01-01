#include "AOC_25.h"

AOC_25::AOC_25(std::string fileName) :
	passReg(4, 0),
	regA(-1),
	clockSignal(false),
	lastTransmit(1),
	line(0),
	count(0)
{
	//open input file
	std::string input = readFile(fileName);
	if (input == "") return;

	//get commands
	std::vector<std::string> lines = splitString(input, '\n');
	for (int i = 0; i < (int)lines.size(); i++)
		commands.push_back(splitString(lines[i], ' '));

	//execute commands
	for (;;)
	{
		if (!clockSignal)
			setNewSignal();
		if (line >= (int)commands.size()) break;
		line += executeCommand(commands[line]);

		if (count > 50)
			break;
	}

	std::cout << std::endl << "--- Challenge 12 A ---" << std::endl;
	std::cout << "The value for reg A is [" << regA << "]." << std::endl;
}

void AOC_25::setNewSignal()
{
	passReg[1] = passReg[2] = passReg[3] = line = count = 0;
	lastTransmit = -1;
	passReg[0] = ++regA;
	clockSignal = true;
	std::cout << std::endl << "Starting new transmission [" << regA << "]: ";
}

int AOC_25::executeCommand(std::vector<std::string> command)
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
	else if (command[0] == "out")
	{
		int value = getValue(command[1]);
		std::cout << value;

		if ((value == 1 || value == 0) && value != lastTransmit)
		{
			lastTransmit = value;
			count++;
		}
		else
			clockSignal = false;
	}
	else
		std::cout << "invalid command: [" << command[0] << "]." << std::endl;

	return 1;
}

int AOC_25::getValue(std::string str)
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

int AOC_25::getRegIndex(std::string reg)
{
	return (int)reg[0] - (int)'a';
}