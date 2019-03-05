// abc.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

void test1();
int test2();

int main()
{
	test1();
	cout << test2() << endl;
	system("pause");
    return 0;
}

void test1() {
	cout << 10 << endl;
}

int test2() {
	return 20;
}