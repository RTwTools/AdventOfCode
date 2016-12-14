#pragma once
#include <string>

struct Key
{
	int index;
	std::string hash;
	std::string checkStr;
	static bool sortIndex(const Key& i, const Key& j)
	{
		return (i.index < j.index);
	}
};