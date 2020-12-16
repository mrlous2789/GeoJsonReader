#include "Reader.h"


Reader::Reader()
{
	
}

bool Reader::ReadFile(std::string filename)
{
	std::fstream file;
	file.open(filename);
	if (file)
	{
		std::cout << "File: " + filename + " opened" << std::endl;
		return true;
	}
	else
	{
		std::cout << "File: " + filename + " could not be opened" << std::endl;
	}

}
