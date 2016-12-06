#include "../Headers/Create13NrCode.h"

using namespace std;

Create13NrCode::Create13NrCode()
{
}

vector<int> Create13NrCode::create12NrCode(vector<char> str, char countryCode[3]) {
	int size;
	vector<int> NewSir;
	if (str.size() < 9) {
		size = 9 - str.size();
		for (int i = 0; i < size; i++) str.insert(str.begin(), '7');
	}
	for (int i = 2; i >= 0; i--) str.insert(str.begin(), countryCode[i]);							
	for (unsigned int i = 0; i < str.size(); i++) NewSir.push_back(str[i] - 48);				
	return NewSir;
}

vector<int> Create13NrCode::addControlNumber(vector<int> str) {
	int SumaImpar = 0, SumaPar = 0, CifraControl;

	for (unsigned int i = 0; i < str.size() - 1; i = i + 2) {
		SumaImpar = SumaImpar + str[i + 1];
		SumaPar = SumaPar + str[i];
	}
	CifraControl = (10 - (SumaImpar * 3 + SumaPar) % 10) % 10;							

	str.push_back(CifraControl);
	return str;
}

vector<int> Create13NrCode::get13NrCode(vector<char> str, char countryCode[3]) {

	vector<int> tempCode = create12NrCode(str, countryCode);
	return addControlNumber(tempCode);

}


Create13NrCode::~Create13NrCode()
{
}
