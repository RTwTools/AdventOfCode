#include "AOC_07.h"

AOC_07::AOC_07(std::string fileName) :
	countA(0),
	countB(0)
{
	//open input file
	std::string input = readFile(fileName);
	if (input == "") return;

	//split string at '\n' 
	std::vector<std::string> lines = splitString(input, '\n');

	for (int i = 0; i < (int)lines.size(); i++)
	{
		splitIP(lines[i]);

		//check hyperparts
		if (!checkAbba(hyperParts) && checkAbba(ipParts))
			countA++;

		//find BAB
		if (findBAB())
		{
			//find ABA
			for (size_t i = 0; i < bab.size(); i++)
			{
				if (findABA(bab[i]))
				{
					countB++;
					break;
				}
			}
		}
	}

	std::cout << "--- Challenge 0x A ---" << std::endl;
	std::cout << "The Number of IPs that support TLS is [" << countA << "]." << std::endl;
	
	std::cout << "--- Challenge 0x B ---" << std::endl;
	std::cout << "The Number of IPs that support SSL is [" << countB << "]." << std::endl;
	std::cout << std::endl;
}

bool AOC_07::checkAbba(std::vector<std::string> vec)
{
	for (size_t i = 0; i < vec.size(); i++)
	{
		std::string str = vec[i];
		if (str.length() < 4)
			continue;

		for (size_t i = 0; i < str.length() - 3; i++)
		{
			if ((str[i] == str[i + 3]) && (str[i + 1] == str[i + 2]) && (str[i] != str[i + 1]))
				return true;
		}
	}
	return false;
}

bool AOC_07::findABA(std::string bab_str)
{
	std::string aba = { bab_str[1], bab_str[0], bab_str[1] };
	
	for (size_t i = 0; i < ipParts.size(); i++)
	{
		if (ipParts[i].find(aba) != -1)
			return true;
	}

	return false;
}

bool AOC_07::findBAB()
{
	bab.clear();
	for (size_t i = 0; i < hyperParts.size(); i++)
	{
		std::string str = hyperParts[i];
		if (str.length() < 3)
			continue;

		for (size_t i = 0; i < str.length() - 2; i++)
		{
			if ((str[i] == str[i + 2]))
				bab.push_back(str.substr(i, 3));
		}
	}

	if (bab.size() != 0)
		return true;

	return false;
}

void AOC_07::splitIP(std::string ip)
{
	ipParts.clear();
	hyperParts.clear();

	std::string ipAddress = ip;
	int begin = ipAddress.find('[', 0);
	int end = ipAddress.find(']', 0);

	while (begin != -1 && end != -1)
	{
		//save found ip parts
		if (begin != 0)
			ipParts.push_back(ipAddress.substr(0, begin));
		hyperParts.push_back(ipAddress.substr(begin + 1, end - (begin + 1)));

		//remove saved parts from original string
		if (end + 1 != ipAddress.length())
			ipAddress = ipAddress.substr(end + 1);
		else
		{
			ipAddress = "";
			break;
		}

		//locate square brackets
		begin = ipAddress.find('[', 0);
		end = ipAddress.find(']', 0);
	}
	ipParts.push_back(ipAddress);
}