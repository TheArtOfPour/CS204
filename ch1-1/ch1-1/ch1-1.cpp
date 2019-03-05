// ch1-1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	int daysLeftToSummer = 12;
	int daysLeftInAttentionSpan;
	bool itsSunnyInPhiladelphia = false;
	cout << "How many days do you left in you? : ";
	cin >> daysLeftInAttentionSpan;
	
	// > < == != && ||
	if (daysLeftToSummer > daysLeftInAttentionSpan && itsSunnyInPhiladelphia) {
		cout << "Going to be a rough final!\n";
	}
	else {
		cout << "You're going to make it.\n";
	}

	system("pause");
    return 0;
}

