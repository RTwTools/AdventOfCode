#include "AOC_13.h"

AOC_13::AOC_13(int input)
{
	Coordinate start{ 1, 1 };
	Coordinate goal{ 31, 39 };

	Move root(start, std::vector<Coordinate>(), 0, input);

	std::cout << "--- Challenge 13 A ---" << std::endl;
	std::cout << "The minimum number of steps is [" << breadthFirstSearch(root, goal) << "]." << std::endl;
	
	std::cout << "--- Challenge 13 B ---" << std::endl;
	std::cout << "The number of locations is [" << (int)locations.size() << "]." << std::endl;
	std::cout << std::endl;
}

int AOC_13::breadthFirstSearch(Move root, Coordinate goal)
{
	std::queue<Move> q;
	std::vector<Move> children;

	q.push(root);
	int level = 0;
	while (!q.empty())
	{
		Move n = q.front();

		if (n.getNrOfSteps() > level)
			level++;

		q.pop();

		//add unique locations to list (Part B)
		if (level <= 50)
			addLocation(n.getCoordinate());

		//check goal state
		if (n.getCoordinate() == goal)
			return n.getNrOfSteps();

		//put next level in queue
		children = n.getChildren();
		for (size_t i = 0; i < children.size(); i++)
		{
			q.push(children[i]);
		}
	}

	std::cout << "Goal not found!" << std::endl;
	return 0;
}

void AOC_13::addLocation(Coordinate coord)
{
	for (size_t i = 0; i < locations.size(); i++)
	{
		if (coord == locations[i])
			return;
	}
	locations.push_back(coord);
}

/*
void AOC_13::printMaze(int input)
{
	//generate maze
	std::vector <std::string> maze(50, std::string(".................................................."));
	for (int y = 0; y < (int)maze.size(); y++)
	{
		for (int x = 0; x < (int)maze[y].length(); x++)
		{
			int sum = (x*x) + (3 * x) + (2 * x*y) + y + (y*y) + input;

			sum = sum - ((sum >> 1) & 0x55555555);
			sum = (sum & 0x33333333) + ((sum >> 2) & 0x33333333);
			int count = (((sum + (sum >> 4)) & 0x0F0F0F0F) * 0x01010101) >> 24;

			maze[y][x] = (count % 2) ? '#' : ' ';
		}
	}

	//print maze
	std::cout << "----------------------   Maze   ---------------------" << std::endl;
	std::cout << "   00000000001111111111222222222233333333334444444444" << std::endl;
	std::cout << "   01234567890123456789012345678901234567890123456789" << std::endl;
	for (size_t i = 0; i < maze.size(); i++)
	{
	if (i < 10) std::cout << "0";
	std::cout << i << " " << maze[i] << std::endl;
	}
	std::cout << std::endl;
}
*/