#include <iostream>
#include <vector>
#include <iomanip>
#include "account.h"
#include "checkingaccount.h"
#include "savingsaccount.h"

using namespace std;

int main()
{
	//A vector of pointers
	vector <Account*> accounts;

	//Bool that flips back and forth to decide between checking and savings
	bool checkingAcc = true;

	//For 6 Bank accounts
	int num = 6;

	//These are reused for user input values
	double balance = 0;
	double fee = 0;
	double interestRate = 0;

	//The calls to change values in derived class of baseclass pointers
	double debit = 0;
	double credit = 0;
	
	//Loop for user to input values for accounts
	for (int i = 1; i <= num; i++)
	{
		if (checkingAcc) 
		{
			cout << "Checking Account " << i << endl;
			cout << "Please enter the balance: ";
			cin >> balance;

			cout << "Please enter the fee: ";
			cin >> fee;
			cout << endl;

			//Dynamically creating new pointer object, then putting it into vector
			Account *accountptr = new CheckingAccount(balance, fee);
			accounts.push_back(accountptr);
			
			cout << endl;

			//Flip bool so next time savings account is made
			checkingAcc = false;
		}		
		else 
		{
			cout << "Savings Account " << i << endl;
			cout << "Please enter the balance: ";
			cin >> balance;

			cout << "Please enter the interest rate: ";
			cin >> interestRate;

			//Dynamically creating new pointer object, then putting it into vector
			Account *accountptr = new SavingsAccount(balance, interestRate);
			accounts.push_back(accountptr);

			cout << endl;

			//Flip bool so next time checking account is made
			checkingAcc = true;
		}		
	}

	//Loop for user to withdraw and deposit, uses polymophism by accessing derived functions with baseClassPointer
	for (int i = 0, k = 1; i < num && k <= num; k++, i++)
	{
		if (checkingAcc)
		{
			cout << "Checking Account " << k << " Balance: $" << fixed << setprecision(2) << accounts.at(i)->getBalance() << endl;
			
			cout << "Enter an amount to withdraw: ";
			cin >> debit;

			//Accessing CheckingAccounts debit because accounts is virtual
			accounts.at(i)->debit(debit);

			cout << "Enter an amount to deposit into Account " << k << ": ";
			cin >> credit;

			//Accessing CheckingAccounts credit because accounts is virtual
			accounts.at(i)->credit(credit);

			cout << endl;

			cout << "Updated Account " << k << " balance: $" << fixed << setprecision(2) << accounts.at(i)->getBalance() << endl;

			cout << endl;
			
			//Flip bool so next time Saving account is made
			checkingAcc = false;
		}
		else 
		{
			cout << "Savings Account " << k << " Balance: " << fixed << setprecision(2) << accounts.at(i)->getBalance() << endl;
			cout << "Enter an amount to withdraw: " << k << ": ";
			cin >> debit;
			//Accessing savingsAccountDebit because accounts is virtual
			accounts.at(i)->debit(debit);

			cout << "Enter an amount to deposit into Account " << k << ": ";
			cin >> credit;
			balance = (credit + (accounts.at(i)->getBalance()));
			
			accounts.at(i)->setBalance(balance);
			//Accessing savingsAccountCredit because accounts is virtual
			accounts.at(i)->credit(balance);
			cout << "Adding $" << accounts.at(i)->getBalance() - balance << " interest to Account " << k << endl;
			cout << endl;

			cout << "Updated Account " << k << " balance: $" << fixed << setprecision(2) << accounts.at(i)->getBalance() << endl;

			cout << endl;

			//Flip bool so next time checking account is made
			checkingAcc = true;
		}
	}
	
	//Itterates through vector and deletes dynamically allocated memory
	for (vector<Account*>::iterator i = accounts.begin(); i != accounts.end(); ++i)
	{
		delete *i;
	}

    return 0;
}

