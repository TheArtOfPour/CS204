// Ch6-04-sortFileActivitySolution.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream> // for cout, cin
#include <fstream>  // for file I/O
#include <string>
#include <Windows.h>
#include <stdio.h>
using namespace std;

void swapInts(int& n1, int& n2);

int main()
{
	string s1;
	string fileName = "sortTemp", oldFileName;
	char fileNameSuffix = 'a';
	int n1, n2, passNumber = 1;
	ifstream inFile;
	ofstream outFile;
	bool notSorted = true;

	// Open an input file
	inFile.open("C:\\Users\\justi\\Desktop\\CS131\\output\\testInFile.txt");
	// exit with error if open fails
	if (inFile.fail())
	{
		cout << "File open failed.\n";
		system("pause");
		exit(1);
	}

	while (notSorted) {
		notSorted = false;

		// Create output file
		outFile.open("C:\\Users\\justi\\Desktop\\CS131\\output\\" + fileName + fileNameSuffix + ".txt");
		// exit with error if open fails
		if (outFile.fail())
		{
			cout << "File open failed.\n";
			system("pause");
			exit(1);
		}

		cout << "Reading file pass " << passNumber++ << ":\n";
		Sleep(1000);
		// Get first number in file
		if (!(inFile >> n1))
		{
			cout << "No data in file.\n";
			system("pause");
			exit(1);
		}


		while (inFile >> n2)
		{
			if (n1 > n2)  // if the previous number is larger, swap
			{
				swapInts(n1, n2);
				notSorted = true;
			}
			outFile << n1 << endl;  // output previous number
			cout << n1 << " ";
			n1 = n2;  // set current number to previous
		}
		outFile << n1 << endl;  // write the last number
		cout << n1 << endl;

		outFile.close();
		inFile.close();

		if (notSorted)
		{
			// Open an input file
			inFile.open("c:\\Users\\justi\\Desktop\\CS131\\output\\" + fileName + fileNameSuffix + ".txt");
			// exit with error if open fails
			if (inFile.fail())
			{
				cout << "File open failed.\n";
				system("pause");
				exit(1);
			}


			// Increment output file suffix
			fileNameSuffix++;

		}

	}

	// display the sorted output
	cout << "The sorted output is: \n";
	// Open an input file
	inFile.open("c:\\Users\\justi\\Desktop\\CS131\\output\\" + fileName + fileNameSuffix + ".txt");
	// exit with error if open fails
	if (inFile.fail())
	{
		cout << "File open failed.\n";
		system("pause");
		exit(1);
	}
	while (inFile >> n1)
	{
		cout << n1 << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}

void swapInts(int& n1, int& n2)
{
	int temp;
	temp = n1;
	n1 = n2;
	n2 = temp;
	return;
}