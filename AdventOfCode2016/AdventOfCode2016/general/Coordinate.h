#pragma once
struct Coordinate
{
	int x;
	int y;
	bool operator==(const Coordinate& i) const
	{
		return (x == i.x && y == i.y);
	}

	Coordinate& operator=(const Coordinate& i)
	{
		x = i.x;
		y = i.y;
		return *this;
	}

	Coordinate operator+(const Coordinate& i) const
	{
		return Coordinate{ i.x + x, i.y + y};
	}
};