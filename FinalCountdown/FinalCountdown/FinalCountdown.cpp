// FinalCountdown.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

struct Contact
{
	string name;
	int phone;
	string emails[5];
};

void displayContact(Contact contact);

int main()
{
	Contact myBro;
	myBro.name = "Richard Gere";
	myBro.phone = 5555556;
	myBro.emails[0] = "richgere1337@gmail.com";
	myBro.emails[1] = "geregere@gmail.com";
	myBro.emails[2] = "richard@geremail.com";

	displayContact(myBro);

	system("pause");
    return 0;
}

void displayContact(Contact contact) {
	cout << "Name: " << contact.name << endl;
	cout << "Phone: " << contact.phone << endl;
	cout << "Email1: " << contact.emails[0] << endl;
	cout << "Email2: " << contact.emails[1] << endl;
	cout << "Email3: " << contact.emails[2] << endl;
}

