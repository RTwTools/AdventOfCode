#include "AOC_09.h"

AOC_09::AOC_09(std::string fileName)
{
	//open input file
	std::string input = readFile(fileName);
	if (input == "") return;

	//split string at '\n' 
	std::string str = splitString(input, '\n')[0];

	findMarkers(str);

	
	std::cout << "--- Challenge 09 A ---" << std::endl;
	std::cout << "The decompressed length is [" << fileContent.length() << "]." << std::endl;
	
	std::cout << "--- Challenge 09 B ---" << std::endl;
	//std::cout << " [" << solutionB << "]." << std::endl;
	std::cout << std::endl;
}

void AOC_09::findMarkers(std::string text)
{
	std::string str = text;
	int begin = str.find('(', 0);
	int end = str.find(')', 0);

	while (begin != -1 && end != -1)
	{
		//read next marker
		std::string marker = str.substr(begin + 1, end-1);
		int length =0 , times = 0;
		readMarker(marker, &length, &times);

		//add string before marker to text
		if (begin != 0)
			fileContent += str.substr(0, begin);

		//execute marker
		if ((end + 1 + length) > (int)str.substr(end + 1).length())
			fileContent += executeMarker(times, str.substr(end + 1));
		else
			fileContent += executeMarker(times, str.substr(end + 1, length));
		str = str.substr((end + 1) + length);

		//find new marker
		begin = str.find('(', 0);
		end = str.find(')', 0);
	}
	fileContent += str;
}

std::string AOC_09::executeMarker(int times, std::string markerStr)
{
	std::string str;
	for (int i = 0; i < times; i++)
	{
		str += markerStr;
	}
	return str;
}

void AOC_09::readMarker(std::string marker, int *length, int * times)
{
	int pos = marker.find('x');
	*length = std::stoi(marker.substr(0, pos));
	*times = std::stoi(marker.substr(pos + 1));
}