#include "stdafx.h"
#include <iostream>
//#include <windows.h>
using namespace std;
int main()
{
	int count = 0;
	int num;
	cout << "Enter a number: ";
	cin >> num;
	count = num;
	for (count <= 0; count--;) {
		cout << num << " ";
	}
	system("pause");
	return 0;
}