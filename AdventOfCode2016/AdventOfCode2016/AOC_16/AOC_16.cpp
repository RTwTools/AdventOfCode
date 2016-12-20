#include "AOC_16.h"

AOC_16::AOC_16(std::string input)
{
	data = generateData(input, DISK_SIZE_A);

	std::cout << "--- Challenge 16 A ---" << std::endl;
	std::cout << "The correct checksum is [" << generateChecksum(data) << "]." << std::endl;

	data = generateData(input, DISK_SIZE_B);
	
	std::cout << "--- Challenge 16 B ---" << std::endl;
	std::cout << "The correct checksum is [" << generateChecksum(data) << "]." << std::endl;
	std::cout << std::endl;
}

std::string AOC_16::generateData(std::string initialData, int length)
{
	std::string data = initialData;
	while ((int)data.length() < length)
	{
		std::string reverse = std::string(data.rbegin(), data.rend());
		std::replace(reverse.begin(), reverse.end(), '1', '2');
		std::replace(reverse.begin(), reverse.end(), '0', '1');
		std::replace(reverse.begin(), reverse.end(), '2', '0');
		data += "0" + reverse;
	}
	return data.substr(0, length);
}

std::string AOC_16::generateChecksum(std::string data)
{
	std::string procesData;
	std::string checksum = data;

	while (!(checksum.length() % 2))
	{
		procesData = checksum;
		checksum.clear();

		for (size_t i = 0; i < procesData.length(); i = i + 2)
		{
			if (procesData[i] == procesData[i + 1])
				checksum += "1";
			else
				checksum += "0";
		}
	}
	
	return checksum;
}