#include "AOC_02.h"

AOC_02::AOC_02(std::string fileName) :
	curKey(5),
	curKeyB('5')
{
	//open input file
	std::string input = readFile(fileName);
	if (input == "") return;

	//split string at '\n' and remove whitespace at the front and the back
	elements = splitString(input, '\n');
	removeWhiteSpaces(elements);

	for (int i = 0; i < (int)elements.size(); i++)
	{
		for (int j = 0; j < (int)elements[i].length(); j++)
		{
			char dir = elements[i].c_str()[j];
			move(dir);
			moveB(dir);
		}

		// add number to code
		code += std::to_string(curKey);
		codeB += std::string(1, curKeyB);
	}
	

	std::cout << "--- Challenge 02 A ---" << std::endl;
	std::cout << "The bathroom code is [" << code << "]." << std::endl;

	std::cout << "--- Challenge 02 B ---" << std::endl;
	std::cout << "The bathroom code is [" << codeB << "]." << std::endl;
	std::cout << std::endl;
}

void AOC_02::move(char dir)
{
	//ignore commands that go of the keypad
	if ((curKey == 1 || curKey == 4 || curKey == 7) && dir == 'L')
		return;
	if ((curKey == 3 || curKey == 6 || curKey == 9) && dir == 'R')
		return;
	if ((curKey == 1 || curKey == 2 || curKey == 3) && dir == 'U')
		return;
	if ((curKey == 7 || curKey == 8 || curKey == 9) && dir == 'D')
		return;

	//move to new key
	if (dir == 'U')
		curKey -= 3;
	else if (dir == 'D')
		curKey += 3;
	else if (dir == 'L')
		curKey--;
	else if (dir == 'R')
		curKey++;
}

void AOC_02::moveB(char dir)
{
	if (curKeyB == '1')
	{
		if (dir == 'D')
			curKeyB = '3';
		else
			return;
	}
	else if (curKeyB == '5')
	{
		if (dir == 'R')
			curKeyB++;
		else
			return;
	}
	else if (curKeyB == '9')
	{
		if (dir == 'L')
			curKeyB--;
		else
			return;
	}
	else if (curKeyB == 'D')
	{
		if (dir == 'U')
			curKeyB = 'B';
		else
			return;
	}
	else if (curKeyB >= CHAR0 + 2 && curKeyB <= CHAR0 + 4 && dir == 'D')
		curKeyB += 4;
	else if (curKeyB >= CHAR0 + 6 && curKeyB <= CHAR0 + 8 && dir == 'D')
		curKeyB += 11;
	else if (curKeyB >= CHARA && curKeyB <= CHARA + 2 && dir == 'U')
		curKeyB -= 11;
	else if (curKeyB >= CHAR0 + 6 && curKeyB <= CHAR0 + 8 && dir == 'U')
		curKeyB -= 4;
	else if ((curKeyB == CHAR0 + 2 || curKeyB == CHAR0 + 3 ||
		curKeyB == CHAR0 + 6 || curKeyB == CHAR0 + 7 ||
		curKeyB == CHARA || curKeyB == CHARA + 1)
		&& dir == 'R')
		curKeyB++;
	else if ((curKeyB == CHAR0 + 3 || curKeyB == CHAR0 + 4 ||
		curKeyB == CHAR0 + 7 || curKeyB == CHAR0 + 8 ||
		curKeyB == CHARA + 1 || curKeyB == CHARA + 2)
		&& dir == 'L')
		curKeyB--;
	else if (curKeyB == CHAR0 + 3 && dir == 'U')
		curKeyB -= 2;
	else if (curKeyB == CHAR0 + 6 && dir == 'L')
		curKeyB--;
	else if (curKeyB == CHAR0 + 8 && dir == 'R')
		curKeyB++;
	else if (curKeyB == CHARA + 1 && dir == 'D')
		curKeyB += 2;
}

