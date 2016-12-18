#pragma once
#include "Floor.h"

bool Floor::hasGenerator(std::string material)
{
	for (size_t i = 0; i < items.size(); i++)
	{
		if (items[i].getType() == generator && items[i].getMaterial() == material)
			return true;
	}
	return false;
}

bool Floor::hasGenerator()
{
	for (size_t i = 0; i < items.size(); i++)
	{
		if (items[i].getType() == generator)
			return true;
	}
	return false;
}

bool Floor::hasMicroChip(std::string material)
{
	for (size_t i = 0; i < items.size(); i++)
	{
		if (items[i].getType() == microChip && items[i].getMaterial() == material)
			return true;
	}
	return false;
}

bool Floor::hasMicroChip()
{
	for (size_t i = 0; i < items.size(); i++)
	{
		if (items[i].getType() == microChip)
			return true;
	}
	return false;
}

bool Floor::isValid()
{
	if (!hasGenerator())
		return true;
	for (size_t i = 0; i < items.size(); i++)
	{
		if (items[i].getType() == microChip)
		{
			if (!hasGenerator(items[i].getMaterial()))
				return false;
		}
	}
	return true;
}