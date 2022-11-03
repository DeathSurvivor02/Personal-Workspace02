#include <iostream>
#include <ifstream>
#include <ofstream>
#include <string>
#include <cstdlib>
#include <iomanip>
// #include
using namespace std;
void AccountDetails();
int main()
{

	cout.setf(ios::fixed, ios::floatfield);
	cout.setf(ios::showpoint);
	int tally=0;


	ifstream inOldMaster{"oldmast.dat", ios::in};
	if (!inOldMaster)
	{
		cerr << "Could not open oldmast.dat" << endl;
		exit(EXIT_FAILURE);
	}

	ifstream inTransaction{"transaction.dat", ios::in};
	if(!inTransaction)
	{
		cerr << "Could not open transaction.dat" << endl;
		exit(EXIT_FAILURE);
	}
	
	ofstream outNewMaster{"newmast.dat", ios::out};
	// ofstream outTransaction{"transaction.dat", ios::out};
	inOldMaster >> accountNumber >> quoted(name) >> CurrentBalance;
	inTransaction >> accountNum >> dollarAmount;
	outNewMaster << accountNum << " " << name << " " << currentBalance;

	while (inOldMaster)
	{
		while(inTransaction)
		{

		}
	}
	return 0;
}

AccountDetails()
{
	float currentBalance = 0.0;
	string name;
	string address;
	int telephone;
	float outstand_balance = 0.0;
	float credit_limit = 0.0;
	unsigned string discount_terms;
	unsigned string contract;

	int accountNum;
	int accountNumber;
	

}