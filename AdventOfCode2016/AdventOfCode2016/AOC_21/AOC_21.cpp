#include "AOC_21.h"

AOC_21::AOC_21(std::string fileName)
{
	//open input file
	std::string input = readFile(fileName);
	if (input == "") return;

	//split string at '\n' 
	std::vector<std::string> lines = splitString(input, '\n');

	//get commands
	for (int i = 0; i < (int)lines.size(); i++)
		commands.push_back(splitString(lines[i], ' '));
	
	std::cout << "--- Challenge 21 A ---" << std::endl;
	std::cout << "The scrambled password is [" << scramble("abcdefgh") << "]." << std::endl;
	
	std::cout << "--- Challenge 21 B ---" << std::endl;
	std::cout << "The unscrambled password is [" << unScramble("fbgdceah") << "]." << std::endl;
	std::cout << std::endl;
}

std::string AOC_21::unScramble(std::string str)
{
	std::string unscrambled = str;
	for (int i = (int)commands.size() -1; i >= 0; i--)
	{
		if (commands[i][0] == "swap")
		{
			if (commands[i][1] == "position")
				swap(unscrambled, std::stoi(commands[i][2]), std::stoi(commands[i][5]));
			else if (commands[i][1] == "letter")
				swap(unscrambled, commands[i][2][0], commands[i][5][0]);
		}
		else if (commands[i][0] == "rotate")
		{
			if (commands[i][1] == "based")
				rotateReverse(unscrambled, false, commands[i][6][0]); //reversed new function + reversed bool
			else
			{
				bool right = (commands[i][1] == "left") ? true : false; //reversed bool
				rotate(unscrambled, right, std::stoi(commands[i][2]));
			}
		}
		else if (commands[i][0] == "reverse")
			reverse(unscrambled, std::stoi(commands[i][2]), std::stoi(commands[i][4]));
		else if (commands[i][0] == "move")
			move(unscrambled, std::stoi(commands[i][5]), std::stoi(commands[i][2])); //turned arguments
		else
			std::cout << "Unknown command [" << commands[i][0] << "] !" << std::endl;
	}
	return unscrambled;
}

std::string AOC_21::scramble(std::string str)
{
	std::string scrambled = str;
	for (size_t i = 0; i < commands.size(); i++)
	{
		if (commands[i][0] == "swap")
		{
			if (commands[i][1] == "position")
				swap(scrambled, std::stoi(commands[i][2]), std::stoi(commands[i][5]));
			else if (commands[i][1] == "letter")
				swap(scrambled, commands[i][2][0], commands[i][5][0]);
		}
		else if (commands[i][0] == "rotate")
		{
			if (commands[i][1] == "based")
				rotate(scrambled, true, commands[i][6][0]);
			else
			{
				bool right = (commands[i][1] == "left") ? false : true;
				rotate(scrambled, right, std::stoi(commands[i][2]));
			}
		}
		else if (commands[i][0] == "reverse")
			reverse(scrambled, std::stoi(commands[i][2]), std::stoi(commands[i][4]));
		else if (commands[i][0] == "move")
			move(scrambled, std::stoi(commands[i][2]), std::stoi(commands[i][5])); 
		else
			std::cout << "Unknown command [" << commands[i][0] << "] !" << std::endl;
	}
	return scrambled;
}

void AOC_21::swap(std::string& str, int pos1, int pos2)
{
	if (pos1 == -1 || pos2 == -1)
	{
		std::cout << "Chars not found" << std::endl;
		return;
	}
	char chr = str[pos1];
	str[pos1] = str[pos2];
	str[pos2] = chr;
}

void AOC_21::swap(std::string& str, char c1, char c2)
{
	swap(str, (int)str.find(c1), (int)str.find(c2));
}

void AOC_21::rotate(std::string& str, bool right, int steps)
{
	for (int i = 0; i < steps; i++)
	{
		if (right)
			str = str[str.length() - 1] + str.substr(0, str.length() - 1);
		else
			str = str.substr(1) + str[0];
	}
}

void AOC_21::rotate(std::string& str, bool right, char c)
{
	int steps = str.find(c);
	steps = (steps >= 4) ? steps + 2 : steps + 1;
	rotate(str, right, steps);
}

void AOC_21::rotateReverse(std::string& str, bool right, char c)
{
	int steps = 0;
	int index = str.find(c);
	if (index % 2)
		steps = (index / 2) + 1;
	else if (index == 0) steps = 1;
	else if (index == 2) steps = 6;
	else if (index == 4) steps = 7;

	rotate(str, right, steps);
}

void AOC_21::reverse(std::string& str, int pos1, int pos2)
{
	std::reverse(str.begin() + pos1, str.begin() + pos2 + 1);
}

void AOC_21::move(std::string& str, int pos1, int pos2)
{
	char c = str[pos1];
	str = str.substr(0, pos1) + str.substr(pos1 + 1);
	str = str.substr(0, pos2) + c + str.substr(pos2);
}