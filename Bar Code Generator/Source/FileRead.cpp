#include "../Headers/FileRead.h"

using namespace std;

FileRead::FileRead()
{
}

vector<string> FileRead::readFromFile(string fileName) {

	const int Max = 50;
	vector<string> ean13;
	string str[Max];
	ifstream file;
	file.exceptions(ifstream::failbit | ifstream::badbit);

	try {
		file.open(fileName);
		int i = 0;
		while (!file.eof()) {
				file >> str[i];
				ean13.push_back(str[i]);
				i++;
			}
	}
	catch (ifstream::failure e) {
		cout << "Error reading from the data base !!!\nThe program will exit now\n";
		cin.get(); cin.get();
		exit(0);
	}
	file.close();
	return ean13;
}


FileRead::~FileRead()
{
}
