#pragma once
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <cstdlib>

class FileRead
{
public:
	FileRead();
	~FileRead();

	std::vector<std::string> readFromFile(std::string);
};

