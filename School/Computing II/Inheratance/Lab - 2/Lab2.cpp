#include <iostream>
#include <string>
#include "Package.h"
// #include ""
using namespace std;

class TwoDayPackage : public Package
{
private:
	double Flat_fee;
	calculateCostTwoDay();
public:
	TwoDayPackage();

};
void TwoDayPackage::TwoDayPackage(double flat_fee)
{
	std::cout << "Enter the two day fee: " << std::endl;
	std::cin >> flat_fee;
	Flat_fee = flat_fee;
	calculateCostTwoDay():calculateCost()
	{
		double cost;
		cost = (Cost_per_ounce* Weight) + Flat_fee;
		return cost;
	}
}
class OvernightsPackage : public Package
{
};
int main()
{
	
}