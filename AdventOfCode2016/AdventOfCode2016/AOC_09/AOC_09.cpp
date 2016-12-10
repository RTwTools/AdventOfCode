#include "AOC_09.h"

AOC_09::AOC_09(std::string fileName)
{
	//open input file
	std::string input = readFile(fileName);
	if (input == "") return;

	//split string at '\n' 
	std::string str = splitString(input, '\n')[0];
	
	std::cout << "--- Challenge 09 A ---" << std::endl;
	std::cout << "The decompressed length is [" << findMarkers(str, true) << "]." << std::endl;
	
	std::cout << "--- Challenge 09 B ---" << std::endl;
	std::cout << "The decompressed length is [" << findMarkers(str, false) << "]." << std::endl;
	std::cout << std::endl;
}

long long AOC_09::findMarkers(std::string text, bool partA)
{
	long long count = 0;
	std::string str = text;
	int begin = str.find('(', 0);
	int end = str.find(')', 0);

	while (begin != -1 && end != -1)
	{
		//add length before marker to the count
		if (begin != 0)
			count += str.substr(0, begin).length();

		//read marker
		std::string marker = str.substr(begin + 1, end - 1);
		int length = 0, times = 0;
		readMarker(marker, &length, &times);

		//check if marker length is bigger than the length of the string
		int maxLength = (int)str.substr(end + 1).length();
		if (length > maxLength) length = maxLength;

		//decompress
		if (partA)
			count += times * length;
		else
			count += times * findMarkers(str.substr(end + 1, length), partA);

		//decompress remaining part
		str = str.substr(end + 1 + length);
		begin = str.find('(', 0);
		end = str.find(')', 0);
	}

	//add remaining part without a marker to the count
	count += str.length();
	return count;
}

void AOC_09::readMarker(std::string marker, int *length, int * times)
{
	int pos = marker.find('x');
	*length = std::stoi(marker.substr(0, pos));
	*times = std::stoi(marker.substr(pos + 1));
}