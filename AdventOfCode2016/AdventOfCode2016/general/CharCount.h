#pragma once
struct CharCount
{
	int count;
	char chr;
	static bool before(const CharCount& i, const CharCount& j)
	{
		if (i.count != j.count)
			return (i.count > j.count);
		else
			return (i.chr < j.chr);
	}
};