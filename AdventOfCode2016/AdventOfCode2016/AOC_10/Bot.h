#pragma once
#include <iostream>

struct Bot
{
	int id;
	int chipLow = -1;
	int chipHigh = -1;
	bool hasTwoChips = false;
	void receiveChip(int chip)
	{
		if (chipLow == -1)
			chipLow = chip;
		else if (chipHigh == -1)
		{
			if (chipLow > chip)
			{
				chipHigh = chipLow;
				chipLow = chip;
			}
			else
				chipHigh = chip;

			hasTwoChips = true;
		}
		else
			std::cout << "Bot " << id << "Already has two chips, can't accept #" << chip << "." << std::endl;
	}

	void releaseChips(int * low, int * high)
	{
		*low = chipLow;
		*high = chipHigh;
		hasTwoChips = false;
		chipLow = chipHigh = -1;
	}
};