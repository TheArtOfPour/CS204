// FinalFinalCountdown.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int divide(int number, int divisor, int& remainder);
int multiply(int number, int multiple);

int main()
{
	int number, divisor, remainder = 0;
	while (true) {
		cout << "Gimme number : ";
		cin >> number;
		cout << "Gimme divisor/multiple : ";
		cin >> divisor;
		if (divisor == 0) {
			break;
		}
		int result = divide(number, divisor, remainder);
		cout << "Result : " << result
			<< " with a remainder of " << remainder << endl << endl;
		int multiplied = multiply(number, divisor);
		cout << "Multiplied it = " << multiplied << endl << endl;
	}
	system("pause");
    return 0;
}

int multiply(int number, int multiple) {
	if (multiple == 1)
		return number;
	return number + multiply(number, multiple - 1);
}

int divide(int number, int divisor, int& remainder) {
	int localRemainder = number - divisor;
	if (localRemainder < 0) {
		remainder = number;
		return 0;
	}
	return 1 + divide(localRemainder, divisor, remainder);
}
