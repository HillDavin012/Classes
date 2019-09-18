#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <string>

using namespace std;
template <typename T, typename T2>

class Account
{
public:

	//Constructors
	Account()
	{
		Account<T, T2>::setBalance(10.0);
		Account<T, T2>::setAccountNumber("123456789");
	}

	Account(T bal, T2 AccountNum)
	{
		if (bal < 0)
		{
			cout << "Error, can't be negative" << endl;
		}
		else
		{
			balance = new T(bal);
			Account<T, T2>::setAccountNumber(AccountNum);
		}
	}

	//Destructor
	virtual ~Account()
	{
		delete balance;
		delete accountNumber;
	}

	//Accessors
	T getBalance() const;
	T2 getAccountNumber() const;
	virtual void displayAccount();


	//Mutator
	void setBalance(T);
	void setAccountNumber(T2);

	//Mutators
	virtual void debit(T);
	virtual void credit(T);

private:
	//Data Members
	T *balance;
	T2 *accountNumber;
};



//Accessors
template <typename T, typename T2>
T Account<T, T2>::getBalance() const
{
	return *balance;
}

template <typename T, typename T2>
T2 Account<T, T2>::getAccountNumber() const
{
	return *accountNumber;
}

template <typename T, typename T2>
void Account<T, T2>::displayAccount()
{
	cout << "This is the account base display" << endl;
}

//Mutators
template <typename T, typename T2>
void Account<T, T2>::setBalance(T bal)
{
	balance = new T(bal);
}

template <typename T, typename T2>
void Account<T, T2>::setAccountNumber(T2 accountNum)
{
	accountNumber = new T2(accountNum);
}

template <typename T, typename T2>
void Account<T, T2>::debit(T amount)
{
	if (amount > Account<T, T2>::getBalance())
	{
		cout << "Debit amount exceeded account balance." << endl;
	}
	else
	{
		Account<T, T2>::setBalance(Account<T, T2>::getBalance() - amount);
	}
}

template <typename T, typename T2>
void Account<T, T2>::credit(T amount)
{
	Account<T, T2>::setBalance(amount + Account<T, T2>::getBalance());
}

#endif // !ACCOUNT_H