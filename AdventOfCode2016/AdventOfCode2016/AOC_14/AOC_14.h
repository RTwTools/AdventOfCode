#pragma once
#include "../general/InputHandler.h"
#include "../general/md5.h"
#include <algorithm>
#include "Key.h"


#define MAXKEYS 64

class AOC_14
{
public:
	AOC_14(std::string salt);

private:
	//members
	int count;
	std::string hash;
	std::vector<Key> queue, keys;

	//methods
	int findKeys(std::string salt, bool partB);
	std::string findTriplet(std::string str);
	void findPentad(int count, std::string hash);
	void addKey(Key key);
};

