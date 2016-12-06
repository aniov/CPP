#include "../Headers/TransformToBinary.h"

using namespace std;

TransformToBinary::TransformToBinary()
{
}

vector<int> TransformToBinary::transformToBinaryCode(vector<string> fileStruct, vector<string> fileEndingP, vector<int> vectArray) {

	vector<int> binaryArray;
	string str1, str2, temp;
	int digit, counter;
	for (int i = 0; i < 95; i++) binaryArray.push_back(0);
	if ((vectArray[0] >= 0) && (vectArray[0]<9)) digit = vectArray[0];
	str1 = fileStruct[digit * 3 + 1];
	str2 = fileStruct[digit * 3 + 2];

	binaryArray[0] = binaryArray[2] = binaryArray[46] = binaryArray[48] = binaryArray[92] = binaryArray[94] = 1;
	counter = 3;
	for (int i = 1; i <= 6; i++) {
		if (str1[i - 1] == 'L') {
			temp = fileEndingP[vectArray[i] * 4 + 1];
			for (int j = 0; j < 7; j++) {				
				binaryArray[counter] = temp[j] - 48;
				counter++;
			}
		}
		else if (str1[i - 1] == 'G') {
			temp = fileEndingP[vectArray[i] * 4 + 2];
			for (int j = 0; j < 7; j++) {
				binaryArray[counter] = temp[j] - 48;
				counter++;
			}
		}
	}
	if (counter == 45) counter = counter + 5;
	else cout << "Error creating binary array\n";
	for (int i = 7; i <= 12; i++) {					
		if (str2[i - 7] == 'R') {					
			temp = fileEndingP[vectArray[i] * 4 + 3];
			for (int j = 0; j < 7; j++) {				
				binaryArray[counter] = temp[j] - 48;
				counter++;
			}
		}
	}
	
	return binaryArray;

}


TransformToBinary::~TransformToBinary()
{
}
