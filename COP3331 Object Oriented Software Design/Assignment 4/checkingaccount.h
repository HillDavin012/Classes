#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H
#include"account.h"

using namespace std;
template <typename T, typename T2>

class CheckingAccount : public Account<T, T2>
{
public:
	//Constructors
	CheckingAccount()
	{
		feeForTransaction = new T(1);
		Account<T, T2>::setBalance(10);
		Account<T, T2>::setAccountNumber("123456789");
	}

	//Parameterzed
	CheckingAccount(T2 accountNum, T bal, T fee)
	{
		if (bal >= 0 && fee >= 0)
		{
			feeForTransaction = new T(fee);
			Account<T, T2>::setBalance(bal);
			Account<T, T2>::setAccountNumber(accountNum);
		}
		else
		{
			feeForTransaction = new T(0);
			Account<T, T2>::setBalance(0);
			Account<T, T2>::setAccountNumber(accountNum);
		}
	}

	//Accessors
	void displayAccount();

	//Destructor
	~CheckingAccount()
	{
		delete feeForTransaction;
	}


	//Mutators
	void debit(T);
	void credit(T);

private:
	//Data members
	T *feeForTransaction;
};

template <typename T, typename T2>
void CheckingAccount<T, T2>::displayAccount()
{
	cout << "Checking Account " << Account<T, T2>::getAccountNumber() << " has a $" << *feeForTransaction << " transaction fee and a balance of $" << Account<T, T2>::getBalance() << endl;
}

//Mutators
template <typename T, typename T2>
void  CheckingAccount<T, T2>::debit(T amount)
{
	if (amount + (*feeForTransaction) > (Account<T, T2>::getBalance()))
	{
		cout << "Debit amount exceeded account balance." << endl;
	}
	else
	{
		cout << "$" << *feeForTransaction << " transaction fee charged. " << endl;
		Account<T, T2>::debit((amount + *feeForTransaction));
	}
}

template <typename T, typename T2>
void  CheckingAccount<T, T2>::credit(T amount)
{
	if (amount + (Account<T, T2>::getBalance()) > (*feeForTransaction))
	{
		cout << "$" << *feeForTransaction << " transaction fee charged. " << endl;
		Account<T, T2>::credit((amount - *feeForTransaction));
	}
	else
	{
		cout << "Debit amount exceeded account balance." << endl;
	}
}

#endif // !CHECKINGACCOUNT_H