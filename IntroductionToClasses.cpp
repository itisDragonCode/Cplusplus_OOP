#include<iostream>
#include<string>

using namespace std;

struct Car {
public:
	string make;
	string model;
	void Buy() {
		cout << "Buy\n";
	}
};

class Product {
private:
	string name;
	float weight=0;
	float price=0;
	void Purchase() {
		cout << "Purchase\n"<<this->name;
	}
public:
	string GetName()
	{
		return this->name;
	}
	void SetName(string n)
	{
		 this->name= n;
	}
	float GetPrice()
	{
		return this->price;
	}
	void SetPrice(float p)
	{
		this->price = p;
	}
	float GetWeight() const
	{
		return this->weight;
	}
	void SetWeight(float w)
	{
		(*this).weight = w;
	}
	void printAddress() const
	{
		cout << this->name << " has following address " << this << endl;
	}
};

int main()
{
	Car c;
	Product p,p2;

	p.SetName("Shampoo");
	p.SetWeight(0.3);
	p.SetPrice(10);

	cout << &p << endl;
	p.printAddress();
	

	p2.SetName("Book");
	p2.SetWeight(0.1);
	p2.SetPrice(30);

	const Product pro;

	pro.printAddress();
	

	return 0;
}
