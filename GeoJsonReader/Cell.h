#pragma once
#include <iostream>
#include <vector>

class Cell
{	
public:
	Cell();
	Cell(std::vector<std::pair<double, double>> inCoords, int inId, int inHeight, int inBiome, std::string inType, int inPopulation, int inState, int inProvince, int inCulture, int inReligion, std::vector<int> inNeighbors);
	void PrintProperties();

	std::vector<std::pair<double, double>> coords;//coords of the cells vertices
	int id;//cell id
	int height;//hieght of cell
	int biome;//biome id
	std::string type;//type of cells e.g. ocean or land
	int population;//cells population
	int state;//cell nation state id 
	int province;//cell province
	int culture;//cell culture
	int religion;//cell religion
	std::vector<int> neighbors;//neighboring cell ids
private:

};

