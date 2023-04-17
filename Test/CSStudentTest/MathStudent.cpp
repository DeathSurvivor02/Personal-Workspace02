#include "MathStudent.h"
#include "Student.h"
#include <iostream>

void MathStudent::setfees()
{
	double fee;
	std::cout << "Please enter the cost of the tutotiral fee" << std::endl;
	std::cin >> fee;
	tutorial_fee = fee;
}
double MathStudent::getfees()
{
	return tutorial_fee;
}
MathStudent::MathStudent():Student::Student()
{
	setfees();
	MathStudent::calculateTotalFees();
}
double MathStudent::calculateTotalFees()
{
	return Years * (Fees + tutorial_fee);

}
