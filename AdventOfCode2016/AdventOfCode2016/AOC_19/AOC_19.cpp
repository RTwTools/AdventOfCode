#include "AOC_19.h"

AOC_19::AOC_19(int input)
{
	//The Josephus Problem
	//https://www.youtube.com/watch?v=uCsD3ZGzMgE
	int power = 0;
	while ((int)pow(2, power) <= input) { power++; }
	int number = (int)pow(2, --power);
	int survivor = ((input - number) * 2) + 1;

	std::cout << "--- Challenge 19 A ---" << std::endl;
	std::cout << "All the presents go to elf [" << survivor << "]." << std::endl;

	power = 0;
	while ((int)pow(3, power) < input) { power++; }
	number = (int)pow(3, --power);
	if (input > number * 2 && input != 1)
		survivor = (input - (number * 2)) * 2 + number;
	else
		survivor = input - number;
	
	std::cout << "--- Challenge 19 B ---" << std::endl;
	std::cout << "All the presents go to elf [" << survivor << "]." << std::endl;
	std::cout << std::endl;
}