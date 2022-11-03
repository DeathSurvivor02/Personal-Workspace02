#include <iostream>
// file header
#include <fstream>
// #include <ifstream>
// #include <ofstream>
// unknown
#include <iomanip>
// c standard library
#include <cstdlib>
#include <string>

int main()
{
	int accountNum;
	int accountNumber;
	std::string name;
	bool acNum;
	float currentBalance;
	float dollarAmount;
	
	// file pointer/s
	std::ifstream inOldMaster{"oldmast.dat", ios::in};
	std::ifstream inTransaction{"trans.dat", ios::in};
	std::ofstream outNewMaster{"newmast.dat", ios::out};


	while (inOldMaster >> accountNumber >> quoted(name) >> currentBalance)
	{
		std::ifstream (inTransaction >> accountNum >> dollarAmount );
		if (accountNumber == accountNum)
		{
			currentBalance += dollarAmount;
		}
		outNewmaster << accountNum << " " << name << " " << currentBalance;

	}
	
	std::ifstream inTransaction("trans.dat", ios::in);
	while (inTransaction >> accountNum >> dollarAmount)
	{
		std::ifstream inOldMaster{"oldmast.dat", ios::in};
		acNum = false;
		while (inOldMaster >> accountNum >> quoted(name) >> currentBalance)
		{
			if (accountNumber == accountNum)
			{
				acNum = true;
			}
		}
		if (acNum == false)
		{
			"Unmatched transaction record for account number" << accountNum;
		} 
	}
	return 0;
}