#include "AOC_01.h"

AOC_01::AOC_01(std::string fileName) :
	curDirection(North),
	doubleLocationFound(false)
{
	curLocation.x = 0;
	curLocation.y = 0;

	locations.push_back(curLocation);

	//open input file
	std::string input = readFile(fileName);
	if (input == "") return;

	//split string at ',' and remove whitespace at the front and the back
	elements = splitString(input, ',');
	removeWhiteSpaces(elements);

	for (int i = 0; i < (int)elements.size(); i++)
	{
		//get direction and number
		char dir = elements[i].substr(0, 1).c_str()[0];
		int count = atoi(elements[i].substr(1).c_str());

		//compute new direction
		getNewDirection(dir);
		//move forward
		for (int i = 0; i < count; i++)
		{
			moveToNewLocation();
			if (!doubleLocationFound)
			{
				checkLocation();
			}
		}
		
	}

	//calculate distance to HQ
	int distance = std::abs(curLocation.x + curLocation.y);

	std::cout << "--- Challenge 01 A ---" << std::endl;
	std::cout << "Location x[" << curLocation.x << "], y[" << curLocation.y << "]." << std::endl;
	std::cout << "Distance to Easter Bunny HQ [" << distance << "]." << std::endl;
}

void AOC_01::showFirstDoubleLocation()
{
	int distance = std::abs(firstDoubleLocation.x + firstDoubleLocation.y);
	
	std::cout << "--- Challenge 01 B ---" << std::endl;
	std::cout << "Location x[" << firstDoubleLocation.x << "], y[" << firstDoubleLocation.y << "]." << std::endl;
	std::cout << "Distance to Easter Bunny HQ [" << distance << "]." << std::endl;
}

void AOC_01::checkLocation()
{
	for (int i = 0; i < (int)locations.size(); i++)
	{
		if (locations[i].x == curLocation.x && locations[i].y == curLocation.y)
		{
			firstDoubleLocation = curLocation;
			doubleLocationFound = true;
			return;
		}
	}
	locations.push_back(curLocation);
}

void AOC_01::moveToNewLocation()
{
	if (curDirection == North)
		curLocation.y++;
	else if (curDirection == East)
		curLocation.x++;
	else if (curDirection == South)
		curLocation.y--;
	else
		curLocation.x--;
}

void AOC_01::getNewDirection(char dir)
{
	if (dir != 'R' && dir != 'L')
	{
		std::cout << "No valid direction was given!" << std::endl;
		return;
	}

	int number = curDirection;
	if (dir == 'L')
		number--;
	else
		number++;

	//check enum boundaries
	if (number == -1)
		number = West;
	else if (number == numberOfItems)
		number = North;

	curDirection = (Direction)number;
}