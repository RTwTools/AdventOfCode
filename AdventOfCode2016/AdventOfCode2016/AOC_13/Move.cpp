#pragma once
#include "Move.h"

Move::Move(Coordinate c, std::vector<Coordinate> path, int moves, int favNr) :
	curCoord(c), visited(path), steps(moves), favNumber(favNr) {}


void Move::generateChildren()
{
	if (curCoord.x - 1 >= 0)
	{
		Coordinate left = curCoord;
		left.x--;
		checkNewMove(left);
	}
	if (curCoord.y - 1 >= 0)
	{
		Coordinate up = curCoord;
		up.y--;
		checkNewMove(up);
	}

	Coordinate right = curCoord;
	right.x++;
	checkNewMove(right);

	Coordinate down = curCoord;
	down.y++;
	checkNewMove(down);
}

void Move::checkNewMove(Coordinate coord)
{
	if (getLocationInfo(coord) == OPEN_SPACE && !isVisited(coord))
	{
		std::vector<Coordinate> newVisited = visited;
		newVisited.push_back(curCoord);
		children.push_back(Move(coord, newVisited, steps + 1, favNumber));
	}
}

std::vector<Move> Move::getChildren()
{
	generateChildren();
	return children;
}

int Move::numberOfBits(int i)
{
	i = i - ((i >> 1) & 0x55555555);
	i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
	return (((i + (i >> 4)) & 0x0F0F0F0F) * 0x01010101) >> 24;
}

char Move::getLocationInfo(Coordinate coord)
{
	int sum = (coord.x*coord.x) + (3 * coord.x) + (2 * coord.x*coord.y) + coord.y + (coord.y*coord.y) + favNumber;
	int count = numberOfBits(sum);
	return (count % 2) ? WALL : OPEN_SPACE;
}

bool Move::isVisited(Coordinate coord)
{
	for (size_t i = 0; i < visited.size(); i++)
	{
		if (coord == visited[i])
			return true;
	}
	return false;
}