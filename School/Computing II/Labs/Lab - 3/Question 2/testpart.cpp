#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>

using namespace std;

int main()
{
	int accountNum, accountNumber;
	string name;
	float currentBalance, dollarAmount;
	bool found;

	// opening files
	ifstream inOldMaster{"oldmast.dat", ios::in};

	ofstream outNewMaster{"newmast.dat", ios::out};

	// prints an error message if oldmast.dat or newmast.dat cannot be opened
	if (!inOldMaster || !outNewMaster)
	{
		cerr << "File cannot be opened!" << endl;
		exit(EXIT_FAILURE);
	}

	// looping through oldmaster.dat file
	while (inOldMaster >> accountNumber >> quoted(name) >> currentBalance)
	{
		ifstream inTransaction{"trans.dat", ios::in};		// reopens trans.dat file
		while (inTransaction >> accountNum >> dollarAmount) // looping through trans.dat file
		{
			if (accountNumber == accountNum) // determines whether the account number from the oldmast.dat and newmast.dat file are the same
			{
				currentBalance += dollarAmount; // updating the current balance
			}
		}
		outNewMaster << accountNumber << " " << name << " " << currentBalance << endl;
	}

	// opening trans.dat file
	ifstream inTransaction{"trans.dat", ios::in};
	// prints an error message if trans.dat cannot be opened
	if (!inTransaction)
	{
		cerr << "File cannot be opened!" << endl;
		exit(EXIT_FAILURE);
	}

	// looping through trans.dat file
	while (inTransaction >> accountNum >> dollarAmount)
	{
		// opening oldmast.dat file
		ifstream inOldMaster{"oldmast.dat", ios::in};
		acNum = false; // sets boolean variable to false
		// loops through oldmast.dat file
		while (inOldMaster >> accountNumber >> quoted(name) >> currentBalance)
		{

			if (accountNumber == accountNum)
			{
				acNum = true; // account is found
			}
		}
		if (acNum == false) // determines whether the account is not found
		{
			cout << "Unmatched transaction record for account number " << accountNum << endl;
		}
	}

	return 0; // terminate program
}