#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Account
{
private:
	struct account_info
	{

		int Age;
		string Name; // todo check for this... doesn't seem right  //fixme possibly wrong

		// DOB
		int Day = 0;
		int Month = 0;
		int Year = 0;

		// Citizenship Number
		char Cit_num[17]; // todo check to see if the works...unknown result pending

		// addresses
		string Address_1;
		string Address_2;
		string Address_3;

		// phone numbers
		long int Cell_number = 0;
		long int Home_number = 0;

		// account type
		string account_type;
	} account_info infoaccount;
};

class Account_function : public Account
{
	void setAge(int age) { Age = age; }
	void setName(int name) { Name = name; }

	void setDay(int day) { Day = day; }
	void setMonth(int month) { Month = month; }
	void setYear(int year) { Year = year; }

	void setCit_num(int cit_num) { COP_NUM = cit_num; }

	void setHome_number(int home_number) { Home_number = home_number; }
	void setCell_number(int cell_number) { Cell_number = cell_number; }

	void setAddress_1(string address_1) { Address_1 = address_1; }
	void setAddress_2(string address_2) { Address_2 = address_2; }
	void setAddress_3(string address_3) { Address_3 = address_3; }

	void setAccount_type(string account_info) { Account_info = account_info; }

	int getAge() { return age; }
	string getName() { return name; }

	int getDay() { return day; }
	int getMonth() { return month; }
	int getYear() { return year; }

	int getCit_num() { return cit_num; }

	int getHome_number() { return home_number; }
	int getCell_number() { return cell_number; }

	string getAddress_1(){return string Address_1} string getAddress_2(){return string Address_2} string getAddress_3(){return string Address_3}

	string getAccount_type()
	{
		return Account_info;
	}
}

/* void Account_function::menu()
{
} */
main()
{

	return 0;
}