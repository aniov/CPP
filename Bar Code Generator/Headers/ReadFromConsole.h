#pragma once
#include <vector>
#include <iostream>
#include <fstream>
#include <string>

class ReadFromConsole
{
public:
	ReadFromConsole();
	~ReadFromConsole();
	std::vector<char> getInputArrayCode();
	std::string getProductName();
private:
	/*
	* Reads the code number made of max 9 digits
	* If the code is less, the code number will be auto complete
	*/
	std::vector<char> readCodeNumber();
	/*
	* Reads the title of the product
	*/
	std::string readProductName();
};

