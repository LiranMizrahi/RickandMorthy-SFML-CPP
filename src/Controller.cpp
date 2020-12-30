#include "Controller.h"
#include <string>
#include <iostream>
Controller::Controller()
{
}

std::fstream Controller::openlevelfile(int level)
{
	std::string filename = "level";
		filename += std::to_string(level);
		std::fstream file;
		file.open(filename);
		if(file.bad())
			std::cout << "Error while open level file";
		return file;
}

