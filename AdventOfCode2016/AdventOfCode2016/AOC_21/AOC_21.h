#pragma once
#include "../general/InputHandler.h"

class AOC_21
{
public:
	AOC_21(std::string fileName);

private:
	//members
	std::vector<std::vector<std::string> > commands;

	//methods
	std::string scramble(std::string str);
	std::string unScramble(std::string str);

	void swap(std::string& str, int pos1, int pos2);
	void swap(std::string& str, char c1, char c2);
	void rotate(std::string& str, bool right, int steps);
	void rotate(std::string& str, bool right, char c);
	void rotateReverse(std::string& str, bool right, char c);
	void reverse(std::string& str, int pos1, int pos2);
	void move(std::string& str, int pos1, int pos2);
	
};

