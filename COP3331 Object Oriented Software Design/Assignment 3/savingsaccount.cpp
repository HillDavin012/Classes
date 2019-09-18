#include <iostream>
#include "savingsaccount.h"

//Constructors
SavingsAccount::SavingsAccount() 
{
	interestRate = new double(.01);
	setBalance(10.0);
}

//Parameterzed
SavingsAccount::SavingsAccount(double amount, double interest) 
{
	if (interest >= 0.0 && interest <= 1.0 && amount >= 0)
	{
		interestRate = new double(interest);
		setBalance(amount);
	}
	else
	{
		interestRate = new double(0.0);
		setBalance(0.0);
	}
}


//Destructor
SavingsAccount::~SavingsAccount() 
{
	cout << "Savings Account Desctructor called." << endl;
	delete interestRate;
}

//Accesors
double SavingsAccount::calcInterest()
{
	return ((*interestRate)*getBalance());
}

//Mutators
void SavingsAccount::credit(double amount) 
{
	Account::credit((calcInterest()));
}

void SavingsAccount::debit(double amount)
{
	Account::debit(amount);
}
