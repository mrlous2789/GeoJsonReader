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
	//reader.PrintData();
	bool running = true;
	std::string input;
	while (running)
	{
		std::cout << "Enter Id: " << std::endl;
		std::cin >> input;
		if (input == "")
		{
			std::cout << "No input" << std::endl;
		} 
		else if (input == "close")
		{
			running = false;
		}
		else
		{
			try
			{
				int tmp = std::stoi(input);
				reader.PrintDataByID(tmp);
			}
			catch (const std::exception&)
			{
				std::cout << "Enter number could not convert" << std::endl;
			} 
		}
	}

	return 0;
}