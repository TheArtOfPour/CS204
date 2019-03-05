// recursion.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

// a recursive function is a function that calls itself
int factorial(int n);
int main()
{
	int myInt;
	do {
		cout << "Give me a number: ";
		cin >> myInt;
		cout << factorial(myInt) << endl;
	} while (myInt != 1);
	system("pause");
	return 0;
}

// n! = n * (n-1)!
int factorial(int n)
{
	if (n <= 1)
		return 1;
	return n * factorial(n - 1);
}
