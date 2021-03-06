#include "AOC_05.h"

AOC_05::AOC_05(std::string input) :
	password("--------"),
	count(0),
	nrOfChrs(0)
{
	std::cout << "--- Challenge 05 A ---" << std::endl;
	std::cout << "The password is: " << std::endl;

	while (nrOfChrs < 8)
	{
		hash = md5(input + std::to_string(count));
		if (hash.find(FIVEZEROS, 0) == 0)
		{
			password[nrOfChrs] = hash[5];
			std::cout << password << std::endl;
			nrOfChrs++;
		}
		count++;
	}

	std::cout << "--- Challenge 05 B ---" << std::endl;
	std::cout << "The password is: " << std::endl;

	//reset values
	count = nrOfChrs = 0;
	password = "--------";

	while (nrOfChrs < 8)
	{
		hash = md5(input + std::to_string(count));
		if (hash.find(FIVEZEROS, 0) == 0)
		{
			position = isdigit(hash[5]) ? hash[5] - '0' : INVALID;
			if (position <= 7 && password[position] == '-')
			{
				password[position] = hash[6];
				std::cout << password << std::endl;
				nrOfChrs++;
			}
		}
		count++;
	}
	std::cout << std::endl;
}