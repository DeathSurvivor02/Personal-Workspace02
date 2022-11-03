#include <iostream>
#include <string>
#include "Package.h"

using namespace std;
// senders
void Package::setFname_sender(string fname_sender)
{
	std::cout << "Please enter the first  name of the sender:\t";
	std::cin >> fname_sender;
	Fname_sender = fname_sender;
}
void Package::setLname_sender(string lname_sender)
{
	std::cout << "Please enter the last name of the sender:\t";
	std::cin >> lname_sender;
	Lname_sender = lname_sender;
}
void Package::setAddress_sender(string address_sender)
{
	std::cout << "Please enter the last name of the sender:\t";
	std::cin >> address_sender;
	Address_sender = address_sender;
}
void Package::setCity_sender(string city_sender)
{
	std::cout << "Please enter the city of the sender:\t";
	std::cin >> city_sender;
	City_sender = city_sender;
}
void Package::setState_sender(string state_sender)
{
	std::cout << "Please enter the state of the sender:\t";
	std::cin >> state_sender;
	State_sender = state_sender;
}
void Package::setZip_sender(string zip_sender)
{
	std::cout << "Please enter the Zip code of the sender:\t";
	std::cin >> zip_sender;
	Zip_sender = zip_sender;
}

// recipient
void Package::setFname_recipient(string fname_recipient)
{
	std::cout << "Please enter the first  name of the recipient:\t";
	std::cin >> fname_recipient;
	Fname_recipient = fname_recipient;
}
void Package::setLname_recipient(string lname_recipient)
{
	std::cout << "Please enter the last name of the recipient:\t";
	std::cin >> lname_recipient;
	Lname_recipient = lname_recipient;
}
void Package::setAddress_recipient(string address_recipient)
{
	std::cout << "Please enter the last name of the recipient:\t";
	std::cin >> address_recipient;
	Address_recipient = address_recipient;
}
void Package::setCity_recipient(string city_recipient)
{
	std::cout << "Please enter the city of the recipient:\t";
	std::cin >> city_recipient;
	City_recipient = city_recipient;
}
void Package::setState_recipient(string state_recipient)
{
	std::cout << "Please enter the state of the recipient:\t";
	std::cin >> state_recipient;
	State_recipient = state_recipient;
}
void Package::setZip_recipient(string zip_recipient)
{
	std::cout << "Please enter the Zip code of the recipient:\t";
	std::cin >> zip_recipient;
	Zip_recipient = zip_recipient;
}

// money

void Package::setWeight(double weight)
{
	std::cout << "Please enter the weight of package:\t";
WEIGHT:
	std::cin >> weight;
	std::cout << endl;
	if (weight <= 0)
	{
		std::cout << "Please enter a value lager than 0\n";
		goto WEIGHT;
	}
	Weight = weight;
}
void Package::setCost_per_ounce(double cost_per_ounce)
{
	std::cout << "Please enter the cost per ounce of the package\t";
OUNCE:
	std::cin >> cost_per_ounce;
	std::cout << endl;
	if (cost_per_ounce <= 0)
	{
		std::cout << "Please enter a value larger than 0\n";
		goto OUNCE;
	}
	Cost_per_ounce = cost_per_ounce;
}

Package::Package(const string &fname_sender, const string &lname_sender, const string &address_sender, const string &city_sender, const string &state_sender, const string &zip_sender, const string &fname_recipient, const string &lname_recipient, const string &address_recipient, const string &city_recipient, const string &state_recipient, const string &zip_recipient, double weight, double cost_per_ounce)
{
	setFname_sender(const string& fname_sender);
	setLname_sender(const string& lname_sender);
	setState_sender(const string& state_sender);
	setCity_sender(const string& city_sender);
	setAddress_sender(const string& address_sender);
	setZip_sender(const string& zip_sender);
	setFname_recipient(const string& fname_recipient);
	setLname_recipient(const string& lname_recipient);
	setState_recipient(const string& state_recipient);
	setCity_recipient(const string& city_recipient);
	setAddress_recipient(const string& address_recipient);
	setZip_recipient(const string& zip_recipient);
}


int main()
{
	Package package;
	return 0;
}