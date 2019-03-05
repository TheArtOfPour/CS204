// Ch7-arrays.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

void showArray(int array[], int size);
void swapInts(int& num1, int& num2);

int main()
{
	string sortBy = "asc";
	const int size = 25;
	srand(time(NULL));
	int numberArray[size] = {};
	int number, randNum; 
	cout << "Give me a number: ";
	cin >> number;
	numberArray[0] = number;
	cout << "The number is ... " << numberArray[0] << endl;

	for (int i = 1; i < size; i++) {
		randNum = (rand() % 1337) + 1;
		numberArray[i] = randNum;
	}

	showArray(numberArray, size);
	swapInts(numberArray[0], numberArray[1]);
	showArray(numberArray, size);

	cout << "Would you like to sort in 'asc' order or 'desc' order? ";
	cin >> sortBy;

	bool sorted = false;
	int loopCount = 0;
	int swapCount = 0;
	while (!sorted) {
		sorted = true;
		for (int i = 0; i < size - 1; i++) {
			if ((sortBy == "asc" && numberArray[i] > numberArray[i + 1])
				|| (sortBy == "desc" && numberArray[i] < numberArray[i + 1])) {
				swapInts(numberArray[i], numberArray[i + 1]);
				sorted = false;
				swapCount++;
			}
		}
		loopCount++;
	}
	showArray(numberArray, size);
	cout << "Loops:" << loopCount << " Swaps:" << swapCount << endl;

	cout << endl;
	system("pause");
	return 0;
}

void showArray(int array[], int size)
{
	cout << endl << "[";
	for (int i = 0; i < size; i++) {
		cout << array[i] << " ";
	}
	cout << "]" << endl;
}

void swapInts(int & num1, int & num2)
{
	int temp = num1;
	num1 = num2;
	num2 = temp;
}
