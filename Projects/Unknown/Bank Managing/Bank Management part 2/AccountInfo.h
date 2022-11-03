#ifndef __ACCOUNTINFO__H
#define __ACCOUNTINFO__H
#include <iostream>
#include <string>
#include <fstream>
// #include "Account.h"
using namespace std;
class Account
{
	int Age;
	std::string Name;

	int Day;
	int Month;
	int Year;

	int Home_number;
	int Cell_number;

	std::string Address_1;
	std::string Address_2;
	std::string Address_3;
	void setName(std::string name);

	void setAge(int age);

	void setDay(int day);
	void setMonth(int month);
	void setYear(int year);

	void setZipcode(int zipcode);

	void setcell_number(int cell_number);
	void sethome_number(int home_number);

	void setAddress_1(std::string address_1);
	void setAddress_2(std::string address_2);
	void setAddress_3(std::string address_3);

	// return functions
	
public:
int getAge();
int getDay();
int getMonth();
int getYear();
int getHome_number();
int getCell_number();
std::string getName();
std::string getAddress_1();
std::string getAddress_2();
std::string getAddress_3();
Account();
};

#endif
