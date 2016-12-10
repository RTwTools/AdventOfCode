#pragma once
#include "../general/InputHandler.h"

class AOC_09
{
public:
	AOC_09(std::string fileName);

private:
	//members

	//methods
	long long findMarkers(std::string text, bool partA);
	void readMarker(std::string marker, int * length, int * times);
};

