#pragma once
#include "Route.h"

Route::Route(Coordinate c, std::string path, std::string passCode) :
	curCoord(c), route(path), code(passCode) {}

void Route::generateChildren()
{
	std::string hash = md5(code + route).substr(0, 4);
	std::vector<bool> doors = checkDoors(hash);

	for (size_t i = 0; i < doors.size(); i++)
	{
		if (doors[i])
		{
			Coordinate coord = curCoord + pathCoord[i];
			children.push_back(Route(coord, (route + pathChar[i]), code));
		}
	}
}

std::vector<bool> Route::checkDoors(std::string str)
{
	std::vector<bool> doors;
	for (size_t i = 0; i < str.length(); i++)
	{
		if (str[i] >= 'b' && str[i] <= 'f')
			doors.push_back(true);
		else
			doors.push_back(false);
	}
	if (curCoord.x == 0)
		doors[LEFT] = false;
	if (curCoord.x == 3)
		doors[RIGHT] = false;
	if (curCoord.y == 0)
		doors[UP] = false;
	if (curCoord.y == 3)
		doors[DOWN] = false;
	return doors;	
}

std::vector<Route> Route::getChildren()
{
	generateChildren();
	return children;
}