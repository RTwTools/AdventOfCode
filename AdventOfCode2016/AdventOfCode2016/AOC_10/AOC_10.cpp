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

				//ignore output destination
				int destLow, destHigh;
				if (commands[i][5] == "output")
					destLow = -1;
				else
					destLow = std::stoi(commands[i][6]);
				if (commands[i][10] == "output")
					destHigh = -1;
				else
					destHigh = std::stoi(commands[i][11]);

				transportChips(vectorId, destHigh, destLow);
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
	//std::cout << " [" << solutionB << "]." << std::endl;
	std::cout << std::endl;
}

void AOC_10::transportChips(int vectorId, int destBotHigh, int destBotLow)
{
	int highChip, lowChip;
	bots[vectorId].releaseChips(&lowChip, &highChip);

	if (destBotHigh != -1)
		addToBot(destBotHigh, highChip);
	if (destBotLow != -1)
		addToBot(destBotLow, lowChip);
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

int AOC_10::getBotVectorId(int botId)
{
	for (size_t i = 0; i < bots.size(); i++)
	{
		if (botId == bots[i].id)
			return i;
	}
	return -1;
}