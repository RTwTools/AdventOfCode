#pragma once
#include <vector>
#include <string>
#include "../general/Coordinate.h"

class PC
{
private:
	//members
	Coordinate coord_;
	int size_, used_, avail_, use_;
	
public:
	PC(Coordinate c, int size, int used, int avail, int use) :
		coord_(c), size_(size), used_(used), avail_(avail), use_(use) {}
	PC(std::string str)
	{
		std::vector<std::string> node = splitString(str, ' ');
		int indexX = node[0].find('-') + 2;
		int indexY = node[0].find('-', indexX);
		int x = std::stoi(node[0].substr(indexX, indexY - indexX));
		int y = std::stoi(node[0].substr(indexY + 2));
		coord_ = Coordinate{ x, y };
		size_ = std::stoi(node[1].substr(0, node[1].length() - 1));
		used_ = std::stoi(node[2].substr(0, node[2].length() - 1));
		avail_ = std::stoi(node[3].substr(0, node[3].length() - 1));
		use_ = std::stoi(node[4].substr(0, node[4].length() - 1));
	}
	int getSize() { return size_; }
	int getUsed() { return used_; }
	int getAvail() { return avail_; }
	int getUse() { return use_; }
};