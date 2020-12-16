#pragma once
#include <iostream>
#include <vector>

class Cell
{	
public:
	Cell();
	Cell(std::vector<float[2]> inCoords, int inId, int inHeight, int inBiome, std::string inType, int inPopulation, int inState, int inProvince, int inCulture, int inReligion, std::vector<int> inNeighbors);
	std::vector<float[2]> coords;
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

