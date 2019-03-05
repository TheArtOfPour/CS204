// structures.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

// Structures are groups of fields or variables
struct BankAcct
{
	string name;
	double balance;
};

void displayAccounts(BankAcct accts[], int accountCount);

int main()
{
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	BankAcct accts[10];
	accts[0].name = "ICU";
	accts[0].balance = 500;
	accts[1].name = "WECU";
	accts[1].balance = 1500;
	accts[2].name = "Chase";
	accts[2].balance = 200;
	accts[3].name = "BECU";
	accts[3].balance = 100;
	accts[4].name = "Bank of Ian";
	accts[4].balance = 1;

	int accountCount = 5;
	string userResponse;
	displayAccounts(accts, accountCount);
	while (cin >> userResponse) {
		if (userResponse == "A") {
			cin.clear();
			string accountName;
			cout << "Name: ";
			getline(cin, accountName);
			accts[accountCount].name = accountName;
			cout << "\nBalance: ";
			cin >> accts[accountCount].balance;
			accountCount++;
		}
		else if (userResponse == "Q") {
			break;
		}
		displayAccounts(accts, accountCount);
	}

	
	system("pause");
    return 0;
}

void displayAccounts(BankAcct accts[], int accountCount)
{
	double total = 0;
	cout << "Account     Balance\n\n";
	for (int i = 0; i < accountCount; i++) {
		cout << accts[i].name << "    " << accts[i].balance << ".\n";
		total += accts[i].balance;
	}
	cout << "Total balance: " << total << ".\n\n";
	cout << "(A)dd     (Q)uit\n";
}
