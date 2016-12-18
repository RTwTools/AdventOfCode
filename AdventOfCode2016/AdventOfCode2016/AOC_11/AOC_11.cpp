#include "AOC_11.h"

AOC_11::AOC_11()
{
	//test
	std::vector<Floor> floors(4);
	setFloorsTest(floors);
	Node root(0, floors, 0, up);

	std::cout << "--- Challenge 11 TEST ---" << std::endl;
	std::cout << "The minimum number of steps is [" << breadthFirstSearch(root) << "]." << std::endl;

	//part 1
	floors = std::vector<Floor>(4);
	setFloorsP1(floors);
	root = Node(0, floors, 0, up);

	std::cout << "--- Challenge 11 A ---" << std::endl;
	std::cout << "The minimum number of steps is [" << breadthFirstSearch(root) << "]." << std::endl;

	//part 2
	floors = std::vector<Floor>(4);
	setFloorsP2(floors);
	root = Node(0, floors, 0, up);
	
	std::cout << "--- Challenge 11 B ---" << std::endl;
	std::cout << "The minimum number of steps is [" << breadthFirstSearch(root) << "]." << std::endl;
	std::cout << std::endl;
}

void AOC_11::setFloorsP1(std::vector<Floor> &floors)
{
	//floor 1
	floors[0].addItem(Item("thulium", generator));
	floors[0].addItem(Item("thulium", microChip));
	floors[0].addItem(Item("plutonium", generator));
	floors[0].addItem(Item("strontium", generator));

	//floor 2
	floors[1].addItem(Item("plutonium", microChip));
	floors[1].addItem(Item("strontium", microChip));

	//floor 3
	floors[2].addItem(Item("promethium", generator));
	floors[2].addItem(Item("promethium", microChip));
	floors[2].addItem(Item("ruthenium", generator));
	floors[2].addItem(Item("ruthenium", microChip));
}

void AOC_11::setFloorsP2(std::vector<Floor> &floors)
{
	setFloorsP1(floors);

	//floor 1
	floors[0].addItem(Item("elerium", generator));
	floors[0].addItem(Item("elerium", microChip));
	floors[0].addItem(Item("dilithium", generator));
	floors[0].addItem(Item("dilithium", microChip));
}

void AOC_11::setFloorsTest(std::vector<Floor>& floors)
{
	//floor 1
	floors[0].addItem(Item("hydrogen", microChip));
	floors[0].addItem(Item("lithium", microChip));

	//floor 2
	floors[1].addItem(Item("hydrogen", generator));

	//floor 3
	floors[2].addItem(Item("lithium", generator));
}

int AOC_11::breadthFirstSearch(Node root)
{
	std::queue<Node> q;
	std::vector<Node> children;

	q.push(root);
	int level = 0;
	while (!q.empty())
	{
		Node n = q.front();

		if (n.getNrOfSteps() > level)
		{
			level++;
			std::cout << "level " << level << " options: " << q.size() << std::endl;
		}
		q.pop();
		
		//check goal state
		if (n.isGoal())
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
