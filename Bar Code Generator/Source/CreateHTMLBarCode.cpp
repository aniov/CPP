#include "../Headers/CreateHTMLBarCode.h"

using namespace std;

CreateHTMLBarCode::CreateHTMLBarCode()
{
}

ofstream CreateHTMLBarCode::createFile(string productName) {

	ofstream file;
	file.exceptions(ofstream::failbit | ofstream::badbit);

	try {
		file.open(productName + ".html");
		return file;
	}
	catch (const ofstream::failure e){

		cout << "File with name: " + productName + "cannot be created\nThe program will exit now";
		cin.get(); cin.get();
		exit(0);
	}

}

void CreateHTMLBarCode::GraficCodeBar(vector<string> FisStruct, vector<string> FisEndingP, vector<int> code13, string productName) {

	vector <int> binaryCode = transformToBinary.transformToBinaryCode(FisStruct, FisEndingP, code13);

	int Y1 = 40, X1 = 20, Y2, pas = 2;
	int Xt = X1 - 10, Yt = Y1 + 54, Xp = X1 - 5, Yp = Y1 - 15;
	ofstream file = createFile(productName);
	
	file << "<!DOCTYPE html>" << endl;
	file << "<html>" << endl;
	file << "<body>" << endl;
	file << "<svg height=\"200\" width=\"400\">" << endl;
		
	for (int i = 0; i < 95; i++) {
		if ((i < 3) || ((i < 49) && (i>45)) || (i>91)) 	
			Y2 = 95;									
		else Y2 = 80;									
		if (binaryCode[i] == 1) file << " <line x1=\"" << X1 << "\"y1=\"" << Y1 << "\"x2=\"" << X1 << "\"y2=\"" << Y2 <<
			"\"style=\"stroke:rgb(0, 0, 0);stroke-width:2\"\/>\n";
		X1 += +pas;
	}
	
	file << " <text x =\"" << Xt << "\"y=\"" << Yt << "\"fill=\"black\""">" << code13[0] << "</text>\n";
	Xt += 7;
	for (int i = 1; i < 7; i++) {
		Xt += 13;
		file << " <text x =\"" << Xt << "\"y=\"" << Yt << "\"fill=\"black\""">" << code13[i] << "</text>\n";
	}
	Xt += 13;
	for (int i = 7; i < 13; i++) {
		Xt += 13;
		file << " <text x =\"" << Xt << "\"y=\"" << Yt << "\"fill=\"black\""">" << code13[i] << "</text>\n";
	}
	
	file << " <text x =\"" << Xp << "\"y=\"" << Yp << "\"fill=\"black\""">" << productName << "</text>\n";
	file << "</svg>" << endl;
	file << "</body>" << endl;
	file << "</html>" << endl;

	file.close();
	cout << "\tFile with name " << productName << ".html was successfully created\n";
	fileName = productName + ".html";

}

void CreateHTMLBarCode::openBrowser() {

	const char* fileTitle = fileName.c_str(); // Transform from string to const char*
	ShellExecute(NULL, "open", fileTitle, "", ".", SW_SHOWNORMAL);
}


CreateHTMLBarCode::~CreateHTMLBarCode()
{
}
