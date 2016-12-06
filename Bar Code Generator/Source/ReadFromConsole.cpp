#include "../Headers/stdafx.h"
#include "../Headers/ReadFromConsole.h"

using namespace std;


	vector<char> ReadFromConsole::getInputArrayCode() {
		return readCodeNumber();
	}
	string ReadFromConsole::getProductName() {
		return readProductName();
	}


	ReadFromConsole::ReadFromConsole()
	{
	}

	vector<char> ReadFromConsole::readCodeNumber() {

		vector<char> v_str;
		string str;
		char repeat;
		bool valid = false;

		do {
			cout << "\tEnter product code (made of max 9 digits, if it's less, it will be autocoplete): \n\t";
			cin >> str;
			for (unsigned int i = 0; i < str.size(); i++)
				if (!isdigit(str[i]) || str.size() > 9) {
					cout << "\tcode must have max. 9 digits (no characters)\n\tYou've entered -> " 
						<< str.size() << " digits"<< "\n\tRetry? Yes(y) / No(n) : ";
					cin >> repeat;
					if (toupper(repeat) == 'Y')
						break;
					else
						return vector<char>();
				}
				else valid = true;
									
		} while (!valid);

		for (unsigned int i = 0; i < str.size(); i++)
			v_str.push_back(str[i]);

		return v_str;
	}

	string ReadFromConsole::readProductName() {
		string name;
		cout << "\tEnter title for product: ";
		getline(cin, name);									
		return name;
	}



	ReadFromConsole::~ReadFromConsole()
	{
	}

