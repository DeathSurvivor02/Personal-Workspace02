#ifndef	__CSSTUDENT__H__
#define __CSSTUDENT__H__
#include "Student.h"
#include "Student.cpp"

class CSStudent : public Student
{
private:
	double Laptop_fee;
public:
	void setlaptop_fee();
	double getLaptop_fee();
	double calculateTotalFees();
	CSStudent();
};


#endif // !

