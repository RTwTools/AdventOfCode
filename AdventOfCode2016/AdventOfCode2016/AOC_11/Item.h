#pragma once
#include <string>

enum ItemType
{
	microChip,
	generator
};

class Item
{
public:
	Item(std::string mat, ItemType iType) : material(mat), type(iType) {}
	ItemType getType() { return type; }
	std::string getMaterial() { return material; }

private:
	ItemType type;
	std::string material;
};