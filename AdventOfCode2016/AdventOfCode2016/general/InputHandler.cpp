#include "InputHandler.h"

const std::string readFile(const std::string filename)
{
	std::ifstream inputStream(filename);

	if (!inputStream.is_open())
	{
		std::cout << "Couldn't open [" << filename << "]." << std::endl;
		system("pause");
		return "";
	}

	std::stringstream ss;
	ss << inputStream.rdbuf();
	inputStream.close();

	return ss.str();
}

const std::vector<std::string> splitString(const std::string &str, char delim)
{
	std::vector<std::string> elements;
	split(str, delim, elements);
	return elements;
}

const void split(const std::string &s, char delim, std::vector<std::string> &elems)
{
	std::stringstream ss;
	ss.str(s);
	std::string item;
	while (std::getline(ss, item, delim))
	{
		if (item.size() > 0)
		elems.push_back(item);
	}
}

const void removeWhiteSpaces(std::vector<std::string> &elems)
{
	for (int i = 0; i < (int)elems.size(); i++)
	{
		//remove whitespace at the front
		while (elems[i].substr(0, 1) == " ")
			elems[i] = elems[i].substr(1);

		//remove whitespace at the back
		while (elems[i].substr(elems[i].length() - 1, 1) == " ")
			elems[i] = elems[i].substr(0, elems[i].length() - 1);
	}
}