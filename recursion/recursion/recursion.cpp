// recursion.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int factorial(int n);

int main()
{
	int i;
	cout << "Gimme number, om nom: ";
	cin >> i;
	cout << factorial(i) << endl;

	system("pause");
    return 0;
}

int factorial(int n) {
	if (n == 1)
		return n;
	return n * factorial(n - 1);
}
