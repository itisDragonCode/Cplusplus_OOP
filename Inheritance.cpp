#include<iostream>
#include<string>

using namespace std;

class Date {
protected:
	int day, month, year;
public:
	Date()
	{
		cout << "Class DATE Deafult ctor\n";
		day = 1;
		month = 1;
		year = 2024;
	}
	Date(int d, int m, int y)
	{
		cout << "Class DATE User-D ctor\n";
		day = d;
		month = m;
		year = y;
	}
	~Date()
	{
		cout << "Class DATE DESTRUCTION\n";
	}
	friend ostream& operator<<(ostream& COUT, const Date& obj)
	{
		COUT << obj.day << "/" << obj.month << "/" << obj.year << "  ";
		return COUT;
	}
};

class Employee : Date {
	string name;
public:
	Employee(string n, int d, int m, int y) :Date(d, m, y)
	{
		cout << "Class Employee User-D ctor\n";
		name = n;


	}
	~Employee()
	{
		cout << "Class Employee DESTRUCTION\n";
	}
	friend ostream& operator<<(ostream& COUT, const Employee& obj)
	{
		COUT << (Date&)obj;
		COUT << obj.name << endl;
		return COUT;
	}
};

int main() {

	Employee e("John", 24, 5, 2001);

	cout << e;
	
	return 0;

}
