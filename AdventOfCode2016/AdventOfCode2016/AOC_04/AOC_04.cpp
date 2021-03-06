#include "AOC_04.h"

AOC_04::AOC_04(std::string fileName) :
	sectorSum(0),
	northPoleSectorID(0)

{
	//open input file
	std::string input = readFile(fileName);
	if (input == "") return;

	//split string at '\n' 
	std::vector<std::string> lines = splitString(input, '\n');

	for (int i = 0; i < (int)lines.size(); i++)
	{
		//split string at '-' and remove whitespace at the front and the back
		std::vector<std::string> room = splitString(lines[i], '-');
		removeWhiteSpaces(room);
		int roomID = 0;

		//check if room is real
		if (checkRoom(room, &roomID))
			sectorSum += roomID;

		//decrypt room name
		int shift = roomID % 26;
		decodeRoomName(room, shift);

		//find north pole object
		if (room[0].find("north", 0) != -1)
			northPoleSectorID = roomID;
	}

	std::cout << "--- Challenge 04 A ---" << std::endl;
	std::cout << "The sum of the sector IDs of the real rooms is [" << sectorSum << "]." << std::endl;
	
	std::cout << "--- Challenge 04 B ---" << std::endl;
	std::cout << "North Pole Objects are stored in [" << northPoleSectorID << "]." << std::endl;
	std::cout << std::endl;
}

void AOC_04::decodeRoomName(std::vector<std::string> &room, int shift)
{
	for (size_t i = 0; i < room.size()-1; i++)
	{
		for (size_t j = 0; j < room[i].length(); j++)
		{
			char * chr = &(room[i][j]);
			shiftChar(chr, shift);
		}
		//std::cout << room[i] << "-";
	}
	//std::cout << std::endl;
}

void AOC_04::shiftChar(char * chr, int shift)
{
	for (int i = 0; i < shift; i++)
	{
		if (*chr == 'z')
			*chr = 'a';
		else
			(*chr)++;
	}
}

bool AOC_04::checkRoom(std::vector<std::string> room, int * roomSectorID)
{
	std::string checksum;
	*roomSectorID = getChecksumAndID(room[room.size() - 1], &checksum);
	
	//remove checksum and sectorID part
	room.pop_back();

	//count all characters
	countOccurences(room);

	//sort on occurence, then on alphabet
	std::sort(chrCount.begin(), chrCount.end(), CharCount::before);

	//check if checksum is correct / room is real
	if (compareChecksum(checksum))
		return true;
	
	return false;
}

bool AOC_04::compareChecksum(std::string checksum)
{
	for (size_t i = 0; i < checksum.length(); i++)
	{
		if (checksum[i] != chrCount[i].chr)
			return false;
	}
	return true;
}

int AOC_04::getChecksumAndID(std::string sectorIDChecksum, std::string * checksum)
{
	int begin = sectorIDChecksum.find('[', 0) +1;
	int end = sectorIDChecksum.find(']', 0);
	*checksum = sectorIDChecksum.substr(begin, (end-begin));

	int sectorID = atoi(sectorIDChecksum.substr(0, begin).c_str());
	return sectorID;
}

void AOC_04::countOccurences(std::vector<std::string> str)
{
	chrCount.clear();

	//count all the characters in the string
	for (size_t i = 0; i < str.size(); i++)
	{
		for (size_t j = 0; j < str[i].length(); j++)
		{
			addChar(str[i].c_str()[j]);
		}
	}
}

void AOC_04::addChar(char chr)
{
	for (size_t i = 0; i < chrCount.size(); i++)
	{
		if (chrCount[i].chr == chr)
		{
			//char exists
			chrCount[i].count++;
			return;
		}
	}

	//char is new
	CharCount newChar;
	newChar.chr = chr;
	newChar.count = 1;
	chrCount.push_back(newChar);
}
