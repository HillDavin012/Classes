#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H
#include"account.h"

using namespace std;

class SavingsAccount : public Account
{
public:
	SavingsAccount();
	SavingsAccount(double, double);

	//Destructors
	~SavingsAccount();

	//Accesors
	double calcInterest();

	//Mutators
	void credit(double);
	void debit(double);


private:
	//Data members
	double *interestRate;
};
#endif // !SAVINGSACCOUNT_H