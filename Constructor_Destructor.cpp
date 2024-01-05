#include<iostream>
#include<string>

using namespace std;

int identifier = 1;


class Product {
private:
	const int id;
	string name;
	float * weight;
	float * price;
public:
	Product():id(identifier++),name("DefaultProductName"),price(new float(0)),weight(new float(0))
	{
		cout << "Default constructor is called. ";
		cout << "Product " << this->name << " is created.\n";
	}
	Product(string n, float p, float w):id(identifier++)
	{
		cout << "User-defined constructor is called. ";
		this->name = n;
		this->weight = new float(w);
		this->price = new float(p);
		cout << "Product " << this->name << " is created.\n";
	}
	Product(Product & p):id(identifier++)
	{
		this->name = p.name;
		this->weight = new float(*(p.weight));
		this->price= new float(*(p.price));
	}
	void printProduct()
	{
		cout <<this->id<<" "<< this->name << " " << *(this->weight) << " kg, " << *(this->price) << " $" << endl;
	}
	~Product()
	{
		cout << "Destructor is called. ";
		delete this->weight, delete this->price;
		cout << "Product " << this->name << " is destroyed.\n";
	}
};

int main()
{
	Product p;

	Product p2("Shampoo", 14, 0.3), p3("Book", 30, 0.1);

	Product p4(p2);

	p2.printProduct();
	p4.printProduct();

	return 0;
}
