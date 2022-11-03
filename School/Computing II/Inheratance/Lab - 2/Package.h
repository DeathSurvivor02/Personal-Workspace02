#ifndef __PACKAGE__H__
#define __PACKAGE__H__

#include <iostream>
#include <string>

using namespace std;

class Package
{
public:
	double calculateCost();

protected:
	string Name;
	string Address;
	string City;
	string State;
	unsigned long ZIP_code_sender;
	unsigned long ZIP_code_recipient;
	double Weight;
	double Cost_per_ounce;
	Package(string name, string address, string city,string state, unsigned long zip_code_sender, unsigned zip_code_recipient, double weight, double cost_per_ounce)
	{
		std::cout << "Enter the name for the receiver: " << std::endl;
		std::getline(std::cin, name);
		Name = name;
		std::cout << "Enter the address for the receiver: " << std::endl;
		std::getline(std::cin, address);
		Address = address;
		std::cout << "Enter the City of the receiver: " << std::endl;
		std::getline(std::cin, city);
		City = city;
		std::cout << "Enter the State of the receiver: " << std::endl;
		std::getline(std::cin, state);
		State = state;
		std::cout << "Enter the Zip Code of the receiver: " << std::endl;
		std::cin >> zip_code_recipient;
		ZIP_code_recipient = zip_code_recipient;
		std::cout << "Enter the Zip Code of the seneder: " << std::endl;
		std::cin >> zip_code_sender;
		ZIP_code_sender = zip_code_sender;

		std::cout << "Enter the Weight of the package: " << std::endl;
	WEIGHT:
		std::cin >> weight;
		if (weight < 0)
		{
			std::cout << "Enter a positive value: " << std::endl;
			goto WEIGHT;
		}
		Weight = weight;

		std::cout << "Enter the cost per ounce of the package: " << std::endl;
	OUNCE:
		std::cin >> cost_per_ounce;
		if (cost_per_ounce < 0)
		{
			std::cout << "Enter a positive value: " << std::endl;
			goto OUNCE;
		}
		Cost_per_ounce = cost_per_ounce;
	};
};

double Package::calculateCost()
{
	double cost;
	cost = Cost_per_ounce * Weight;
	return cost;
}


#endif