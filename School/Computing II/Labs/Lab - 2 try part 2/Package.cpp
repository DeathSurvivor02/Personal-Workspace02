#include <iostream>
#include <string>
#include "Package.h"

using namespace std;
void Package::setName()
{
	string name;
	std::cout << "Please enter your name:\t";
	std::getline(std::cin, name);
	Name = name;
}

void Package::setAddress()
{
	string address;
	std::cout << "Please enter your address:\t";
	std::getline(std::cin, address);
	Address = address;
}

void Package::setCity()
{
	string city;
	std::cout << "Please enter your city:\t";
	std::getline(std::cin, city);
	City = city;
}

void Package::setState()
{
	string state;
	std::cout << "Please enter the state:\t ";
	std::getline(std::cin, state);
	State = state;
}

void Package::setZip_code_receiver()
{
	string zip_code_receiver;
	std::cout << "Please enter the zip code of the receiver ";
	std::getline(std::cin, zip_code_receiver);
	Zip_code_receiver = zip_code_receiver;
}

void Package::setZip_code_sender()
{
	string zip_code_sender;
	std::cout << "Please enter the zip code of the sender ";
	std::getline(std::cin, zip_code_sender);
	Zip_code_sender = zip_code_sender;
}

void Package::setWeight()
{
	double weight;
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

void Package::setCost_per_ounce()
{
	double cost_per_ounce;
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

double Package::calculateCost()
{
	double calculatedcost;
	calculatedcost = Weight * Cost_per_ounce;
	return calculatedcost;
}

Package::Package()
{
	setName();
	setState();
	setCity();
	setAddress();
	setZip_code_sender();
	setZip_code_receiver();
	setWeight();
	setCost_per_ounce();
}

//int main()
//{
//	double cost = 0;
//	Package class_package;
//	// Package();
//
//	cost = class_package.calculateCost();
//	cout << cost;
//	return 0;
//}