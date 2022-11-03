#ifndef __PACKAGE__H__
#define __PACKAGE__H__

#include <string>
#include <iostream>
using namespace std;
class Package
{
public:
	void setFname_sender(const std::string);
	void setLname_sender(const std::string);
	void setAddress_sender(const std::string);
	void setCity_sender(const std::string);
	void setState_sender(const std::string);
	void setZip_sender(const std::string);

	void setFname_recipient(const std::string);
	void setLname_recipient(const std::string);
	void setAddress_recipient(const std::string);
	void setCity_recipient(const std::string);
	void setState_recipient(const std::string);
	void setZip_recipient(const std::string);

	std::string getFname_sender() const;
	std::string getLname_sender() const;
	std::string getAddress_sender() const;
	std::string getCity_sender() const;
	std::string getState_sender() const;
	std::string getZip_sender() const;

	std::string getFname_recipient() const;
	std::string getLname_recipient() const;
	std::string getAddress_recipient() const;
	std::string getCity_recipient() const;
	std::string getState_recipient() const;
	std::string getZip_recipient() const;

	void setWeight(double);
	double getWeight()const;
	void setCost_per_ounce(double);
	Package(const std::string, const std::string, const std::string, const std::string, const std::string, const std::string, const std::string, const std::string, const std::string, const std::string, const std::string, const std::string, double = 0.0, double = 0.0);

protected:
	std::string Fname_sender;
	std::string Lname_sender;
	std::string Address_sender;
	std::string City_sender;
	std::string State_sender;
	std::string Zip_sender;

	std::string Fname_recipient;
	std::string Lname_recipient;
	std::string Address_recipient;
	std::string City_recipient;
	std::string State_recipient;
	std::string Zip_recipient;

	double Weight;
	double Cost_per_ounce;
};

#endif