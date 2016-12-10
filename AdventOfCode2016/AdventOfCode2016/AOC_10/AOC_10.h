#pragma once
#include "../general/InputHandler.h"
#include "Bot.h"

class AOC_10
{
public:
	AOC_10(std::string fileName);

private:
	//members
	std::vector<std::vector<std::string> > commands;
	std::vector<Bot> bots;
	int botA;
	//methods
	void transportChips(int botId, int destBotHigh, int destBotLow);
	void addToBot(int botId, int chip);
	int getBotVectorId(int botId);
};

