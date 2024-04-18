#include<iostream>
#include<string>

using namespace std;


class Number {
	int number;
	int* numberArray;
	int arraySize;
	void AddNumber(int n) {
		int* temp = new int[arraySize + 1];
		for (size_t i = 0; i < arraySize; i++)
		{
			temp[i] = numberArray[i];
		}
		if (numberArray != nullptr)
		{
			delete[] numberArray;
		}
		numberArray = temp;
		temp = nullptr;
		numberArray[arraySize] = n;
		arraySize++;
	}
public:
	Number(int n = 0)
	{
		number = n;
		numberArray = nullptr;
		arraySize = 0;
	}
	Number(const Number& obj)
	{
		number = obj.number;
		arraySize = obj.arraySize;
		numberArray = new int[obj.arraySize];
		for (size_t i = 0; i < obj.arraySize; i++)
		{
			numberArray[i] = obj.numberArray[i];
		}
	}
	void Print()
	{
		cout << "Number is " << number << endl;
	}
	void PrintArray()
	{
		for (size_t i = 0; i < arraySize; i++)
		{
			cout << numberArray[i] << endl;
		}
	}
	void SetNumber(int n)
	{
		number = n;
		AddNumber(n);
	}
	friend Number operator+(Number&, Number&);
	friend bool operator>(Number&, Number&);
	friend ostream& operator<<(ostream&, Number&);
	friend istream& operator>>(istream&, Number&);
	Number operator=(const Number& obj)
	{
		if (this != &obj)
		{
			number = obj.number;
			arraySize = obj.arraySize;
			if (numberArray != nullptr)
			{
				delete[] numberArray;
			}
			numberArray = new int[obj.arraySize];
			for (size_t i = 0; i < obj.arraySize; i++)
			{
				numberArray[i] = obj.numberArray[i];
			}
		}
		return *this;
	}
	Number operator-(Number obj) {
		return Number(this->number - obj.number);
	}
	Number operator+=(Number obj)
	{
		return number += obj.number;
	}
	~Number()
	{
		if (numberArray != nullptr)
		{
			delete[] numberArray;
			numberArray = nullptr;
		}
		arraySize = 0;
	}
};

Number operator+(Number& obj1, Number& obj2)
{
	return  Number(obj1.number + obj2.number);
}

bool operator>(Number& obj1, Number& obj2)
{
	return obj1.number > obj2.number;
}

ostream& operator<<(ostream& COUT, Number& obj)
{
	COUT << obj.number << endl;
	return COUT;
}

istream& operator>>(istream& CIN, Number& obj)
{
	CIN >> obj.number;
	return CIN;
}

int main() {
	Number n1(5);
	Number n2 = 7;

	Number n3 = n2 - n1;
	n3 += 100;

	n3.SetNumber(142);
	n3.SetNumber(145745);
	n3.SetNumber(782);

	Number n4;

	n4 = n3;

	n4.PrintArray();
	return 0;

}
