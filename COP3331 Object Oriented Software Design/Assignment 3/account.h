#ifndef ACCOUNT_H
#define ACCOUNT_H

using namespace std;

class Account 
{
public:
	//Constructors
	Account();
	Account(double);

	//Destructor
	virtual ~Account();

	//Accessors
	double getBalance() const;

	//Mutator
	void setBalance(double);

	//Mutators
	virtual void debit(double);
	virtual void credit(double);

private:
	//Data Members
	double* balance;
};
#endif // !ACCOUNT_H

