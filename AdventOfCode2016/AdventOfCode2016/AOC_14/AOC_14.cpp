#include "AOC_14.h"

AOC_14::AOC_14(std::string salt)
{
	std::cout << "--- Challenge 14 A ---" << std::endl;
	std::cout << "The 64th key is at index [" << findKeys(salt, false) << "]." << std::endl;
	
	std::cout << "--- Challenge 14 B ---" << std::endl;
	std::cout << "The 64th key is at index [" << findKeys(salt, true) << "]." << std::endl;
	std::cout << std::endl;
}

int AOC_14::findKeys(std::string salt, bool partB)
{
	keys.clear();
	queue.clear();
	count = 0;

	//wait for MAXKEYS and finish queue
	while (keys.size() < MAXKEYS || queue.size() > 0)
	{
		//get MD5 hash
		hash = md5(salt + std::to_string(count));
		if (partB)
		{
			for (int z = 0; z < 2016; z++)
				hash = md5(hash);
		}

		//only add new potential keys if found keys < MAXKEYS
		if (keys.size() < MAXKEYS)
		{
			//find triplet
			std::string checkStr = findTriplet(hash);
			if (checkStr != "")
			{
				Key key;
				key.checkStr = checkStr;
				key.hash = hash;
				key.index = count;
				queue.push_back(key);
			}
		}

		findPentad(count, hash);
		count++;
	}

	//sort keys
	std::sort(keys.begin(), keys.end(), Key::sortIndex);

	return keys[MAXKEYS - 1].index;
}

void AOC_14::findPentad(int count, std::string hash)
{
	for (size_t i = 0; i < queue.size(); i++)
	{
		if (count <= queue[i].index + 1000)
		{
			//skip own hash and find Pentad
			if (count != queue[i].index && hash.find(queue[i].checkStr) != -1)
			{
				addKey(queue[i]);
				queue.erase(queue.begin() + i);
				i--;
			}
		}
		else
		{
			//remove potential key from queue
			queue.erase(queue.begin() + i);
			i--;
		}
	}
}

void AOC_14::addKey(Key key)
{
	if (keys.size() < MAXKEYS)
		keys.push_back(key);
	else
	{
		for (size_t i = 0; i < keys.size(); i++)
		{
			if (keys[i].index > key.index)
				keys[i] = key;
		}
	}
}

std::string AOC_14::findTriplet(std::string str)
{
	for (size_t i = 0; i < str.length()-2; i++)
	{
		if (str[i] == str[i + 1] && str[i] == str[i + 2])
		{
			//return string 5*found Triplet Char
			std::string checkStr;
			for (size_t j = 0; j < 5; j++)
				checkStr += str[i];
			return checkStr;
		}
	}

	return "";
}