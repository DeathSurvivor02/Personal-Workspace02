#ifndef __MATHSTUDENT__H__
#define __MATHSTUDENT__H__
#include "Student.h"

class MathStudent : public Student
{
private:
	double tutorial_fee;
	double getfees();
	void setfees();
public:
	double calculateTotalFees();
	MathStudent();
};

#endif // !__MATHSTUDENT__H__
