#include<iostream>
#include<string>

using namespace std;


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
	virtual void Introduce()
	{
		cout << "I am person " << name << ", and I am " << age << endl;
	}
	virtual ~Person()
	{
		cout << "Person destruction\n";
	}
};

class Student : public Person {
	int semester;
public:
	Student(int  s, string n, int a) :Person(n, a)
	{
		semester = s;
	}
	void Introduce()
	{
		cout << "I am student " << name << ", and I am " << age << endl;
	}
	~Student()
	{
		cout << "Student destruction\n";
	}
};

class Professor : public Person {
	string subject;
public:
	Professor(string s, string n, int a) :Person(n, a)
	{
		subject = s;
	}
	void Introduce()
	{
		cout << "I am professor " << name << ", and I am " << age << endl;
	}
};

int main()
{
	Person* p1 = new Student(3, "Harry", 24);
	Person* p2 = new Professor("Geography", "Tom", 45);

	Student* student = nullptr;
	Professor* professor = nullptr;

	professor = dynamic_cast<Professor*>(p2);

	if (professor != nullptr)
	{
		cout << "Conversion is successful\n";
		professor->Introduce();
	}
	else
	{
		cout << "Conversion failed\n";
	}


	delete p1;
	delete p2;

  return 0;

}
