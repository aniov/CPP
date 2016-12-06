#pragma once
#include <vector>

class Create13NrCode
{
public:
	Create13NrCode();
	~Create13NrCode();
	std::vector<int> get13NrCode(std::vector<char>, char countryCode[3]);
private:
	std::vector<int> create12NrCode(std::vector<char> str, char countryCode[3]);
	std::vector<int> addControlNumber(std::vector<int> str);
};

