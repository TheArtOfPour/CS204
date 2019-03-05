#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

int mainbrain()
{
	// step 1
	string w3rd;
	cout << "Bird is the ______ ";
	cin >> w3rd;

	// step 2
	cout << "Word one is : " << w3rd << endl;

	// step 3
	string w4rd;
	cout << "_______ to your mother ~(^.^)~ ";
	cin >> w4rd;
	cout << "Word two is : " << w4rd << endl;

	// step 4
	string swerd = w3rd;
	w3rd = w4rd;
	w4rd = swerd;
	cout << "Now word one is : " << w3rd << " and word two is : " << w4rd << endl;


	system("pause");
	return 1337;
}