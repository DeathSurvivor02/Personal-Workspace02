#ifndef __PACKAGE__H__
#define __PACKAGE__H__

#include <iostream>
#include <string>

using namespace std;
class Package
{
public:
	Package(); //constructor
	string Address_receiver;
	string Address_sender;
	string Name_receiver;
	string Name_sender;
	string City_receiver;
	string City_sender;
	string State_receiver;
	string State_sender;
	string Zip_code_sender;
	string Zip_code_receiver;
	double Weight;
	double Cost_per_ounce;

// private:
	void setAddress();
	void setName();
	void setCity();
	void setState();
	void setZip_code_sender();
	void setZip_code_receiver();
	void setWeight();
	void setCost_per_ounce();
	double calculateCost();

// protected:
};


#endif