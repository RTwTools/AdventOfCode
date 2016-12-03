#pragma once
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

const std::string readFile(const std::string fileName);
const std::vector<std::string> splitString(const std::string &str, char delim);
const void split(const std::string &s, char delim, std::vector<std::string> &elems);
const void removeWhiteSpaces(std::vector<std::string> &elems);