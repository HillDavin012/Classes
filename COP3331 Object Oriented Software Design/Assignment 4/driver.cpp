#include <iostream>
#include <vector>
#include <iomanip>
#include <typeinfo>
#include "account.h"
#include "checkingaccount.h"
#include "savingsaccount.h"
#include "cdaccount.h"


using namespace std;

int main()
{
	//2 vectors of base class pointers to templates
	vector <Account<int, string>*> accounts;
	vector <Account<double, string>*> accounts2;

	//Bool that flips back and forth to decide between checking and savings
	bool checkingAcc = false;
	bool savingsAccount = false;
	bool cdAccount = true;

	//For 4 Bank accounts
	int num = 4;

	//These are for user input values
	double balance = 0.0;
	double interestRate = 0.0;
	double addInterest = 0.0;
	double fee = 0.0;
	double debit = 0.0;
	double credit = 0.0;
	string accountNumber;

	//Loop for user to input values for accounts
	for (int i = 1; i <= num / 2; i++)
	{
		if (cdAccount)
		{
			std::cout << "CDA Account " << i << endl;

			std::cout << "Please enter the account number: ";
			std::getline(std::cin, accountNumber);

			std::cout << "Please enter the balance: ";
			std::cin >> balance;

			std::cout << "Please enter the interest rate: ";
			std::cin >> interestRate;

			//Dynamically creating new pointer object, then putting it into vector
			Account<double, string> *accountptr2 = new CDAccount<double, string>(accountNumber, balance, interestRate);
			accounts2.push_back(accountptr2);

			std::cout << endl;

			//Flip bool to move to next account
			cdAccount = false;
		}
		else
		{
			std::cout << "Savings Account " << i << endl;
			std::cin.ignore();

			std::cout << "Please enter the account number: ";
			std::getline(std::cin, accountNumber);

			std::cout << "Please enter the balance: ";
			std::cin >> balance;

			std::cout << "Please enter the interest rate: ";
			std::cin >> interestRate;

			//Dynamically creating new pointer object, then putting it into vector
			Account<double, string> *accountptr3 = new SavingsAccount<double, string>(accountNumber, balance, interestRate);
			accounts2.push_back(accountptr3);

			std::cout << endl;

			//Flipping bools to move to next account
			cdAccount = true;
		}
	}

	for (int i = 1; i <= num / 2; i++)
	{
			//Users inputs checking account info
			std::cout << "Checking Account " << i << endl;
			std::cin.ignore();

			std::cout << "Please enter the account number: ";
			std::getline(std::cin, accountNumber);

			std::cout << "Please enter the balance: ";
			std::cin >> balance;
			balance = (int)balance;

			std::cout << "Please enter the fee: ";
			std::cin >> fee;
			fee = (int)fee;

			//Dynamically creating new pointer object, then putting it into vector
			Account<int, string> *accountptr = new CheckingAccount<int, string>(accountNumber, balance, fee);
			accounts.push_back(accountptr);

			std::cout << endl;

		
	}

	cdAccount = true;
	//Loop for withdrawing from CD and Saving accounts
	for (int i = 0, k = 1; i < num / 2 && k <= num / 2; k++, i++)
	{
		if (cdAccount)
		{
			//CD account begins
			std::cout << "CD Account " << k << " Balance: $" << fixed << setprecision(2) << accounts2.at(i)->getBalance() << endl;
			std::cout << "Enter an amount to withdraw: ";
			std::cin >> debit;

			//Down casting pointer to derived class
			CDAccount<double, string> *derivedptr = dynamic_cast <CDAccount<double, string>*>(accounts2.at(i));

			//Here it calls CD account debit, which does not allow debit to be called on a CD account
			derivedptr->debit(debit);

			std::cout << "Enter an amount to deposit: ";
			std::cin >> credit;

			//Calculating new balance, setting to new balance, then adding interest
			balance = derivedptr->getBalance();
			balance += credit;
			derivedptr->setBalance(balance);
			addInterest = derivedptr->calcInterest();
			balance += addInterest;
			derivedptr->setBalance(balance);


			//Accessing down cast pointer to calc interest
			std::cout << "Adding $" << addInterest << " interest to CD Account " << k << endl;

			//Calling for display the account
			accounts2.at(i)->displayAccount();

			std::cout << endl;

			//Change bool to change accounts
			cdAccount = false;
		}
		else
		{
			//Savings account begins
			std::cout << "Savings Account " << i << " Balance: $" << fixed << setprecision(2) << accounts2.at(i)->getBalance() << endl;
			std::cout << "Enter an amount to withdraw: ";
			std::cin >> debit;

			//Down casting pointer to derived class
			SavingsAccount<double, string> *derivedptr = dynamic_cast <SavingsAccount<double, string>*>(accounts2.at(i));

			//Calculating new balance by getting current and subtracting debit, then putting whats left back into account
			balance = derivedptr->getBalance();
			balance -= debit;
			derivedptr->setBalance(balance);

			std::cout << "Enter an amount to deposit: ";
			std::cin >> credit;

			//Calculating new balance, setting to new balance, then adding interest
			balance = derivedptr->getBalance();
			balance += credit;
			derivedptr->setBalance(balance);
			addInterest = derivedptr->calcInterest();
			balance += addInterest;
			derivedptr->setBalance(balance);


			//Accessing down cast pointer to calc interest
			std::cout << "Adding $" << addInterest << " interest to Savings Account " << i <<  endl;

			//Calling for display the account
			accounts2.at(i)->displayAccount();

			std::cout << endl;

			cdAccount = true;
		}
	}

	//Checking account loop
	for (int i = 0, k = 1; i < num / 2 && k <= num / 2; k++, i++)
	{
		//Loop for user to withdraw and deposit, uses polymophism by accessing derived functions with baseClassPointer
		std::cout << "Checking Account " << k << " Balance: $" << fixed << setprecision(2) << accounts.at(i)->getBalance() << endl;
		std::cout << "Enter an amount to withdraw: ";
		std::cin >> debit;
		debit = (int)debit;

		//Accessing CheckingAccounts debit because accounts is virtual
		accounts.at(i)->debit(debit);

		std::cout << "Enter an amount to deposit into Checking Account " << k << ": ";
		std::cin >> credit;
		credit = (int)credit;

		//Accessing CheckingAccounts credit because accounts is virtual
		accounts.at(i)->credit(credit);

		//Calling for display the account
		accounts.at(i)->displayAccount();

		std::cout << endl;
	}

	//Itterates through vectors and deletes dynamically allocated memory
	for (vector <Account<int, string>*>::iterator i = accounts.begin(); i != accounts.end(); ++i)
	{
		delete *i;
	}

	for (vector <Account<double, string>*>::iterator i = accounts2.begin(); i != accounts2.end(); ++i)
	{
		delete *i;
	}
	return 0;
}
