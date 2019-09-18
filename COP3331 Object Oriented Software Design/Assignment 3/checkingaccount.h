#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H
#include"account.h"

using namespace std;

class CheckingAccount: public Account
{
public:
	//Constructors
	CheckingAccount();
	CheckingAccount(double, double);

	//Destructor
	~CheckingAccount();

	//Mutators
	void debit(double);
	void credit(double);

private:
	//Data members
	double *feeForTransaction;
};
#endif // !CHECKINGACCOUNT_H
