#include <iostream>
#include <string>
// #include "Account.h"
#include "AccountInfo.h"




void Account::setName(std::string Name)
{	
	std::string name;
	std::cout << "Please enter your name: ";
	std::cin >> name;
	Name = name;
}
void Account::setAge(int Age)
{
	int age;
	std::cout << "Please enter your age: ";
	std::cin >> age;
	Age = age;
}
void Account::setDay(int Day)
{
	int day;
	std::cout << "Please enter your day: ";
	std::cin >> day;
	Day = day;
}
void Account::setYear(int Year)
{
	int year;
	std::cout << "Please enter your year: ";
	std::cin >> year;
	Year = year;
}

void Account::setHome_number(Home_number)
{
	int home_number;
	std::cout << "Please enter your home number: ";
	std::cin >> home_number;
	Home_number = home_number;
}
void Account::setCell_number(Cell_number)
{
	std::cout << "Please enter your cell number: ";
	std::cin >> cell_number;
	Cell_number = cell_number;
}
void Account::setAddress_1(std::string Address_1)
{
	std::string address_1;
	std::cout << "Please enter your address 1: ";
	std::cin >> address_1;
	Address_1 = address_1;
}
void Account::setAddress_2(std::string Address_2)
{
	std::string address_2;
	std::cout << "Please enter your address 2: ";
	std::cin >> address_2;
	Address_2 = address_2;
}
void Account::setAddress_3(std::string Address_3)
{
	std::string address_3;
	std::cout << "Please enter your address 3: ";
	std::cin >> address_3;
	Address_3 = address_3;
}

int Account::getAge()
{
	return Age;
}
int Account::getDay()
{
	return Day;
}
int Account::getMonth()
{
	return Month;
}
int Account::getYear()
{
	return Year;
}
int Account::getHome_number()
{
	return Home_number;
}
int Account::getCell_number()
{
	return Cell_number;
}
std::string Account::getName()
{
	return Name;
}
std::string Account::getAddress_1()
{
	return Address_1;
}
std::string Account::getAddress_2()
{
	return Address_2;
}
std::string Account::getAddress_3()
{
	return Address_3;
}


Account::Account()
{
	setName(std::string Name);
	setAge(Age);
	setDay(Day);
	setMonth(Month);
	setYear(Year);
	setHome_number(Home_number);
	setCell_number(Cell_number);
	setAddress_1(Address_1);
	setAddress_2(Address_2);
	setAddress_3(Address_3);
	setAge(Age);
}