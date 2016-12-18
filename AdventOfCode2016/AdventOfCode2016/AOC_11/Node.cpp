#pragma once
#include "Node.h"

Node::Node(int floor, std::vector<Floor> flrs, int stps, dir d)
{
	currentFloor = floor;
	floors = flrs;
	steps = stps;
	direction = d;
}

void Node::generateChildren()
{
	if (currentFloor + 1 <= HIGHEST_FLOOR)
	{
		if (moveTwoItemsUp() == NOT_POSSIBLE)
			moveOneItemUp();
	}
	if (currentFloor - 1 >= LOWEST_FLOOR)
	{
		if (moveOneItemDown() == NOT_POSSIBLE)
			moveTwoItemsDown();
	}
}

int Node::moveOneItemUp()
{
	std::vector<Floor> newFloors;
	int count = 0;
	for (int i = 0; i < floors[currentFloor].getNrOfItems(); i++)
	{
		newFloors = floors;

		//add items to new floor
		newFloors[currentFloor + 1].addItem(newFloors[currentFloor].items[i]);

		//remove items from current floor
		newFloors[currentFloor].items.erase(newFloors[currentFloor].items.begin() + i);

		//check new situation
		Node child(currentFloor + 1, newFloors, steps + 1, up);
		if (child.checkState())
		{
			children.push_back(child);
			count++;
		}
	}

	return count;
}

int Node::moveOneItemDown()
{
	std::vector<Floor> newFloors;
	int count = 0;
	for (int i = 0; i < floors[currentFloor].getNrOfItems(); i++)
	{
		//move 1 item down
		if (currentFloor - 1 >= 0)
		{
			newFloors = floors;

			//add items to new floor
			newFloors[currentFloor - 1].addItem(newFloors[currentFloor].items[i]);

			//remove items from current floor
			newFloors[currentFloor].items.erase(newFloors[currentFloor].items.begin() + i);

			//check new situation
			Node child(currentFloor - 1, newFloors, steps + 1, down);
			if (child.checkState())
			{
				children.push_back(child);
				count++;
			}
		}
	}
	return count;
}

int Node::moveTwoItemsUp()
{
	if (floors[currentFloor].getNrOfItems() < 2)
		return 0;

	std::vector<Floor> newFloors;
	int count = 0;
	bool pair = false;

	for (int i = 0; i < floors[currentFloor].getNrOfItems() - 1; i++)
	{
		for (int j = 1; j < floors[currentFloor].getNrOfItems(); j++)
		{
			if (j > i)
			{
				newFloors = floors;

				//Assumption: there is only ONE PAIR of each of the materials
				if (newFloors[currentFloor].items[i].getMaterial() == newFloors[currentFloor].items[j].getMaterial())
				{
					if (pair)
						continue;
					pair = true;
				}

				//add items to new floor
				newFloors[currentFloor + 1].addItem(newFloors[currentFloor].items[i]);
				newFloors[currentFloor + 1].addItem(newFloors[currentFloor].items[j]);

				//remove items from current floor
				newFloors[currentFloor].items.erase(newFloors[currentFloor].items.begin() + j);
				newFloors[currentFloor].items.erase(newFloors[currentFloor].items.begin() + i);

				//check new situation
				Node child(currentFloor + 1, newFloors, steps + 1, up);
				if (child.checkState())
				{
					children.push_back(child);
					count++;
				}
			}
		}
	}
	return count;
}

int Node::moveTwoItemsDown()
{
	if (floors[currentFloor].getNrOfItems() < 2)
		return 0;

	//don't move anything down to floor 1 and 2 if they are empty
	if (floors[currentFloor - 1].getNrOfItems() == 0 && currentFloor -1 < 2)
		return 0;

	std::vector<Floor> newFloors;
	int count = 0;
	bool pair = false;

	for (int i = 0; i < floors[currentFloor].getNrOfItems() - 1; i++)
	{
		for (int j = 1; j < floors[currentFloor].getNrOfItems(); j++)
		{
			if (j > i)
			{
				newFloors = floors;

				//Assumption: there is only ONE PAIR of each of the materials
				if (newFloors[currentFloor].items[i].getMaterial() == newFloors[currentFloor].items[j].getMaterial())
				{
					if (pair)
						break;
					pair = true;
				}

				//add items to new floor
				newFloors[currentFloor - 1].addItem(newFloors[currentFloor].items[i]);
				newFloors[currentFloor - 1].addItem(newFloors[currentFloor].items[j]);

				//remove items from current floor
				newFloors[currentFloor].items.erase(newFloors[currentFloor].items.begin() + j);
				newFloors[currentFloor].items.erase(newFloors[currentFloor].items.begin() + i);

				//check new situation
				Node child(currentFloor - 1, newFloors, steps + 1, down);
				if (child.checkState())
				{
					children.push_back(child);
					count++;
				}
			}
		}
	}
	return count;
}

bool Node::checkState()
{
	int checkfloors = (direction == up) ? currentFloor - 1 : currentFloor;
	for (size_t i = 0; i < 2; i++)
	{
		if (!floors[checkfloors + i].isValid())
			return false;
	}
	return true;
}

std::vector<Node> Node::getChildren()
{
	generateChildren();
	return children;
}

bool Node::isGoal()
{
	if (floors[0].getNrOfItems() == 0 && floors[1].getNrOfItems() == 0 && floors[2].getNrOfItems() == 0)
		return true;

	return false;
}