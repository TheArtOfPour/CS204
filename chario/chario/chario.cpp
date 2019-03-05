// chario.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	char c1;

	cout << "Give me numbers:" << endl;
	do
	{
		cin.get(c1);
		if (isupper(c1)) {
			cout.put(c1);
		}
	} while (c1 != '\n');

	system("pause");
    return 0;
}

