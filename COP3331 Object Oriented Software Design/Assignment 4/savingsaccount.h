#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H
#include"account.h"

using namespace std;
template <typename T, typename T2>

class SavingsAccount : public Account<T, T2>
{
public:
	//Constructors
	SavingsAccount()
	{
		interestRate = new T(.01);
		Account<T, T2>::setBalance(10.0);
		Account<T, T2>::setAccountNumber("123456789");
	}

	//Parameterzed
	SavingsAccount(T2 accountNum, T amount, T interest)
	{

		if (interest >= 0.0 && interest <= 1.0 && amount >= 0)
		{
			interestRate = new T(interest);
			Account<T, T2>::setBalance(amount);
			Account<T, T2>::setAccountNumber(accountNum);
		}
		else
		{
			interestRate = new T(0.0);
			Account<T, T2>::setBalance(0.0);
			Account<T, T2>::setAccountNumber(accountNum);
		}
	}


	//Destructors
	~SavingsAccount()
	{
		delete interestRate;
	}

	//Accesors
	T calcInterest();
	virtual void displayAccount();


protected:
	//Data members
	T *interestRate;
};

//Accesors
template <typename T, typename T2>
void SavingsAccount<T, T2>::displayAccount()
{
	cout << "Savings Account " << Account<T, T2>::getAccountNumber() << " has interest rate of " << *interestRate << " and a balance of $" << Account<T, T2>::getBalance() << endl;
}

template <typename T, typename T2>
T SavingsAccount<T, T2>::calcInterest()
{
	return ((*interestRate)*Account<T, T2>::getBalance());
}

#endif // !SAVINGSACCOUNT_H