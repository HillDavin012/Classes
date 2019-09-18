#include "checkingaccount.h"
#include <iostream>

//Constructors
//Defualt
CheckingAccount::CheckingAccount() 
{
	feeForTransaction = new double(1.0);
	setBalance(10.0);
}

//Parameterzed
CheckingAccount::CheckingAccount(double bal, double fee) 
{
	if (bal >= 0 && fee >= 0) 
	{
		feeForTransaction = new double(fee);
		setBalance(bal);
	}
	else
	{
		feeForTransaction = new double(0.0);
		setBalance(0.0);
	}
}

//Destructor
CheckingAccount::~CheckingAccount() 
{
	cout << "Checking Account Desctructor called." << endl;
	delete feeForTransaction;
}

//Mutators
void CheckingAccount::debit(double amount) 
{
	if ( amount + (*feeForTransaction) > (getBalance()))
	{
		cout << "Debit amount exceeded account balance." << endl;
	}
	else
	{
		cout << "$" << *feeForTransaction << " transaction fee charged. " << endl;
		Account::debit((amount + *feeForTransaction));
	}
}

void CheckingAccount::credit(double amount)
{
	if (amount + (getBalance()) > (*feeForTransaction))
	{
		cout << "$" << *feeForTransaction << " transaction fee charged. " << endl;
		Account::credit((amount - *feeForTransaction));
	}
	else
	{
		cout << "Debit amount exceeded account balance." << endl;
	}
}

