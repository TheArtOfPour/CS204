// vectors.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include <vector>
#include <string>

using namespace std;

void display(vector<string>& v);

string command;

int main()
{
	vector <string> customers = { "Luke", "Han", "Leia" };
	string newCustomer;
	int customerToRemove;

	display(customers);

	while (command != "Q" && command != "q") {

		if ((command == "S" || command == "s") && customers.size() > 0) {
			// serve
			cout << "Now serving " << customers[0] << "..." << endl;
			customers.erase(customers.begin());
		}
		else if (command == "A" || command == "a") {
			// add
			cout << "Add a customer: ";
			cin >> newCustomer;
			customers.push_back(newCustomer);
		}
		else if ((command == "R" || command == "r") && customers.size() > 0) {
			// remove
			cout << "Who should Kylo remove?:";
			cin >> customerToRemove;
			customers.erase(customers.begin() + customerToRemove - 1);
		}

		display(customers);
	}
	
	system("pause");
    return 0;
}

void display(vector<string>& v)
{
	cout << "Queue-bert" << endl;
	cout << "------------------------------------" << endl;
	for (int i = 0; i < v.size(); i++) {
		cout << i+1 << ") " << v[i] << endl;
	}
	cout << endl;
	if (v.size() == 0) {
		cout << "(A)dd (Q)uit: ";
	}
	else {
		cout << "(S)erve  (A)dd  (R)emove  (Q)uit: ";
	}
	cin >> command;
}
