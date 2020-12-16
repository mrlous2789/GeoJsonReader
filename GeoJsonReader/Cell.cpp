#include "Cell.h"

Cell::Cell()
{
	
}
Cell::Cell(std::vector<float[2]> inCoords, int inId, int inHeight, int inBiome, std::string inType, int inPopulation, int inState, int inProvince, int inCulture, int inReligion, std::vector<int> inNeighbors)
{
	coords = inCoords;
	id = inId;
	height = inHeight;
	biome = inBiome;
	type = inType;
	population = inPopulation;
	state = inState;
	province = inProvince;
	culture = inCulture;
	religion = inReligion;
	neighbors = inNeighbors;
}