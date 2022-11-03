#ifndef __TWODAYPACKAGE__H__
#define __TWODAYPACKAGE__H__

#include <iostream>
#include <string>
#include "Package.h"

class TwoDayPackage : public Package
{
public:
	// private:
	double Flatfee;
	void setFlatfee();
	double calculateCost(double weight, double costperounce);
	TwoDayPackage(double Weight, double cost_per_ounce);
};

#endif // end define