// Chapter 11.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;

class Child
{
	//Mother class members can access the private parts of class Child.
	friend class Mother;
public:
	Child();
	Child(string name);
	string name;
protected:
	void setName(string newName);
};

class Mother
{
public:
	Mother();
	string name;
	void setChildName(Child* child, string newName);
	void setName(string newName);
};

void testFriendship() {
	Mother *Theresa = new Mother();
	//The a->b notation is usually just a shorthand for (*a).b.
	Theresa->setName("Theresa");

	Child *Rufus = new Child("Rufus");

	cout << "Child's name : " << Rufus->name << endl;

	Theresa->setChildName(Rufus, "Rutherford");

	cout << "And now the Child's name : " << Rufus->name << endl;
}

Child::Child()
{
	name = "";
}

Child::Child(string newName)
{
	name = newName;
}

void Child::setName(string newName)
{
	name = newName;
}

Mother::Mother()
{
	name = "";
}

void Mother::setName(string newName)
{
	name = newName;
}

void Mother::setChildName(Child* child, string newName)
{
	child->setName(newName);
}

int main()
{
	testFriendship();
	system("pause");
	return 0;
}