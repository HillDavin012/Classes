#ifndef CDACCOUNT_H
#define CDACCOUNT_H
#include"account.h"
#include "savingsaccount.h"

using namespace std;

template <typename T, typename T2>

class CDAccount : public SavingsAccount<T, T2>
{
public:
	//Constructors
	CDAccount() : SavingsAccount<T, T2>() {};


	//Parameterzed
	CDAccount(T2 accountNum, T amount, T interest) : SavingsAccount<T, T2>(accountNum, amount, interest) {};

	//Accessors
	void displayAccount();

	//Mutators
	void debit(T);
	void credit(T);

};

template <typename T, typename T2>
void CDAccount<T, T2>::debit(T amount)
{
	if (amount > 0)
	{

		cout << "Cannot debit from a CD account" << endl;
	}
	else
	{
		cout << "Thank you for not trying to withdraw from a CD Account" << endl;
	}
}

template <typename T, typename T2>
void CDAccount<T, T2>::displayAccount()
{
	cout << "CD Account " << Account<T, T2>::getAccountNumber() << " has interest rate of " << *SavingsAccount<T, T2>::interestRate << " and a balance of $" << Account<T, T2>::getBalance() << endl;
}

template <typename T, typename T2>
void CDAccount<T, T2>::credit(T amount)
{
	Account<T, T2>::setBalance(amount + (Account<T, T2>::getBalance()));
}

#endif // !CDACCOUNT_H