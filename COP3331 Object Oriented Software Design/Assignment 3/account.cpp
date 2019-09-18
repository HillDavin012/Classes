#include"account.h"
#include <iostream>

//Constructors
//Defualt
Account::Account() 
{
	balance = new double(10.0);
}

//Parameterzed
Account::Account(double bal) 
{
	if (bal < 0) 
	{
		cout << "Error, can't be negative" << endl;
	}
	else
	{
		balance = new double (bal);
	}
}

//Destructor
Account::~Account()
{
	cout << "Account Desctructor called." << endl;
	delete balance;
}

//Accessors
double Account::getBalance() const
{
	return *balance;
}

//Mutators
void Account::setBalance(double bal) 
{
	balance = new double(bal);
}

void Account::debit(double amount) 
{
	if (amount > getBalance()) 
	{
		cout << "Debit amount exceeded account balance." << endl;
	}
	else 
	{		
		setBalance(getBalance() - amount);
	}
}

void Account::credit(double amount) 
{
	setBalance(amount + getBalance());
}