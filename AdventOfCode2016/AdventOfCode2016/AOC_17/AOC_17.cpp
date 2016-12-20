#include "AOC_17.h"

AOC_17::AOC_17(std::string input)
{
	Coordinate start{ 0, 0 };
	Coordinate goal{ 3, 3 };

	Route root(start, "", input);

	std::cout << "--- Challenge 17 A ---" << std::endl;
	std::cout << "The shortest path is [" << breadthFirstSearch(root, goal, false) << "]." << std::endl;

	std::cout << "--- Challenge 17 B ---" << std::endl;
	std::cout << "The longest path is [" << breadthFirstSearch(root, goal, true).length() << "]." << std::endl;
	std::cout << std::endl;
}

std::string AOC_17::breadthFirstSearch(Route root, Coordinate goal, bool partB)
{
	std::queue<Route> q;
	std::vector<Route> children;
	std::string longestPath;

	q.push(root);
	int level = 0;
	while (!q.empty())
	{
		Route n = q.front();
		if (n.getNrOfSteps() > level)
			level++;

		q.pop();

		//check goal state
		if (n.getCoordinate() == goal)
		{
			if (!partB)
				return n.getPath();
			else
			{
				longestPath = n.getPath();
				continue;
			}
		}

		children = n.getChildren();
		for (size_t i = 0; i < children.size(); i++)
		{
			q.push(children[i]);
		}
	}

	if (!partB)
	{
		std::cout << "Goal not found!" << std::endl;
		return "";
	}
	else
		return longestPath;	
}