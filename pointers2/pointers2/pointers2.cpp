// Pointers.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	// integers
	int num1 = 111, num2 = 222;
	// pointers to integers
	int *p1, *p2;

	cout << "num1 is " << num1 << endl;
	cout << "num2 is " << num2 << endl;

	cout << "&num1 is " << &num1 << endl;
	cout << "&num2 is " << &num2 << endl;

	// pointers contain addresses
	p1 = &num1;
	cout << "p1 is " << p1 << endl;

	// * dereferences pointers
	cout << "*p1 is " << *p1 << endl;

	*p1 = 333;
	cout << "after *p1 = 333, num1 is " << num1 << endl;

	// don't do this plz
	// dynamic variables using "new"
	p1 = new int;
	cout << "After p1 = new int, p1 is " << p1 << endl;
	cout << "After p1 = new int, *p1 is " << *p1 << endl;
	*p1 = 444;
	cout << "After *p1 = 444, *p1 is " << *p1 << endl;
	cout << "num1 is " << num1 << endl;

	// destroy, eradicate, ex-term-innnnnate using "delete"
	delete p1;
	cout << "After delete p1, p1 is " << p1 << endl;
	cout << "After delete p1, *p1 is " << *p1 << endl;

	// at this point the memory at p1 is freed for C to reuse
	p1 = &num2;
	cout << "After delete p1, *p1=&num2, *p1 is " << *p1 << endl;

	// dynamic arrrrrrrrrrrrrrrrrray
	p2 = new int[10];
	p2[-1] = 111;
	cout << "p2[-1] is " << p2[-1] << endl;
	cout << "p2 is " << p2 << endl;

	// loop over it
	for (int i = 0; i < 10; i++) {
		p2[i] = i % 4;
	}
	for (int i = -1; i < 111; i++) {
		cout << p2[i] << " ";
	}
	cout << endl;

	cout << "p2 + 1 is " << p2 + 1 << endl;
	cout << "p2 + 2 is " << p2 + 2 << endl;
	cout << "p2 + 3 is " << p2 + 3 << endl;

	p1 = p2 + 9;
	cout << "After p1 = p2 + 9, *p1 is " << *p1 << endl;

	delete [] p2;
	cout << "After delete [] p2, p2[0] is " << p2[0] << endl;

	system("pause");
	return 0;
}

