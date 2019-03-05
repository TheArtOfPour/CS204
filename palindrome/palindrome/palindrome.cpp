// palindrome.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string stringforward, stringbackward = "";

	cout << "Enter in a string and press Enter:\n";
	getline(cin, stringforward);
	cout << "You input: " << stringforward << endl;
	for (int i = stringforward.length() - 1; i >= 0; i--) {
		if (stringforward[i] == ' ') {
			continue;
		}
		stringbackward += stringforward[i];
	}
	stringforward = "";
	for (int i = stringbackward.length() - 1; i >= 0; i--) {
		if (stringbackward[i] == ' ') {
			continue;
		}
		stringforward += stringbackward[i];
	}
	cout << "and reversed: " << stringbackward << endl;

	if (stringforward == stringbackward) {
		cout << "PALINDROME!!!!!!!!!!!!!!!" << endl;
	}

	system("pause");
    return 0;
}

