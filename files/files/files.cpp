// files.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	string s1;

	ifstream inFile;

	inFile.open("C:\\Users\\justi\\Desktop\\CS131\\output\\testOutFile.txt");

	if (inFile.fail()) {
		cout << "File open has failed.";
		system("pause");
		exit(1);
	}

	cout << "Lets loop through the poop file";
	while (inFile >> s1) {
		cout << s1 << endl;
	}

	system("pause");
    return 0;
}

