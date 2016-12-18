#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Item.h"

class Floor
{
public:
	//members
	std::vector<Item> items;

	//methods
	Floor() {}
	int getNrOfItems() { return (int)items.size(); }
	void addItem(Item item) { items.push_back(item); }
	bool isValid();

private:
	//methods
	bool Floor::hasGenerator(std::string material);
	bool Floor::hasGenerator();
	bool Floor::hasMicroChip(std::string material);
	bool Floor::hasMicroChip();
};