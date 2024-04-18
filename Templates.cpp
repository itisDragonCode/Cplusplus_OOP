#include<iostream>
#include<string>

using namespace std;

template<typename T>
T Add(T a, T b)
{
	return a + b;
}

class Car {
	string name;
	int year;
public:
	Car(string n = "", int y = 0)
	{
		name = n;
		year = y;
	}
	friend ostream& operator<<(ostream&, Car&);
};

ostream& operator<<(ostream& COUT, Car& c)
{
	COUT << c.name << " " << c.year << endl;
	return COUT;
}

template<class T>
class Person {
	string name;
	T* array;
	int size;
public:
	Person(string n = "No name")
	{
		name = n;
		size = 0;
		array = nullptr;
	}
	void AddElement(T e) {
		T* temp = new T[size + 1];
		for (size_t i = 0; i < size; i++)
		{
			temp[i] = array[i];
		}
		if (array != nullptr)
			delete[]array;
		array = temp;
		temp = nullptr;
		array[size] = e;
		size++;
	}
	void PrintArray()
	{
		if (size > 0) {
			cout << "\nArray elements:\n";
			for (size_t i = 0; i < size; i++)
			{
				cout << array[i] << endl;
			}
		}
		else
		{
			cout << "\No elements:\n";
		}
	}
	~Person()
	{
		if (array != nullptr)
			delete[]array;
		size = 0;
	}
};

int main()
{
	Person<int> p1("John");

	p1.AddElement(14);
	p1.AddElement(257);
	p1.AddElement(15248);
	p1.PrintArray();

	Person<char> p2("Tom");

	p2.AddElement('f');
	p2.AddElement('k');
	p2.PrintArray();

	Car car1("BMW", 10), car2("Ford", 21);

	Person<Car> p3("Harry");

	p3.AddElement(car1);
	p3.AddElement(car2);
	p3.PrintArray();

  return 0;

}
