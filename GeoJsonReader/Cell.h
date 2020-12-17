#pragma once
#include <iostream>
#include <vector>

class Cell
{	
public:
	Cell();
	Cell(std::vector<std::pair<double, double>> inCoords, int inId, int inHeight, int inBiome, std::string inType, int inPopulation, int inState, int inProvince, int inCulture, int inReligion, std::vector<int> inNeighbors);
	void PrintProperties();

	std::vector<std::pair<double, double>> coords;
	int id;
	int height;
	int biome;
	std::string type;
	int population;
	int state;
	int province;
	int culture;
	int religion;
	std::vector<int> neighbors;
private:

};

