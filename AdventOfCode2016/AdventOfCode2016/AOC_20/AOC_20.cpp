#include "AOC_20.h"

AOC_20::AOC_20(std::string fileName) :
	ip(0)
{
	//open input file
	std::string input = readFile(fileName);
	if (input == "") return;

	std::vector<std::string> lines = splitString(input, '\n');
	for (int i = 0; i < (int)lines.size(); i++)
	{
		std::vector<std::string> ip = splitString(lines[i], '-');
		rules.emplace_back(std::strtoul(ip[0].c_str(), NULL, 0), std::strtoul(ip[1].c_str(), NULL, 0));
	}
	std::sort(rules.begin(), rules.end());

	long long address = 0;
	long long count = 0;
	for (size_t i = 0; i < rules.size(); i++)
	{
		//Search first free IP
		if (rules[i].first <= ip && rules[i].second >= ip)
			ip = rules[i].second + 1;

		//count open IPs
		if (address >= rules[i].first)
		{
			if (address <= rules[i].second)
				address = (long long)rules[i].second + 1;
		}
		else
		{
			count += rules[i].first - address;
			address = (long long)rules[i].second + 1;
		}
	}
	if (address <= 4294967295)
		count += (4294967295 - address) + 1;

	std::cout << "--- Challenge 20 A ---" << std::endl;
	std::cout << "The lowest-valued IP that is not blocked is [" << ip << "]." << std::endl;
	
	std::cout << "--- Challenge 20 B ---" << std::endl;
	std::cout << "There are [" << count << "] allowed IPs." << std::endl;
	std::cout << std::endl;
}