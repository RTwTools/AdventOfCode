#pragma once
#include "../general/InputHandler.h"

class AOC_09
{
public:
	AOC_09(std::string fileName);

	void findMarkers(std::string text);

	std::string executeMarker(int times, std::string markerStr);

	void readMarker(std::string marker, int * length, int * times);

private:
	//members
	std::string fileContent;
	//methods
};

