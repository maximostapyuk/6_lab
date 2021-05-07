#pragma once
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

class Property {
private:
	string name;
public:
	int priority;
	Property();
	Property(string, int);

	int getPriority();
	void setPriority(int index);

	string getName();
	void setName(string name);

	friend ostream& operator<<(ostream&, Property);
	friend bool operator<(const Property&, const Property&);
	friend bool operator>(const Property&, const Property&);
};