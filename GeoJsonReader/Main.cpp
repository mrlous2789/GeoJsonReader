#include "Reader.h"

int main()
{
	std::string filename = "testFile.geojson";
	std::cout << "Starting" << std::endl;
	std::cout << "Enter Filename:" << std::endl;
	std::getline(std::cin, filename);
	if (filename == "")
	{
		filename = "testFile.geojson";
	}
	Reader reader;
	reader.ReadFile(filename);
	reader.PrintData();
	return 0;
}