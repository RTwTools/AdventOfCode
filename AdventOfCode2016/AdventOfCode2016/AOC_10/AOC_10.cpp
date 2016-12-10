#include "AOC_10.h"

AOC_10::AOC_10(std::string fileName) :
	botA(0)
{
	//open input file
	std::string input = readFile(fileName);
	if (input == "") return;

	//split string at '\n' 
	std::vector<std::string> lines = splitString(input, '\n');

	//split commands
	for (int i = 0; i < (int)lines.size(); i++)
	{
		commands.push_back(splitString(lines[i], ' '));
	}

	//execute commands
	int i = 0;
	bool action = false;
	while (commands.size() > 0)
	{
		if (commands[i][0] == "value")
		{
			addToBot(std::stoi(commands[i][5]), std::stoi(commands[i][1]));
			commands.erase(commands.begin() + i);
			i--;
			action = true;
		}
		else if (commands[i][0] == "bot")
		{
			int vectorId = getBotVectorId(std::stoi(commands[i][1]));
			if (vectorId != -1 && bots[vectorId].hasTwoChips)
			{
				//check challenge A
				if (bots[vectorId].chipLow == 17 && bots[vectorId].chipHigh == 61)
				{
					botA = bots[vectorId].id;
				}

				//check output destination
				int destLow, destHigh;
				bool destLowOutput = false;
				bool destHighOutput = false;

				if (commands[i][5] == "output")
					destLowOutput = true;
				if (commands[i][10] == "output")
					destHighOutput = true;

				destLow = std::stoi(commands[i][6]);
				destHigh = std::stoi(commands[i][11]);

				transportChips(vectorId, destHigh, destLow, destHighOutput, destLowOutput);
				action = true;
			}
		}

		i++;
		if (i == commands.size())
		{
			i = 0;

			if (action)
				action = false;
			else
				break;
		}
	} 

	std::cout << "--- Challenge 10 A ---" << std::endl;
	std::cout << "The number of the bot is [" << botA << "]." << std::endl;
	
	std::cout << "--- Challenge 10 B ---" << std::endl;
	std::cout << "The product of the chips in the outputs is [" << calculateProductOfOutputs(0, 2) << "]." << std::endl;
	std::cout << std::endl;
}

int AOC_10::calculateProductOfOutputs(int startIndex, int endIndex)
{
	//calculate product of chips in outputs
	int product = 1;
	for (size_t i = 0; i < outputs.size(); i++)
	{
		if (outputs[i].id >= startIndex && outputs[i].id <= endIndex)
		{
			for (size_t j = 0; j < outputs[i].Chips.size(); j++)
			{
				product *= outputs[i].Chips[j];
			}
		}
	}
	return product;
}

void AOC_10::transportChips(int vectorId, int destHigh, int destLow, bool destHighOutput, bool destLowOutput)
{
	int highChip, lowChip;
	bots[vectorId].releaseChips(&lowChip, &highChip);

	if (!destHighOutput)
		addToBot(destHigh, highChip);
	else
		addToOutput(destHigh, highChip);

	if (!destLowOutput)
		addToBot(destLow, lowChip);
	else
		addToOutput(destLow, lowChip);
}

void AOC_10::addToBot(int botId, int chip)
{
	int vectorId = getBotVectorId(botId);
	if (vectorId == -1)
	{
		//bot does not exists
		Bot newBot;
		newBot.id = botId;
		newBot.receiveChip(chip);
		bots.push_back(newBot);
	}
	else
		bots[vectorId].receiveChip(chip);
}

void AOC_10::addToOutput(int outputId, int chip)
{
	int vectorId = getOutputVectorId(outputId);
	if (vectorId == -1)
	{
		//output does not exists
		Output newOutput;
		newOutput.id = outputId;
		newOutput.Chips.push_back(chip);
		outputs.push_back(newOutput);
	}
	else
		outputs[vectorId].Chips.push_back(chip);
}

int AOC_10::getBotVectorId(int botId)
{
	for (size_t i = 0; i < bots.size(); i++)
	{
		if (botId == bots[i].id)
			return i;
	}
	return -1;
}

int AOC_10::getOutputVectorId(int outputId)
{
	for (size_t i = 0; i < outputs.size(); i++)
	{
		if (outputId == outputs[i].id)
			return i;
	}
	return -1;
}