// BarCodeGenerator.cpp : Defines the entry point for the console application.
//
#include "../Headers/stdafx.h"
#include "../Headers/ReadFromConsole.h"
#include "../Headers/Create13NrCode.h"
#include "../Headers/FileRead.h"
#include "../Headers/CreateHTMLBarCode.h"

#define FileEndingDigEAN13 "../DataBase/EndingDigEAN13.txt"
#define FileStructEAN131 "../DataBase/StructEAN13.txt"

using namespace std;

char countryCode[3] = { '5','9','4' };

int main()
{
    char reload;
    string productName;
    vector <char> enteredCode;
    vector <int> code13, binaryCode;
    vector <string> dataFromEAN131, dataFromEAN13;

    ReadFromConsole input;

   do {

        productName = input.getProductName();
        enteredCode = input.getInputArrayCode();

        if (enteredCode.size() == 0)
            return 0;

        Create13NrCode create13NrCode;
        code13 = create13NrCode.get13NrCode(enteredCode, countryCode);

        FileRead fileRead;
        dataFromEAN13 = fileRead.readFromFile(FileEndingDigEAN13);
        dataFromEAN131 = fileRead.readFromFile(FileStructEAN131);

        CreateHTMLBarCode createHtmlBarCode;
        createHtmlBarCode.GraficCodeBar(dataFromEAN131, dataFromEAN13, code13, productName);
        //createHtmlBarCode.openBrowser();

        cout << "\n\nDo you want to create another Bar Code ? Yes(y) / No(n) : ";
        cin >> reload;
        getchar();
        
    } while (toupper(reload) == 'Y');

    return 0;
}