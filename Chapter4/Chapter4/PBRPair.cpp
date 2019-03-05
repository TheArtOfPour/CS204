// Ch5-referenceSort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

void getFiveWords(string& w1, string& w2, string& w3, string& w4, string& w5);

void sortFiveWords(string& w1, string& w2, string& w3, string& w4, string& w5);

void swapWords(string& w1, string& w2);

int maint() {
	string word1, word2, word3, word4, word5;

	getFiveWords(word1, word2, word3, word4, word5);

	sortFiveWords(word1, word2, word3, word4, word5);

	cout << "The five words in sorted order are:\n";
	cout << word1 << " " << word2 << " " << word3;
	cout << " " << word4 << " " << word5 << endl;
	system("pause");
	return 0;
}

void getFiveWords(string& w1, string& w2, string& w3, string& w4, string& w5) {
	cout << "Enter 5 words separated by spaces: ";
	cin >> w1 >> w2 >> w3 >> w4 >> w5;
	return;
}

void sortFiveWords(string& w1, string& w2, string& w3, string& w4, string& w5) {
	bool sorted = false;

	while (!sorted) {
		sorted = true;
		if (w1 > w2) {
			sorted = false;
			swapWords(w1, w2);
		}
		if (w2 > w3) {
			sorted = false;
			swapWords(w2, w3);
		}
		if (w3 > w4) {
			sorted = false;
			swapWords(w3, w4);
		}
		if (w4 > w5) {
			sorted = false;
			swapWords(w4, w5);
		}
	}
	return;
}

void swapWords(string& w1, string& w2) {
	string temp;
	temp = w1;
	w1 = w2;
	w2 = temp;
	return;
}