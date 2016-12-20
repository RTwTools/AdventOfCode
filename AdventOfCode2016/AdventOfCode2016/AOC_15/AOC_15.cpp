#include "AOC_15.h"

AOC_15::AOC_15(std::string fileName)
{
	readInput(fileName);

	while (!pushButton())
		wait();

	std::cout << "--- Challenge 15 A ---" << std::endl;
	std::cout << "You can press the button at [" << time << "]." << std::endl;

	readInput(fileName);
	discs.push_back(Disc{ 0, 11 });

	while (!pushButton())
		wait();
	
	std::cout << "--- Challenge 15 B ---" << std::endl;
	std::cout << "You can press the button at [" << time << "]." << std::endl;
	std::cout << std::endl;
}

void AOC_15::readInput(std::string fileName)
{
	discs.clear();
	time = 0;

	//open input file
	std::string input = readFile(fileName);
	if (input == "") return;

	//read input
	std::vector<std::string> lines = splitString(input, '\n');
	for (int i = 0; i < (int)lines.size(); i++)
	{
		std::vector<std::string> disc = splitString(lines[i], ' ');
		Disc newDisc;
		newDisc.nrOfPositions = std::stoi(disc[3]);
		newDisc.Position = std::stoi(disc[11].substr(0, 1));
		discs.push_back(newDisc);
	}
}

int AOC_15::TryMove(Disc disc, int moves)
{
	for (int i = 0; i < moves; i++)
		move(&disc);

	return disc.Position;
}

void AOC_15::move(Disc * disc)
{
	if (disc->Position < (disc->nrOfPositions - 1))
		disc->Position++;
	else
		disc->Position = 0;
}

bool AOC_15::pushButton()
{
	for (size_t i = 0; i < discs.size(); i++)
	{
		if (TryMove(discs[i], i + 1) != 0)
			return false;
	}
	return true;
}

void AOC_15::wait()
{
	time++;
	for (size_t i = 0; i < discs.size(); i++)
		move(&(discs[i]));
}