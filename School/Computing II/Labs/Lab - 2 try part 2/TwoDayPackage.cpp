#include <iostream>
#include <string>
#include "Package.cpp"
#include "TwoDayPackage.h"

using namespace std;

void TwoDayPackage::setFlatfee()
{
	double flatfee;
	std::cout << "Enter the flat fee for the two day shipping:\t";
	std::cin >> flatfee;
	Flatfee = flatfee;
}

double TwoDayPackage::calculateCost()
{
	double cost;
	cost = (Weight * Cost_per_ounce) + Flatfee;
	std::cout << cost << std::endl;
	return cost;
}

TwoDayPackage::TwoDayPackage()
{
	Package package;
	TwoDayPackage::calculateCost();
}

int main()
{

	TwoDayPackage twoday;
	return 0;
}