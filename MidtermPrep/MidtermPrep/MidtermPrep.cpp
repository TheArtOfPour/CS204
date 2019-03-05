// Ch3-04-for.cpp : Defines the entry point for the console application.
//

// a for loop uses the form:
//
// for (initialization; condition; increase) 
//	 statement;

#include "stdafx.h"
#include <iostream>
#include <Windows.h>

using namespace std;

void addTwoNumbers(int num1, int num2, int& result);

int main()
{
	int resultMain;
	int num1 = 2;
	int num2 = 3;
	addTwoNumbers(num1, num2, resultMain);

	cout << resultMain << endl;

	system("pause");
	return 0;
}

void addTwoNumbers(int num1, int num2, int& result) 
{
	result = num1 + num2;
	return;
}