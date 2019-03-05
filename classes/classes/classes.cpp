// classes.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class BankAcct
{
public:
	// Constructors
	BankAcct(string name, double balance);
	// Overloading
	BankAcct(string name);
	BankAcct();
	// Member functions
	void display();
	void deposit(double amt);
	void withdraw(double amt);
	BankAcct transfer(double amt, BankAcct acct);
private:
	string name;
	double balance;
};

int main()
{
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	// create account using constructor
	BankAcct wecu("WECU", 1000);
	BankAcct icu("ICU");
	BankAcct becu;

	vector <BankAcct> accts = { icu, wecu };
	accts.push_back(becu);

	wecu.display();
	icu.display();
	becu.display();

	wecu.withdraw(100);
	cout << "After what's left from my paycheck... \n";
	wecu.display();

	cout << "Transfer funds from WECU to ICU" << endl;
	icu = wecu.transfer(2, icu);
	wecu.display();
	icu.display();

	system("pause");
    return 0;
}








BankAcct::BankAcct(string n, double b)
{
	name = n;
	balance = b;
}

BankAcct::BankAcct(string n)
{
	name = n;
	balance = 0;
}

BankAcct::BankAcct()
{
	name = "---";
	balance = 0;
}

void BankAcct::display()
{
	cout << "Name: " << name << "\tBalance: " << balance << endl;
}

void BankAcct::deposit(double amt)
{
	balance += amt;
}

void BankAcct::withdraw(double amt)
{
	balance -= amt;
}

BankAcct BankAcct::transfer(double amt, BankAcct acct)
{
	balance -= amt;
	acct.balance += amt;
	return acct;
}
