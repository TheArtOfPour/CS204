#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	string s1;

	ofstream outFile;

	outFile.open("c:\\Users\\justi\\Desktop\\CS131\\output\\testOutFile.txt");

	if (outFile.fail()) {
		cout << "Fail file fickle foundry\n";
		system("pause");
		exit(1);
	}

	// get input
	cout << "Enter words(q to quit): ";
	while (cin >> s1) {
		if (s1 == "q") {
			break;
		}
		outFile << s1 << endl;
	}
	outFile.close();

	system("pause");
	return 0;
}