#pragma once

#include <sstream>
#include <fstream>
#include <string>
#include "Cell.h"

class Reader
{
public:
	Reader();

	bool ReadFile(std::string filename);

	void PrintData();
private:
	bool reading = true;

	std::pair<int, int>FindFirstAndLast(std::string line);
	std::string GetProperty(std::string line);
	int ConvertToInt(std::string property);
	double ConvertToDouble(std::string property);

	std::vector<Cell> cells;
};

