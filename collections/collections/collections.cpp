// collections.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int main()
{
	/*
	{1, 2, 6, 1}
	{'i', 'n', 'i', 't'}
	*/

	string s1 = "initial value", s2, s3;
	cout << "s1: " << s1 << endl;
	s1 += " moar stuff";
	cout << "s1: " << s1 << endl;
	cout << "length: " << s1.length() << endl;
	s2 = s1.substr(s1.length() - 5, 5);
	cout << "s2: " << s2 << endl;

	for (int i = 0; i < 12; i++) {
		cout << s1[i] << " ";
	}
	cout << endl;



	




	char string1[24] = "initial value"; // '\0'
	char string2[5] = "food"; // '\0'
	char string3[5] = "food"; // '\0'

	cout << string1 << endl;

	// does not work ! string1 = "new value";
	strcpy(string1, "new value");
	
	cout << string1 << endl;
	cout << "Length : " << strlen(string1) << endl;


	strncpy(string1, " oooooh", 5);
	cout << string1 << endl;

	// == won't work
	int result = strcmp(string2, string3);

	if (strcmp(string2, string3) == 0) {
		cout << "EQUAL" << endl;
	}
	cout << "string compare result:" << result << endl;


	system("pause");
    return 0;
}

