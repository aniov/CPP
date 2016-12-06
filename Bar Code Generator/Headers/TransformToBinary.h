#pragma once

#include <vector>
#include <iostream>

class TransformToBinary
{
public:
	TransformToBinary();
	~TransformToBinary();
	std::vector<int> transformToBinaryCode(std::vector<std::string>, std::vector<std::string>, std::vector<int>);
};

