#include "stdafx.h"
#include <iostream>
using namespace std;


int main6()
{
	int gradeInt;
	char gradeChar;
	
	cout << "Enter a grade: ";
	cin >> gradeInt;

	if (gradeInt >= 90)
		gradeChar = 'A';
	else if (gradeInt >= 80)
		gradeChar = 'B';
	else if (gradeInt >= 70)
		gradeChar = 'C';
	else if (gradeInt >= 60)
		gradeChar = 'D';
	else
		gradeChar = 'F';

	cout << "You got a " << gradeChar << "!" << endl;

	system("pause");
	return 0;
}