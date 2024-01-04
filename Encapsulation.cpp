#include<iostream>
#include<string>

using namespace std;

class BankAccount {
private:
	string userName;
	string password;
	float balance;
public:
	void SignUp(string, string);
	void CheckBalance(string, string);
};

void BankAccount::SignUp(string u, string p) {
	this->userName = u;
	this->password = p;
	this->balance = 1000;
}

void BankAccount::CheckBalance(string u, string p)
{
	if (this->userName.compare(u) == 0 && this->password.compare(p)==0)
	{
		cout << "Your balance is " << this->balance << endl;
	}
	else
	{
		cout << "Wrong credentials\n";
	}
}

int main()
{
	string username, password;
	BankAccount* account = new BankAccount;

	cout << "Create a bank account\n";
	cout << "Enter username: ";
	cin >> username;
	cout << "Enter password: ";
	cin >> password;

	account->SignUp(username, password);

	cout << "\nBank account is successfully created\n";
	cin.ignore();
	cin.get();
	system("cls");
	username = "";
	password = "";


	cout << "Check balance\n";
	cout << "Enter username: ";
	cin >> username;
	cout << "Enter password: ";
	cin >> password;

	account->CheckBalance(username, password);

	delete account;

	return 0;
}
