#include "AOC_02A.h"

AOC_02A::AOC_02A(std::string fileName) :
	curNumber(5)
{
	//open input file
	std::string input = readFile(fileName);
	if (input == "") return;

	//split string at '\n' and remove whitespace at the front and the back
	elements = splitString(input, '\n');
	removeWhiteSpaces(elements);

	for (int i = 0; i < (int)elements.size(); i++)
	{
		for (int j = 0; j < elements[i].length(); j++)
		{
			move(elements[i].c_str()[j]);
		}

		// add number to code
		code += std::to_string(curNumber);
	}
	

	std::cout << "--- Challenge 02 A ---" << std::endl;
	std::cout << "The bathroom code is [" << code << "]." << std::endl;
}

void AOC_02A::move(char dir)
{
	//ignore commands that go of the keypad
	if ((curNumber == 1 || curNumber == 4 || curNumber == 7) && dir == 'L')
		return;
	if ((curNumber == 3 || curNumber == 6 || curNumber == 9) && dir == 'R')
		return;
	if ((curNumber == 1 || curNumber == 2 || curNumber == 3) && dir == 'U')
		return;
	if ((curNumber == 7 || curNumber == 8 || curNumber == 9) && dir == 'D')
		return;

	//move to new key
	if (dir == 'U')
		curNumber -= 3;
	else if (dir == 'D')
		curNumber += 3;
	else if (dir == 'L')
		curNumber--;
	else if (dir == 'R')
		curNumber++;
}

