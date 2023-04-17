#ifndef __SOURCE__H__ 
#define __SOURCE__H__

//#include <iostream>
#include <string>

class Student
{
private:
	std::string Name;
	int ID_number;
	void setName();
	void setID_number();
	void setYears();
	void setFees();
	std::string getName();
	int getID_number();
	int getYears();
	double getFees();

public:
	int Years;
	double Fees;
	Student();
	double calculateTotalFees();
};



#endif // !

