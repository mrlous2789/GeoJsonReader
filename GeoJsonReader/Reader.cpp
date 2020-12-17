#include "Reader.h"


Reader::Reader()
{
	
}

bool Reader::ReadFile(std::string filename)
{
	std::fstream file;
	file.open(filename);

	if (file)//if file is open read file
	{
		std::string line;
		std::cout << "File: " + filename + " opened" << std::endl;
		int id = 0, height = 0, biome = 0, population = 0, state = 0, province = 0, culture = 0, religion = 0;
		
		std::string type;
		std::vector<int> neighbors;

		std::vector<std::pair<double, double>> coords;
		
		int linenum = 0;
		
		while (std::getline(file, line))
		{			
			//linenum++;
			//std::cout << linenum << std::endl;
			//std::cout << line << std::endl;
			if (line.find("\"geometry\":") != std::string::npos)
			{
				int start = line.find_first_of('[');
				std::string coord = "";
				double x = 0.0f, y = 0.0f;
				bool xcoord = true;
				for (int i = start; i < line.size(); i++)
				{
					if (line.at(i) == '[' || line.at(i) == ']')
					{

					}
					else if (line.at(i) == ',')
					{
						if (xcoord)
						{
							x = ConvertToDouble(coord);
							xcoord = false;
							coord = "";
						}
						else
						{
							y = ConvertToDouble(coord);
							coords.push_back({ x,y });
							xcoord = true;
							coord = "";
						}
					}
					else
					{
						coord += line.at(i);
					}
				}
			}
			else if (line.find("\"id\":") != std::string::npos) { id = ConvertToInt(GetProperty(line)); }
			else if (line.find("\"height\":") != std::string::npos) { height = ConvertToInt(GetProperty(line)); }
			else if (line.find("\"biome\":") != std::string::npos) { biome = ConvertToInt(GetProperty(line)); }
			else if (line.find("\"type\":") != std::string::npos) { type = GetProperty(line); }
			else if (line.find("\"population\":") != std::string::npos) { population = ConvertToInt(GetProperty(line)); }
			else if (line.find("\"state\":") != std::string::npos) { state = ConvertToInt(GetProperty(line)); }
			else if (line.find("\"province\":") != std::string::npos) { province = ConvertToInt(GetProperty(line)); }
			else if (line.find("\"culture\":") != std::string::npos) { culture = ConvertToInt(GetProperty(line)); }
			else if (line.find("\"religion\":") != std::string::npos) { religion = ConvertToInt(GetProperty(line)); }
			else if (line.find("\"neighbors\":") != std::string::npos)
			{
				int start = line.find_first_of('[');
				for (int i = start; i < line.size(); i++)
				{
					std::string neighbor = "";
					if (line.at(i) == ',')
					{
						neighbors.push_back(ConvertToInt(neighbor));
						neighbor = "";
					}
					else if (line.at(i) == ']' || line.at(i) == '[')
					{

					}
					else
					{
						neighbor += line.at(i);
					}
				}
			}
			else if (line == "},")
			{
				std::cout << "Im here" << std::endl;
				cells.push_back(Cell(coords, id, height, biome, type, population, state, province, culture, religion, neighbors));
			}
			//Cell cell = Cell(coords, id, height, biome, type, population, state, province, culture, religion, neighbors);

		}
		std::cout << "Done" << std::endl;
		

		return true;
	}
	else//return error
	{
		std::cout << "File: " + filename + " could not be opened" << std::endl;
		return false;
	}

}

std::pair<int, int> Reader::FindFirstAndLast(std::string line)
{
	int last = line.find_last_of("\"");
	int first = 0;

	for (int i = (last - 1); i > 0; i--)
	{
		if (line.at(i) == '\"')
		{
			first = i + 1;
			break;
		}
	}
	return std::pair<int, int>(first, last);
}

std::string Reader::GetProperty(std::string line)
{
	std::pair<int, int> firstLast = FindFirstAndLast(line);
	std::string propertyString = line.substr(firstLast.first, firstLast.second - firstLast.first);
	return propertyString;
}

int Reader::ConvertToInt(std::string line)
{
	try
	{
		int prop = std::stoi(line);
		return prop;
	}
	catch (const std::exception&)
	{
		std::cout << "Error converting: " << line << std::endl;
		return 0;
	}
}
double Reader::ConvertToDouble(std::string line)
{
	try
	{
		double prop = std::stof(line);
		return prop;
	}
	catch (const std::exception&)
	{
		std::cout << "Error converting: " << line << std::endl;
		return 0.0f;
	}
}
void Reader::PrintData()
{
	std::cout << "Cell count: " <<cells.size() << std::endl;
	cells[5].PrintProperties();
	cells[19].PrintProperties();
	cells[456].PrintProperties();
}
