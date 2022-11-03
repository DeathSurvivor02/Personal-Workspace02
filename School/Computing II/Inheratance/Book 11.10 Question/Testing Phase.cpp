#include <iostream>
// #include "file.h"

class Account
{
public:
	double balance;

	Account(double bal);
	Credit();
	debit();
};

void Account::Account(double bal)
{
	if (bal >= 0.0)
		balance = balbalance = bal;
	else
		bal = 0.0;
	std::cout << "Error!\nThe Value You Have entered is invalid." << std::endl;
}
class SavingsAccount : public Account
{
};
class CheckoutAccount : public Account
{
};

int main()
{
	Account Account_class;
}