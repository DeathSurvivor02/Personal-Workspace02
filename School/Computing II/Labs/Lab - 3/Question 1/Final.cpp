//use a while loop to read master file
	// another while on the transcation file for records/payments
		//have a tallying variable for the total amount of transtions
		// read it in a new masterfile

#include <iostream>
#include <ifstream>
#include <ofstream>
#include <fstream>
#include <string>

using namespace std;

// functions
void transactions();

// global variables
struct account_info
{
	string name;
	string address;
	char telephone[6];
	float outstanding_balance;
	float credit_limit;
	unassigned discount_terms;
	string contract_arrangement;
	string history;
};

int main()
{

	return 0;
}

void transactions()
{
	// ifstream constructor opens the file;
	istream filemngr("trans.dat", ios::in);
	
	// exit program if ifstream couldn't open the file;
	if (!filemngr)
	{
		cerr << "File could not be opened" << endl;
		exit(EXIT_FAILURE);
	}
	
}


//while read the transaction
	// use a while loop to read the master numberfile
	// print error message for the account number 
