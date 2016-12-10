#pragma once
#include "../general/InputHandler.h"
#include "Bot.h"
#include "Output.h"

class AOC_10
{
public:
	AOC_10(std::string fileName);

private:
	//members
	std::vector<std::vector<std::string> > commands;
	std::vector<Bot> bots;
	std::vector<Output> outputs;
	int botA;
	//methods
	void transportChips(int vectorId, int destHigh, int destLow, bool destHighOutput, bool destLowOutput);
	void addToBot(int botId, int chip);
	void addToOutput(int outputId, int chip);
	int getBotVectorId(int botId);
	int getOutputVectorId(int outputId);
	int calculateProductOfOutputs(int startIndex, int endIndex);
};

