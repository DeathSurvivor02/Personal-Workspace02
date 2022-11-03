#include <iostream>
#include <string>
#include <fstream> // read/write
// #include <ofstream> //write
// #include <ifstream> // read

// #include <windows.h>
using namespace std;

// functions
void menu();
void new_acc();
void list();
void void_list();
void edit();
void transact();
void erase();
void see();

// classes
class bank
{
// public:
protected:
	int x = 0;
	int choice = 0;
	struct account_info
	{
		string name;
		// std::string date_of_birth;
		int day;
		int month;
		int year;
		char citizenship_number[17];
		string address;
		long int phone_number = 0;
		double balance = 0;
		string ac_type;
	};
	struct account_info newacc, list, edit, transact, erase;

};
class NewAcc: public bank
{
	
};

class account : public bank
{
	// using bankfile
public:
	// Openfile(){if (myfile.is_open());}
private:
	// std::ofstream bankfile;
	// bankfile.open("bankdata.txt");
	// template <...> opener = bankfile.open("bankdata.txt");
};

/*
menu - this function displays the menu or welcome screen to perform
different banking activities mentioned below.
 */
void menu()
{
	bank Bank;
	// struct	Bankaccount_details;

// int choice = 0;
// label:
startMenu:
	std::cout << "Welcome to Bank Management\n";
	std::cout << "What do you wish to do?" << std::endl;
	std::cout << "1. Create new account\n2. Update information of existing account\n3. For transcation\n4. Check details of existing account\n5. Remove existing account\n6. View customer's list\n7. Exit\n\n";
	std::cout << "Enter your choice: ";
	std::cin >> Bank.choice;
	while ((Bank.choice <= 7) && (Bank.choice > 0))
	{

		switch (Bank.choice)
		{

		case 1:
			system("cls");
			std::cout << "Creating New Account" << std::endl;
			new_acc();
			break;
		case 2:
			std::cout << "Updating Information" << std::endl;
			system("cls");
			// edit();
			break;
		case 3:
			std::cout << "For transcation" << std::endl;
			system("cls");
			// transact();
			break;
		case 4:
			std::cout << "Checking details" << std::endl;
			system("cls");
			list();
			break;
		case 5:
			std::cout << "Remove existing account" << std::endl;
			system("cls");
			// erase();
			break;
		case 6:
			std::cout << "Viewing customer's list" << std::endl;
			system("cls");
			// view();
			break;
		case 7:
			std::cout << "Exiting" << std::endl;
			system("exit");
			break;
		default:
			std::cout << "Please enter a valid choice" << std::endl;
			std::cin >> Bank.choice;
			break;
		}
		system("cls");
		goto startMenu;
	}
}

/*
new_acc() – This function creates a new customer account. It asks for some  personal and banking details of the customer such as name, date of birth, citizenship number, address and phone number. You can enter the amount to deposit and choose one type of deposit account – saving, current, fixed for 1 year, fixed for 2 years or fixed for 3 years.
 */

void NewAcc::new_acc()
{
restart:
	bank Bank;
	account Ac;

	std::ofstream newacc;
	char confirm;
	newacc.open("Bankdata.txt");
	Bank.x = Bank.x + 1;

Name:
	std::cout << "Enter the name of the new customer \n";
	// getline(cin, Bank.newacc.name);
	std::cin >> Bank.newacc.name;
	if (Bank.newacc.name == "NULL")
	{
		std::cout<<"Enter a valid name\n";
		goto Name;
	}
Day:
	std::cout << "Enter the number for the Date of birth of the new customer:\n Day -- 00 - 31: ";
	std::cin >> Bank.newacc.day;
	if (Bank.newacc.day > 31 || Bank.newacc.day < 0)
	{
		std::cout << "Please enter a valid number";
		goto Day;
	}

Month:
	std::cout << "\nMonth -- 01 - 12: ";
	std::cin >> Bank.newacc.month;
	if (Bank.newacc.month > 12 || Bank.newacc.month < 0)
	{
		std::cout << "Please enter a valid number";
		goto Month;
	}

Year:
	std::cout << "\nYear -- 1930 - 2021: ";
	std::cin >> Bank.newacc.year;
	if (Bank.newacc.year > 2021 || Bank.newacc.year < 1930)
	{
		std::cout << "Please enter a valid number";
		goto Year;
	}

Citizenship:
	std::cout << "\nEnter the citizenship number of the new customer:\n";
	std::cin >> Bank.newacc.citizenship_number;
	if (Bank.newacc.citizenship_number <= 100000000000000)
	{
		std::cout << "Please enter a valid citizenship number\n";
		goto Citizenship;
	}
	// if (Bank.newacc.citizenship_number > )

	std::cout << "Enter the new customer's address\n";
	// std::getline(std::cin, Bank.newacc.address);
	std::cin >> Bank.newacc.address;
	std::cout << "Enter the new customer's phone number\n";
	std::cin >> Bank.newacc.phone_number;
	std::cout << "Enter the new customer's starting balance\n";
	std::cin >> Bank.newacc.balance;
	std::cout << "Enter the new customer's deposit type ( choose a number )\n";
	std::cout << "\t\t1.\tSavings\n\t\t2.\tCurrent\n\t\t3.\tFixed for 1 year\n\t\t4.\tFixed for 2 years\n\t\t5.\tFixed for 3 years\n";
	int choice = 0;
	std::cin >> choice;
	while (choice != 0)
	{
		if (choice == 1)
		{
			Bank.newacc.ac_type = "Savings";
			choice = 0;
		}
		else
		{
			if (choice == 2)
			{
				Bank.newacc.ac_type = "Current";
				choice = 0;
			}
			else
			{
				if (choice == 3)
				{
					Bank.newacc.ac_type = "Fixed for 1 year";
					choice = 0;
				}
				else
				{
					if (choice == 4)
					{
						Bank.newacc.ac_type = "Fixed for 2 years";
						choice = 0;
					}
					else
					{
						std::cout << "Please enter a  valid number\n";
						std::cin >> choice;
					}
				}
			}
		}
		// }
		// newacc << "Name: "; // << Bank.new;

		Bank.newacc.ac_type = choice;
	}

	// Confirmation
	std::cout << "Please confirm if the following information is correct\n";
	std::cout << "Name: " << Bank.newacc.name << std::endl;
	std::cout << "Date of Birth: dd/mm/yy" << Bank.newacc.day << "/" << Bank.newacc.month << "/" << Bank.newacc.year << std::endl;
	std::cout << "Address: " << Bank.newacc.address << std::endl;
	std::cout << "Citizenship Number" << Bank.newacc.citizenship_number << std::endl;
	std::cout << "Phone Number" << Bank.newacc.phone_number << std::endl;
	// std::cout << "Email Address" << Bank.newacc.email_address << std::endl;
	std::cout << "Account Balance" << Bank.newacc.balance << std::endl;
	std::cout << "Do you confirm the above information?(y/n)\n";
	std::cin >> confirm;
	if (confirm == 'y')
	{
		std::cout << "Compiling account information" << std::endl;
	}
	if (confirm == 'n')
	{
		std::cout << "Please re-enter the above information\n";
		system("cls");
		goto restart;
	}
	// while (newacc != 1)
	// {
	newacc /* "Name: " */ << Bank.newacc.name << std::endl;
	newacc /* "Address: " */ << Bank.newacc.address << std::endl;
	newacc /* "Date of Birth: dd/mm/yyyy \t" */ << Bank.newacc.day << "/" << Bank.newacc.month << "/" << Bank.newacc.year << std::endl;
	// std::newacc << Bank.newacc.address << std::endl;
	newacc /* "Citizenship Number: " */ << Bank.newacc.citizenship_number << std::endl;
	newacc /* "Phone Number:	 " */ << Bank.newacc.phone_number << std::endl;
	newacc /* "Balance: " */ << Bank.newacc.balance << std::endl;
	newacc /* "Account Type: " */ << Bank.newacc.ac_type << std::endl;
	newacc << endl;
	// }
	newacc.close();
}

/*
view list() – With this function, you can view the customer’s banking information such as account number, name, address and phone number provided while creating the account.
*/

void list()
{
	fstream v_acc;
	int banknum = 0;
	std::cout << "Enter the customer bank account number: ";
	std::cin >> banknum;
	v_acc.open("bankdata.txt");
	while (v_acc.is_open())
	{
		// std::cout << "File is open and in use\n";
		// system("Pause");
		if (banknum != )
		{

		}
		v_acc.close();
	}
}

/*
void viewlist()
{

} */

/*
edit() – This function has been used for changing the address and phone number of a particular customer account.
*/

/*
transact() – With this function, you can deposit and withdraw money to and from a particular customer account.
*/

/*
erase() – This function is for deleting a customer account.
*/

/*
see() – This function shows account number, name, date of birth, citizenship number, age, address, phone number, type of account, amount deposited and date of deposit. It also displays the amount of interest corresponding to a particular account type.
 */

int main()
{
	menu();
	return 0;
}