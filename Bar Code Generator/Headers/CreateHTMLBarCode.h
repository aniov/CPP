#pragma once

#include <fstream>
#include <vector>
#include <string>
#include <iostream>
//#include <windows.h>
#include "TransformToBinary.h"

class CreateHTMLBarCode
{
public:
	CreateHTMLBarCode();
	~CreateHTMLBarCode();
	void GraficCodeBar(std::vector<std::string>, std::vector<std::string>, std::vector<int>, std::string);
	void openBrowser();
private:
	std::string fileName;
	void createFile(std::string, std::ofstream*);
	TransformToBinary transformToBinary;
};

