#include<iostream>
#include<string>

using namespace std;


class Date {
protected:
	int day, month, year;
public:
	Date()
	{
		day = 1;
		month = 1;
		year = 2024;
	}
	Date(int d, int m, int y)
	{
		day = d;
		month = m;
		year = y;
	}
	friend ostream& operator<<(ostream& COUT, const Date& obj)
	{
		COUT << obj.day << "/" << obj.month << "/" << obj.year << "  ";
		return COUT;
	}
	int century = 21;
	void PrintYear()
	{
		cout << "Year is " << year << endl;
	}
};

class Employee :protected Date {
	string name;
public:
	Employee(string n, int d, int m, int y) :Date(d, m, y)
	{
		name = n;
	}
	friend ostream& operator<<(ostream& COUT, const Employee& obj)
	{
		COUT << (Date&)obj;
		COUT << obj.name << endl;
		return COUT;
	}
};

class SuperEmployee : Employee {
	float bonus;
	void Method()
	{
		PrintYear();
		century;
	}
};

