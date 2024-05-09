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
	virtual void PrintYear()
	{
		cout << "Year is " << year << " (Date class)" << endl;
	}
	void PrintMonth()
	{
		cout << "Mont is " << month << " (Date class)" << endl;
	}
};

class Employee :public Date {
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
	void PrintYear()
	{
		cout << "Year is " << year << " (Employee class)" << endl;
	}
	void PrintMonth()
	{
		cout << "Month is " << month << " (Employee class)" << endl;
	}
};


class Person {
protected:
	string name;
	int age;
public:
	Person(string n, int a)
	{
		name = n;
		age = a;
	}
	virtual void Introduce() = 0;
};



class Student : public Person {
	int ID;
	int semester;
public:
	Student(int id, int s, string n, int a) :Person(n, a)
	{
		ID = id;
		semester = s;
	}
	void Introduce() {
		cout << "I am student " << name << ", and I am " << age << endl;
	}
};

class Professor : public Person {
	string subject;
public:
	Professor(string s, string n, int a) : Person(n, a)
	{
		subject = s;
	}
	void Introduce() {
		cout << "I am professor " << name << ", and I am " << age << endl;
	}
};

void PrintInfo(Person& obj)
{
	obj.Introduce();
}

void PrintInfo(Person* obj)
{
	obj->Introduce();
}

int main()
{
  
Person* persons[2];

persons[0] = new Student(12451, 3, "Harry", 24);
persons[1] = new Professor("History", "Tom", 45);

Student* student = nullptr;
Professor* professor = nullptr;

professor = dynamic_cast<Professor*>(persons[0]);

if (professor != nullptr)
{
	cout << "Conversion is successful\n";
}
else
{
	cout << "Failed to convert\n";
}


delete persons[0];
delete persons[1];


return 0;
}
