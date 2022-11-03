
#ifndef __OVERNIGHTPACKAGE__H__
#define __OVERNIGHTPACKAGE__H__
#include <iostream>
#include <string>
#include "Package.h"



class OvernightPackage : public Package
{
private:
	double overnight_delivery_fee;
public:

	OvernightPackage(string sender_n, string sender_addr, string sender_c,
		string sender_s, string sender_Z, string recipient_n, string recipient_addr,
		string recipient_c, string recipient_s, string recipient_Z, double wei,
		double cost, double delivery_fee);

	double calculateCost();
	double getovernight_delivery_fee();
	void setovernight_delivery_fee(double delivery_fee);

};
#endif
